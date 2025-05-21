

#ifndef shiniGPS_h
#define shiniGPS_h

#include <TinyGPS++.h>
#include <shiniConfig.h>
#include <shiniGPS.h>


class shiniGPS{
private:
TinyGPSPlus gps;
uint8_t day,month,year;
uint8_t hour,minute,second,cycle,lastSecond;
double lat,lng,speedKPH,speedMPH,altitude;
float hdop;
uint8_t sats;
uint16_t course;
uint32_t centisecond;
public:

void begin();
void read();
};

#endif


