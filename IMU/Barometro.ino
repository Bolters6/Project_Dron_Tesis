#include <SFE_BMP180.h>

class Barometrico{
  
  private:
 double Po;//presion del punto inicial para h=0;
  char status;
  double Temperatura,Presion, PoMedia, Altitude, Altitudemedia = 0;
  int i = 0;
  public:
  SFE_BMP180 bmp180;
  void SetupBaro();
  void PTA();
  double GetTemperature();
   double GetPresion();
   double GetAltitude();
};



void Barometrico::SetupBaro()

{
  if (bmp180.begin())
  { 
   for ( i = 0; i <= 30; i++){
    //Serial.println("BMP180 iniciado correctamentenTomando medidadas del punto de referncia...n");
    status = bmp180.startTemperature();//Inicio de lectura de temperatura
    if (status != 0)
    {   
      delay(status); //Pausa para que finalice la lectura
      status = bmp180.getTemperature(Temperatura);//Obtener la temperatura
      if (status != 0)
      {
        status = bmp180.startPressure(3);//Inicio lectura de presió
        if (status != 0)
        {        
          delay(status);//Pausa para que finalice la lectura        
          status = bmp180.getPressure(Presion,Temperatura);//Obtenemos la presión
          if (status != 0)
          {                  
            Po= Po + Presion; //Asignamos el valor de presión como punto de referencia
                               // Serial.println("Punto de referncia establecido: h=0");  
          }      
        }      
      }   
    }
   delay(3);
  }
   PoMedia = Po / i;
    i = 0;
  }
 
  
  else
  {
    Serial.println("Error al iniciar el BMP180");
    while(1); // bucle infinito
  }
}

void Barometrico::PTA()
{
  //for ( i = 0; i <= 15; i++){
i++;
  status = bmp180.startTemperature();//Inicio de lectura de temperatura
  if (status != 0)
  {   
    delay(status); //Pausa para que finalice la lectura
    status = bmp180.getTemperature(Temperatura);//Obtener la temperatura
    if (status != 0)
    {
      status = bmp180.startPressure(3);//Inicio lectura de presión
      if (status != 0)
      {        
        delay(status);//Pausa para que finalice la lectura        
        status = bmp180.getPressure(Presion,Temperatura);//Obtenemos la presión
        if (status != 0)
        {                    
          //-------Calculamos la altura con respecto al punto de referencia--------
          Altitude= Altitude + bmp180.altitude(Presion,PoMedia);
          if ( i == 23) { 
           Altitudemedia = Altitude / i;
          i = 0;
          Altitude = bmp180.altitude(Presion,PoMedia);
          }
        /*  Serial.print("h=");
          Serial.print(Altitude);
          Serial.println(" metros");    */
 
    }
  }
  

}}
   delay(2);
//}
} 


double Barometrico::GetTemperature(){
  return(Temperatura);
}
double Barometrico::GetPresion(){
  return(Presion);
}
double Barometrico::GetAltitude(){
  return(Altitudemedia);
}
Barometrico BAROPressure;
