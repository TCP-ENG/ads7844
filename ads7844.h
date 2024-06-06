#ifndef _ADS7844_H_
#define _ADS7844_H_

#include "Arduino.h"

enum pMode{
    powerDown = 0x00,
    always_On = 0x03
};

#define  single  0x01
#define  diff    0x00


typedef union _control_Byte
{
    uint8_t d8;
    struct
    {
        uint8_t power_down:2;
        uint8_t s_dMode:1;
        uint8_t not_used:1;
        uint8_t address:3;
        uint8_t start:1;
    }control_Byte;
    
};

typedef union _ads7844_data_t_
{
    uint16_t d16;
    struct
    {
        uint8_t not_used  : 3;
        uint16_t data     : 12;
        uint8_t start     : 1;
    }ads7844_data_t;
    
};

class ADS7844
{
    private:
        pMode power_mode = powerDown;
        uint8_t csPin;
        uint8_t S_DMode;
        uint8_t chanMap[8] = {
            0,
            4,
            1,
            5,
            2,
            6,
            3,
            7
        };
        
    public:
        void set_pMode(pMode mode);
        pMode get_pMode(void);
        void set_csPin(uint8_t cspin);
        uint16_t read_CH(uint8_t chan);
        uint16_t read_CHm(uint8_t chan);
        int readALL(uint16_t *data); 
        ADS7844(uint8_t csp);
        ~ADS7844();
};


#endif