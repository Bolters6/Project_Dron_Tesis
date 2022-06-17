/*#include <SoftwareSerial.h>
SoftwareSerial BT(2,3); //rx,tx

class Comunicacion {
  private:
  char Bytes;

  public:
  
  void SetupBT();
 char ReceivedBytes();
 void SendBytes(char x);
};

void Comunicacion::SetupBT(){
  BT.begin(9600);
}
void Comunicacion::SendBytes(char x){
  BT.println(x);
}

char Comunicacion::ReceivedBytes(){

  if ( BT.available() ){
     Bytes = BT.read();
  }else{
    Bytes = 0;
  }
return(Bytes);
  
}
Comunicacion BlueT;*/
