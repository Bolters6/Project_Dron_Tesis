/*
#define TRIGGER 3
#define ECHO 2
class USA{
  
  private:
  long echotime, distancia, Vspeed;
  float tiempo_prev;
   long dis_anterior;
    
  public:
  void SetupUS();
  void Echo();
  long LecturaUS();
  long Velocidadvertical();

  
};

void USA::SetupUS(){
  
   pinMode(TRIGGER, OUTPUT);
   pinMode(ECHO, INPUT);
   
}

void USA::Echo(){
  
float dt = (millis() - tiempo_prev) / 1000.0;
   tiempo_prev = millis();
   digitalWrite(TRIGGER, LOW);
   delayMicroseconds(2);
   digitalWrite(TRIGGER, HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIGGER, LOW);

echotime = pulseIn(ECHO, HIGH);
distancia = (echotime/2)/29;
Vspeed = (distancia - dis_anterior) / dt;
dis_anterior = distancia;
  

}



long USA::LecturaUS(){
 
  return(distancia);  
}
long USA::Velocidadvertical(){
    return(Vspeed);  
}

USA Ultra;
*/
