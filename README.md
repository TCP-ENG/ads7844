# ADS7844
This is a library for reading from an ADS7844 ADC

## Basic Usage

```c++
#include "ads7844.h"

//Setup Using Chip select pin
uint8_t cs = 10; //Chip select pin
ADS7844 ads7844(cs);

//Read from one channel
uint16_t value = ads7844.read_CH(0);

//Read from all channels
uint16_t values[8];
ads7844.readALL(data);

