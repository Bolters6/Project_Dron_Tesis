
class Vigilancia{
  
  private:
// int pirState = LOW;           // de inicio no hay movimiento
int val = 0;                  // estado del pin

  public:
  #define PIRPin 12        // pin de entrada (for PIR sensor)
 #define AlarmPin 13    // pin para el buzzer
  void setupPIRAlarm();
  int PIRAlarm();
  
};




 
void Vigilancia::setupPIRAlarm() 
{
   pinMode(AlarmPin, OUTPUT); 
   pinMode(PIRPin, INPUT);
   //Serial.begin(9600);
}
 
int  Vigilancia::PIRAlarm()
{
   val = digitalRead(PIRPin);
   if (val == HIGH)   //si está activado
   { 
      digitalWrite(AlarmPin, HIGH);  //LED ON
     /* if (pirState == LOW)  //si previamente estaba apagado
      {
        Serial.println("Sensor activado");
        pirState = HIGH;
      }*/
   } 
   else   //si esta desactivado
   {
      digitalWrite(AlarmPin, LOW); // LED OFF
     /* if (pirState == HIGH)  //si previamente estaba encendido
      {
        Serial.println("Sensor parado");
        pirState = LOW;
      }*/
   }
   return(val);
}
Vigilancia Alarma;
