#include "HMC5883L.h"


 class Magnetometro{
  
  private:
  
 int16_t mx, my, mz;
  const float declinacion = 11.45;
  long tiempo_prev;
    float anguloprev, ang_z_prev, ang_z, ang_n_z;
       float angulo, anguloN;
        float Zspeed;
  
  public: 
HMC5883L compass;
  void SetupMag();
  void Brujula();
  float LecturaZ();
  float LecturaZN();
  float LecturaSpeedZ();
  
 };
 

void Magnetometro::SetupMag()
{
  

    Wire.begin();
    compass.initialize();
 
}
 
void Magnetometro::Brujula()
{
  
double dt = (millis() - tiempo_prev) / 1000.0;
   tiempo_prev = millis();
   //Obtenemos del magnetómetro las componentes del campo magnético
    compass.getHeading(&mx, &my, &mz);
    
    GYRO.LecturaGyro();
    
    Zspeed = gz / 131;
    //Calculamos el ángulo del eje X con respecto al norte
    angulo = atan2(my, mx);
    angulo=angulo*(180/M_PI);//convertimos de Radianes a grados
    angulo=angulo-declinacion; //corregimos la declinación magnética
    //Mostramos el angulo entre el eje X y el Norte*/
  //  Serial.print("AnguloX-N: ");
    //Serial.print(angulo,0);
    float accel_ang_z = atan(sqrt(pow(ax, 2) + pow(ay, 2)) / az)*(180.0 / 3.14);
    
     ang_z = (ang_z_prev + (gz / 131)*dt);
      ang_z_prev = ang_z;
      
      ang_n_z = 0.999*ang_z + 0.0005*accel_ang_z * 0.0005 * angulo;
   
  
    //calculamos el ángulo equivalente de [-180 180] a [0 360]
    if(ang_n_z<0) anguloN=ang_n_z+360;
    //Serial.print("\tN");
    //Serial.println(angulo,0); 
delay(5);
  
}
float Magnetometro::LecturaZ(){
  return(ang_n_z);
  
} 
float Magnetometro::LecturaZN(){
   return(anguloN);
}

float Magnetometro::LecturaSpeedZ(){
  return(Zspeed);
  
}
Magnetometro Compass;


