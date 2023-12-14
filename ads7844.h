#ifndef _ADS7844_H_
#define _ADS7844_H_

#include "Arduino.h"

typedef union 
{
    uint8_t d8;
    struct
    {
        uint8_t strat:1;
        uint8_t address:3;
        uint8_t not_used:1;
        uint8_t single:1;
        uint8_t power-down:2;
    }control_Byte;
    
};


typedef union
{
    uint16_t d16;
    struct
    {
        uint16_t data:11;
        uint16_t not_used:5;
    }ads7844_data;
    
};
enum pMode{
    powerDown = 0x00;
    always_On = 0x03;
};
class ADS7844
{
private:
    pMode power_mode = 0;
public:
    void set_pMode(pMode mode);
    pMode get_pMode(void);
    ads7844_data read_CH(uint8_t chan);
    int readALL(*ads7844_data data); 
    ADS7844(/* args */);
    ~ADS7844();
};

ADS7844::ADS7844(/* args */)
{
}

ADS7844::~ADS7844()
{
}

#endif