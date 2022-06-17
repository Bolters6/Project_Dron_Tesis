
//#include <avr/dtostrf.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(2,3); //rx,tx
#define batterypin A3
#define ledconnect 4


/*int V1;
int V2;
int V3;*/
int velocidad;
char buffer[15];
char STATUS = 'd';
//int x,y,z,temp,presion,altitud;

void setup() {
  
Alarma.setupPIRAlarm();
   BT.begin(9600);
   pinMode(ledconnect, OUTPUT);
  Serial.begin(9600);
  GPS.SetupGPS();
//  BlueT.SetupBT();
 GYRO.Iniciotransmision();
 Compass.SetupMag();
 BAROPressure.SetupBaro();
  //Ultra.SetupUS();
 // CONTROL.configuracionX();
  //CONTROL.configuracionY();
  //CONTROL.configuracionT();
  /*Serial.println("calibrando...");
  delay(3000);
  M.Calibracion();
  delay(1000);
  Serial.println("calibrado");*/
  //randomSeed(50);
while ( STATUS == 'd'){
  BT.listen();
 if ( BT.available()){
  STATUS = BT.read();
 }

 if (STATUS == 'c' ){
  digitalWrite(ledconnect, HIGH);
 }

  
}

}

void loop() {
  

int lecturacarga = analogRead(batterypin);
int porcentajecarga = (lecturacarga ) / 7.35;
  
  

 

  
 GPS.LecturaGPS();
  velocidad = GPS.Speed();
int latdec = (GPS.Locationlat() * 1000);
float londec = GPS.Locationlong();
char loncar = "";
dtostrf(londec, 8, 3, loncar);
int distance = GPS.DistanceCourse();

/*Serial.println(longitud);
Serial.print(latitud);
Serial.println("vel");
Serial.println(velocidad);*/
  /*BAROPressure.PTA();
  int temp = BAROPressure.GetTemperature();
 int presion = BAROPressure.GetPresion();
 int altitud = BAROPressure.GetAltitude();
 val = digitalRead(PIRPin);
 sprintf(buffer, "%d,%d,%d",temp,presion,altitud);
BlueT.SendBytes(buffer);
Serial.println(buffer);
delay(500);*/
  
//while ( STATUS == 'c' ) {

GYRO.LecturaGyro();
int x = GYRO.GetAngleX() + 45;
int y = (GYRO.GetAngleY() * (-1)) + 45;
 
 Compass.Brujula();
 int z = Compass.LecturaZ();

 
int vacio1 = 0, vacio2 = 0;
 
  BAROPressure.PTA();
 int temp = BAROPressure.GetTemperature();
 int presion = BAROPressure.GetPresion();
 //BAROPressure.GetAltitude();
int altitud = BAROPressure.GetAltitude() * 100;

int val = Alarma.PIRAlarm();
/*V1 = random(30,80);
 V2 = random(20,30); 
 V3 = random(80,100);
sprintf(buffer, "%d,%d,%d",V1,V2,V3);
BT.println(buffer);*/
 sprintf(buffer,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%s,%d,%d,%d",vacio1,temp,presion,altitud,z,x,y,velocidad,porcentajecarga,val,loncar,latdec,distance,vacio2);
BT.println(buffer);
//Serial.println(buffer);

/*BT.print(temp);
BT.print(",");
BT.print(presion);
BT.print(",");
BT.print(altitud);
BT.print(",");
BT.println(z);*/
 /* BT.listen();
  while ( BT.available() > 0){
  STATUS = BT.read();
 }

 if (STATUS == 'd' ){
  digitalWrite(ledconnect, LOW);
 }
 if (STATUS == 'c' ){
  digitalWrite(ledconnect, HIGH);
 }*/
 
 
//Serial.println(buffer);
//Serial.println(altitud);
//Serial.println(BAROPressure.GetAltitude());
  /*GYRO.LecturaGyro();
  Serial.println( GYRO.GetOMEGAY());
/*Compass.Brujula();
Serial.println(Compass.LecturaSpeedZ());*/

delay(2);
 
}

 //Compass.Brujula();
  //CONTROL.computeT();
//}





