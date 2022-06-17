#include "TinyGPS++.h"
 #include <SoftwareSerial.h>
   SoftwareSerial SerialGps(8,7);

class GPSplus{
  
   private:
 double courseToHome;

   public:
  TinyGPSPlus GPS;
 void SetupGPS();
   void LecturaGPS();
  double Locationlat();
    double Locationlong();
   double Speed();
   double DistanceCourse();
   const char CardinalCourse();
};

 void GPSplus::SetupGPS(){

SerialGps.begin(9600);
  
}

void GPSplus::LecturaGPS(){
  SerialGps.listen();
  while (SerialGps.available() > 0){
  GPS.encode(SerialGps.read()); }
  delay(5);
 
}
double GPSplus::Locationlat(){
  
  if (GPS.location.isValid()){

   /* Serial.print(F(" Lat="));
    Serial.print(GPS.location.lat(), 6);
    Serial.print(F(" Long="));
    Serial.println(GPS.location.lng(), 6);*/
    return(GPS.location.lat());
   
      
  if (GPS.location.isUpdated())
  {
    /*Serial.print(F(" Lat="));
    Serial.print(GPS.location.lat(), 6);
    Serial.print(F(" Long="));
    Serial.println(GPS.location.lng(), 6);*/
    return(GPS.location.lat());
    
  }
}
}
double GPSplus::Locationlong(){
  
  if (GPS.location.isValid()){

   /* Serial.print(F(" Lat="));
    Serial.print(GPS.location.lat(), 6);
    Serial.print(F(" Long="));
    Serial.println(GPS.location.lng(), 6);*/
   
    return(GPS.location.lng());
      
  if (GPS.location.isUpdated())
  {
    /*Serial.print(F(" Lat="));
    Serial.print(GPS.location.lat(), 6);
    Serial.print(F(" Long="));
    Serial.println(GPS.location.lng(), 6);*/
   
    return(GPS.location.lng());
  }
}
}
double GPSplus::Speed(){
  
  if (GPS.speed.isValid()){
    
    /*Serial.print(F(" m/s="));
    Serial.print(GPS.speed.mps());
    Serial.print(F(" km/h="));
    Serial.println(GPS.speed.kmph());*/
    //return(GPS.speed.kmph());
   return(GPS.speed.mps());
    
  if (GPS.speed.isUpdated())
  {
      /*Serial.print(F(" m/s="));
    Serial.print(GPS.speed.mps());
    Serial.print(F(" km/h="));
    Serial.println(GPS.speed.kmph());*/
    //return(GPS.speed.kmph());
    return(GPS.speed.mps());
  }
  }
}
  
double GPSplus::DistanceCourse(){
  
  if (GPS.location.isValid())
    {
      static const double HOME_LAT = 10.211090, HOME_LON = -67.993929;
      double distanceToHome =
        TinyGPSPlus::distanceBetween(
          GPS.location.lat(),
          GPS.location.lng(),
          HOME_LAT, 
          HOME_LON);
       courseToHome =
        TinyGPSPlus::courseTo(
          GPS.location.lat(),
          GPS.location.lng(),
          HOME_LAT, 
          HOME_LON);

      /*Serial.print(F("HOME     Distance="));
      Serial.print(distanceToHome/1000, 6);
      Serial.print(F(" km Course-to="));
      Serial.print(courseToHome, 6);
      Serial.print(F(" degrees ["));
      Serial.print(TinyGPSPlus::cardinal(courseToHome));
      Serial.println(F("]"));*/
      return(distanceToHome/1000);
      
      
    }
}
const char GPSplus::CardinalCourse(){
return(TinyGPSPlus::cardinal(courseToHome));
}
GPSplus GPS;
