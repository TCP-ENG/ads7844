#include "Arduino.h"
#include "ads7844.h"
#include "SPI.h"


ADS7844::ADS7844(uint8_t csp)
{
    csPin = csp;
    SPI.begin();
    pinMode(csPin,OUTPUT);
    digitalWrite(csPin,HIGH);
    
}
ADS7844::~ADS7844()
{
}

void ADS7844::set_pMode(pMode mode)
{
    power_mode = mode;
}

pMode ADS7844::get_pMode(void)
{
    return power_mode;
}

void ADS7844::set_csPin(uint8_t cspin)
{
    csPin = cspin;
    S_DMode = single;
}


uint16_t ADS7844::read_CH(uint8_t chan)
{
    SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
    _control_Byte cByte;
    _ads7844_data_t_ aData;
    cByte.control_Byte.start = 1;
    cByte.control_Byte.s_dMode = single;
    cByte.control_Byte.not_used = 1;
    cByte.control_Byte.power_down = powerDown;
    cByte.control_Byte.address = chanMap[chan];
    //Serial.printf("cByte Pin : %x\r\n", cByte.d8);
    digitalWrite(csPin, LOW);
    //
    SPI.transfer(cByte.d8);
    
    aData.d16 = SPI.transfer16(0x0000);
    digitalWrite(csPin,HIGH);
    SPI.endTransaction();
    return aData.ads7844_data_t.data;
}

int ADS7844::readALL(uint16_t *data)
{
    int count = 0;
    for(count=0; count < 8; count++)
    {
        data[count] = read_CH(count);
    }
    digitalWrite(csPin,HIGH);
    SPI.endTransaction();
    return 0;
}