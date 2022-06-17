#include <Servo.h> 
#define MOTORXL 10
#define MOTORXR 9
#define MOTORYL 5
#define MOTORYR 6

class Drivers {

public:
void Calibracion();
double MOTORESX(double XL, double XR);
double MOTORESY(double YL, double YR);
//void Prueba();
Servo ESCXL, ESCXR, ESCYL, ESCYR;

private:
int pwmlow = 30;
int pwmhigh = 160;
//int val;
  
};

void Drivers::Calibracion(){
  
ESCXL.attach(MOTORXL);

ESCXL.write(pwmhigh); 
delay(2500);
ESCXL.write(pwmlow); 
delay(2500); 

ESCXR.attach(MOTORXR);

ESCXR.write(pwmhigh); 
delay(2500);
ESCXR.write(pwmlow); 
delay(2500); 

ESCYL.attach(MOTORYL);

ESCYL.write(pwmhigh); 
delay(2500);
ESCYL.write(pwmlow); 
delay(2500); 

ESCYR.attach(MOTORYR);

ESCYR.write(pwmhigh); 
delay(2500);
ESCYR.write(pwmlow); 
delay(3500); 
 
}

double Drivers::MOTORESX(double XL, double XR){
 
  ESCXL.write(XL); ESCXR.write(XR);
  
}

double Drivers::MOTORESY(double YL, double YR){
 
  ESCYL.write(YL); ESCYR.write(YR);
  
}


/*void Drivers::Prueba(){
  
  if ( Serial.available() != 0){
    val = Serial.parseInt();  
  delay(15);                   
  }
  ESCXL.write(val);  
  ESCXR.write(val);     
  ESCYL.write(val);
  ESCYR.write(val); 
}*/

Drivers M;

