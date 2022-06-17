
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

 int ax, ay, az;
int gx, gy, gz;
 
long tiempo_prev;
float dt;
float ang_x, ang_y, vy_prev, VNY;
float ang_x_prev, ang_y_prev;

class Giroscopio{
 
   private:
 

   public:
  // const int mpuAddress = 0x69;  // Puede ser 0x68 o 0x69
  MPU6050 mpu;
   void Iniciotransmision();
   void LecturaGyro();
   
   double GetAngleX();
   double GetAngleY();
   double GetOMEGAY();
   double GetOMEGAX();
   
   //Giroscopio() : AngleX(0), AngleY(0), Gy1(0), Acc1(0), Gy2(0), Acc2(0), AcX(0), AcY(0), AcZ(0), GyX(0), GyY(0), GyZ(0) {}
   
   
};

 void Giroscopio::Iniciotransmision()
 
    {
     
   Wire.begin();
   mpu.initialize();
   //Serial.println(mpu.testConnection() ? F("IMU iniciado correctamente") : F("Error al iniciar IMU"));
    }
    
   void updateFiltered()
{
   dt = (millis() - tiempo_prev) / 1000.0;
   tiempo_prev = millis();
 
   //Calcular los ángulos con acelerometro
   float accel_ang_x = atan(ay / sqrt(pow(ax, 2) + pow(az, 2)))*(180.0 / 3.14);
   float accel_ang_y = atan(-ax / sqrt(pow(ay, 2) + pow(az, 2)))*(180.0 / 3.14);
 
   //Calcular angulo de rotación con giroscopio y filtro complementario
   ang_x = 0.975*(ang_x_prev + (gx / 131)*dt) + 0.025*accel_ang_x;
   ang_y = 0.975*(ang_y_prev + (gy / 131)*dt) + 0.025*accel_ang_y;
   
   ang_x_prev = ang_x;
   ang_y_prev = ang_y;

  
}

    void Giroscopio::LecturaGyro()
    {  
  // Leer las aceleraciones y velocidades angulares
   mpu.getAcceleration(&ax, &ay, &az);
   mpu.getRotation(&gx, &gy, &gz);
 
   updateFiltered();
 
  /* Serial.print(F("Rotacion en X:  "));
   Serial.print(ang_x);
   Serial.print(F("\t Rotacion en Y: "));
   Serial.println(ang_y);*/
 
   delay(10);
   
    }
    
    double Giroscopio::GetAngleY(){
      return(ang_y);
      
    }
    
     double Giroscopio::GetAngleX(){
      return(ang_x);
    }
    
     double Giroscopio::GetOMEGAY(){
      return(gy/131);
     }
     
    double Giroscopio::GetOMEGAX(){
      return(gx/131);
     }
     
   Giroscopio GYRO;

