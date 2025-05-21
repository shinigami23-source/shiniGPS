
#include <shiniGPS.h>
void  shiniGPS::begin(){
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  delay(500);
#ifdef DEBUG
  Serial.println("GPS started.. ...");
#endif

}

void shiniGPS::read(){

     uint32_t start = millis();

    while (millis() - start < 1000) {
      while (Serial2.available() > 0) {
        gps.encode(Serial2.read());
      }

    }
      
      if (gps.location.isUpdated()) {


        // timeDoc["c"] = gps.time.centisecond(); //compiles but retyrns false.. so prolly not complete

        lat = gps.location.lat();
        lng = gps.location.lng();

#ifdef DEBUG
Serial.print("lat: ");
Serial.print(lat);
Serial.print(", lng: ");
Serial.println(lng);
#endif

      }

  else if (gps.date.isUpdated())
  {
    

   year = gps.date.year();
    
   month = gps.date.month();
   
   day = gps.date.day();
   #ifdef DEBUG
Serial.print("date: ");
Serial.print(day);
Serial.print(":");
Serial.print(month);
Serial.print(":");
Serial.println(year);


#endif
  }

  else if (gps.time.isUpdated())
  {
    
   hour = gps.time.hour();
    
  minute =  gps.time.minute();
   second = gps.time.second();
    
  centisecond  = gps.time.centisecond();

     #ifdef DEBUG
Serial.print("time: ");
Serial.print(hour);
Serial.print(":");
Serial.print(minute);
Serial.print(":");
Serial.print(second);
Serial.print(":");
Serial.println(centisecond);

#endif
/*
          //centiseconds doesn't work on esp32 this is a workaround
            if(second == lastSecond){
                cycle += 1;
            }
            else{
                cycle = 0;
            }
      */      
  }


  else if (gps.speed.isUpdated())
  {
       speedKPH = gps.speed.kmph();
       speedMPH = gps.speed.mph();
       #ifdef DEBUG
        Serial.print("mph:");
        Serial.print(speedMPH);
        Serial.print(", kph:");
        Serial.println(speedKPH);         
        #endif
  }

  else if (gps.course.isUpdated())
  {
     course = gps.course.deg();
        #ifdef DEBUG
        Serial.print("course:");
        Serial.println(course);        
        #endif
  }

  else if (gps.altitude.isUpdated())
  {
    altitude = gps.altitude.meters();
        #ifdef DEBUG
        Serial.print("altitude:");
        Serial.println(altitude);        
        #endif
  }

  else if (gps.satellites.isUpdated())
  {
    sats = gps.satellites.value();
        #ifdef DEBUG
        Serial.print("sats:");
        Serial.println(sats);        
        #endif
  }

  else if (gps.hdop.isUpdated())
  {

        hdop = gps.hdop.value() / 100.0;

        #ifdef DEBUG
        Serial.print("hdop:");
        Serial.println(hdop);        
        #endif

  }



}
