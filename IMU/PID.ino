/*#include <PID_v1.h>  // marca

class Control
{
  
  private:

  
  double SaggTKp=7, SaggTKi=2, SaggTKd=2.4;
  double aggTKp=5, aggTKi=1.8, aggTKd=2;
  double norTKp=3., norTKi=1.5, norTKd=1.7;
  double VALX = 0, VALY = 0, VALWX = 0, VALWY = 0, VALOUTX = 0, VALOUTY = 0; 
  int ERRORWX = 0, ERRORWY = 0;
  float ERRORX = 0, ERRORY = 0;
  
  public:
  
   void configuracionX();   
   void computeX();          
   void configuracionY();    
   void computeY();                     
   void configuracionT();
   void computeT();
   void PUTSP();
   
};

double KpX=6.5, KiX=0.2, KdX=0.1;
double WXKp=0.1, WXKi=0, WXKd=0.01;
double Kp=6.5, Ki=0.2, Kd=0.1;
double WKp=0.1, WKi=0, WKd=0.01;
double consTKp=2, consTKi=1.1, consTKd=1.3;
double SetpointX = 2.5, SetpointY = -1.3, SetpointT = 0, SetpointWX = 0.08, SetpointWY = 0.06;
double OutputX, OutputY, OutputT, OutputWX, OutputWY;
double InputX, InputY, InputT, InputWX, InputWY;


PID myPIDX(&InputX, &OutputX, &SetpointX, KpX, KiX, KdX, DIRECT);
PID myPIDWX(&InputWX, &OutputWX, &SetpointWX, WXKp, WXKi, WXKd, DIRECT);
PID myPIDWY(&InputWY, &OutputWY, &SetpointWY, WKp, WKi, WKd, DIRECT);
PID myPIDY(&InputY, &OutputY, &SetpointY, Kp, Ki, Kd, DIRECT);
PID myPIDT(&InputT, &OutputT, &SetpointT, consTKp, consTKi, consTKd, DIRECT);

 void Control::configuracionX(){
  
   myPIDX.SetMode(AUTOMATIC);
   myPIDX.SetSampleTime(10);
   myPIDX.SetOutputLimits(-1000 , 1000);
    myPIDWX.SetMode(AUTOMATIC);
   myPIDWX.SetSampleTime(10);
   myPIDWX.SetOutputLimits(-1000 , 1000);
}

 void Control::computeX(){
  
    
    InputX = GYRO.GetAngleX();
    InputWX = GYRO.GetOMEGAX();
    
   
   
    ERRORX = SetpointX-InputX;
    ERRORWX = SetpointWX - InputWX;
    
      
   myPIDWX.Compute();
   myPIDX.Compute(); 
  
}

 void Control::configuracionY(){
  
   myPIDY.SetMode(AUTOMATIC);
   myPIDY.SetSampleTime(10);
   myPIDY.SetOutputLimits(-1000 , 1000);
    myPIDWY.SetMode(AUTOMATIC);
   myPIDWY.SetSampleTime(10);
   myPIDWY.SetOutputLimits(-1000 , 1000);
}

 void Control::computeY(){
  
   
    InputY = GYRO.GetAngleY();
    
    InputWY = GYRO.GetOMEGAY();
    
    
           ERRORY = SetpointY - InputY;
           ERRORWY = SetpointWY - InputWY;
           
 myPIDWY.Compute();
 myPIDY.Compute(); 
    
}


void Control::configuracionT(){
  
   myPIDT.SetMode(AUTOMATIC);
   myPIDT.SetSampleTime(1);
   myPIDT.SetOutputLimits(950 , 1850);
}

void Control::computeT(){
  
  /* Ultra.Echo();
   InputT = Ultra.LecturaUS();

   double gapT = abs(SetpointT-InputT);
   
 if ( gapT <= 5 ){
    
    myPIDT.SetTunings(consTKp, consTKi, consTKd);
    
   }
   
   if (gapT > 7 && gapT <= 20 ){
    
    myPIDT.SetTunings(norTKp, norTKi, norTKd);
    
   }
   
   if (gapT > 30 && gapT <= 40) {
    
    myPIDT.SetTunings(aggTKp, aggTKi, aggTKd);
    
   }
   
   if (gapT > 42) {
    
    myPIDY.SetTunings(SaggTKp, SaggTKi, SaggTKd);
    
   }
 
   
   myPIDT.Compute();
  /* Serial.print(" THROTTLE ");
   Serial.println(abs(OutputT));*/
  /*  GYRO.LecturaGyro();          //marca
   computeX();
   computeY();
   
   M.MOTORESX( 40, 40);
    M.MOTORESY(40, 40);
   
   /*double OUTPUTXT = abs(OutputX) + abs(OutputT);
   double OUTPUTYT = abs(OutputY) + abs(OutputT);
   double ABSOUTPUTT = abs(OutputT);*/
   
/*  if ((ERRORX > 1) && (ERRORY > 0) || (ERRORY > 1 ) && (ERRORX > 0))   //marca
   
   {
    
    while ((ERRORX > 0 && ERRORY > 0)) {

     GYRO.LecturaGyro();
      //myPIDT.Compute();
      computeX();
      VALX = map(OutputX, 0, 900, 0, 130);
      if ( ERRORWX > 0 ) {
        
         VALWX = -(map(abs(OutputWX), 0, 1000, 0, 50));
      
      }else{
         VALWX = map(abs(OutputWX), 0, 1000 , 0, 50 );
         
      }
      if (ERRORWX == 0) {
        myPIDWX.SetMode(MANUAL);
        OutputWX = 0;
         myPIDWX.SetMode(AUTOMATIC);
      }
      
    VALOUTX = VALX - VALWX;
    
       M.MOTORESX( 40 + VALOUTX, 40 - (VALX/6));
    
      computeY();
      VALY = map(OutputY, 0, 900, 0, 130);
       if ( ERRORWY > 0) {
        
         VALWY = -(map(abs(OutputWY), 0, 1000, 0, 50));
      
      }else{
        
         VALWY = map(abs(OutputWY), 0, 1000 , 0, 50);
         
      }
      if (  ERRORWY == 0  ) {
        myPIDWY.SetMode(MANUAL);
        OutputWY = 0;
         myPIDWY.SetMode(AUTOMATIC);
      }
      VALOUTY = VALY - VALWY;
      M.MOTORESY(40 - (VALY/6), 40 + VALOUTY);
      
    Serial.print(" XL ");
    Serial.println(VALWX);
    Serial.print(" YR ");
    Serial.println(VALWY);
   /* Serial.print("IDAAAXXX");
    Serial.println(IX);
    Serial.print("IDAAAYYY");
    Serial.println(IY);*/
   /* Serial.print(" T ");
    Serial.println(abs(OutputT));*/
  
      

    
    
   // M.MOTORESX((OutputX + abs(OutputT)),abs(OutputT));
   // M.MOTORESY(abs(OutputT),abs(OutputT));
    
  //M.ESCXL.writeMicroseconds(OutputX + abs(OutputT));  
  //M.ESCXR.writeMicroseconds(abs(OutputT));  
      
 /*   };    /marca

     
    if ( ERRORX <= 0 ) {

      
      myPIDX.SetMode(MANUAL);
       OutputX = 0;
       
       //M.MOTORESX( 40, 40);
        myPIDX.SetMode(AUTOMATIC);
        
      
       }
       
       if ( ERRORY <= 0 ) {
        
    
      myPIDY.SetMode(MANUAL);
       OutputY = 0;
       
      // M.MOTORESY( 40, 40);
        myPIDY.SetMode(AUTOMATIC);
        
      
       }
   }
    
   if ((ERRORX < -1) && (ERRORY < 0) || (ERRORY < -1 ) && (ERRORX < 0))
  
     {
    
    while(ERRORX < 0 && ERRORY < 0) {
  GYRO.LecturaGyro();
      //myPIDT.Compute();
     computeX();
      VALX = map(abs(OutputX), 0, 900, 0, 130);
      
      if ( ERRORWX > 0 ) {
        
         VALWX = map(abs(OutputWX), 0, 1000, 0, 50);
      
      }else{
         VALWX = -(map(abs(OutputWX), 0, 1000 , 0, 50));
         
      }
       if (  ERRORWX == 0  ) {
        myPIDWX.SetMode(MANUAL);
        OutputWX = 0;
        myPIDWX.SetMode(AUTOMATIC);
      }
    VALOUTX = VALX - VALWX;
     M.MOTORESX(40 - (VALX/6), 40 + VALOUTX);
      computeY();
      VALY = map(abs(OutputY), 0, 900 , 0, 130);
       if ( ERRORWY > 0) {
        
         VALWY = map(abs(OutputWY), 0, 1000, 0, 50);
      
      }else{
        
         VALWY = -(map(abs(OutputWY), 0, 1000 , 0, 50));
         
      }
      if (  ERRORWY == 0  ) {
        myPIDWY.SetMode(MANUAL);
        OutputWY = 0;
         myPIDWY.SetMode(AUTOMATIC);
      }
      VALOUTY = VALY - VALWY;
      M.MOTORESY(40 + VALOUTY, 40 - (VALY/6));
     
       Serial.print(" XR ");
    Serial.println(VALWX);
    Serial.print(" YL ");
    Serial.println(VALWY);
    
  
     
     /*Serial.print(" XR ");
    Serial.println(abs(OutputX)+ abs(OutputT));
    Serial.print(" T ");
    Serial.println(abs(OutputT));*/
    
    //M.MOTORESX(abs(OutputT),(abs(OutputX)+ abs(OutputT)));
    //M.MOTORESY(abs(OutputT),abs(OutputT));
    
    //M.ESCXL.writeMicroseconds(abs(OutputT));  
    //M.ESCXR.writeMicroseconds(abs(OutputX) + abs(OutputT));       

  /*  };   //marca
    
    
   if ( ERRORX >= 0 ) {

     
      myPIDX.SetMode(MANUAL);
       OutputX = 0;
       
      // M.MOTORESX( 40, 40);
        myPIDX.SetMode(AUTOMATIC);
        
      
       }
       
       if ( ERRORY >= 0 ) {

      
      myPIDY.SetMode(MANUAL);
       OutputY = 0;
      
      // M.MOTORESY( 40, 40);
        myPIDY.SetMode(AUTOMATIC);
        
      
       }
    
   }

   if ((ERRORX > 1) && ( ERRORY < 0) || (ERRORY < -1 ) && (ERRORX > 0)){
    
    while(ERRORX > 0 && ERRORY < 0) {

       GYRO.LecturaGyro();
      //myPIDT.Compute();
      computeX();
      VALX = map(OutputX, 0, 900, 0, 130);
      
      if ( ERRORWX > 0 ) {
        
         VALWX = -(map(abs(OutputWX), 0, 1000, 0, 50));
      
      }else{
         VALWX = map(abs(OutputWX), 0, 1000 , 0, 50);
         
      }
       if (  ERRORWX == 0  ) {
        myPIDWX.SetMode(MANUAL);
        OutputWX = 0;
        myPIDWX.SetMode(AUTOMATIC);
      }
    VALOUTX = VALX - VALWX;
    M.MOTORESX( 40 + VALOUTX, 40 - (VALX/6));
      computeY();
      VALY = map(abs(OutputY), 0, 900, 0, 130);
       if ( ERRORWY > 0 ) {
        
         VALWY = map(abs(OutputWY), 0, 1000, 0, 50);
      
      }else{
        
         VALWY = -(map(abs(OutputWY), 0, 1000 , 0, 50));
         
      }
      if (  ERRORWY == 0  ) {
        myPIDWY.SetMode(MANUAL);
        OutputWY = 0;
         myPIDWY.SetMode(AUTOMATIC);
      }
      VALOUTY = VALY - VALWY;
      M.MOTORESY(40 + VALOUTY, 40 - (VALY/6));
       Serial.print(" XL ");
    Serial.println(VALWX);
   Serial.print(" YL ");
    Serial.println(VALWY);
   
    /*Serial.print(" YR ");
    Serial.println(OutputY + abs(OutputT));
    Serial.print(" T ");
    Serial.println(abs(OutputT));*/

 
      
   // M.MOTORESY(abs(OutputT),(OutputY + abs(OutputT)));
    //M.MOTORESX(abs(OutputT),abs(OutputT));
    
  //M.ESCYR.writeMicroseconds(OutputY + abs(OutputT));  
  //M.ESCYL.writeMicroseconds(abs(OutputT));      
  /*  };

  if ( ERRORX <= 0 ) {    //marca

 
      myPIDX.SetMode(MANUAL);
       OutputX = 0;
      
       //M.MOTORESX( 40, 40);
        myPIDX.SetMode(AUTOMATIC);
        
      
       }
       
       if ( ERRORY >= 0 ) {

  
      myPIDY.SetMode(MANUAL);
       OutputY = 0;
       
       //M.MOTORESY( 40, 40);
        myPIDY.SetMode(AUTOMATIC);
        
      
       }
    
   } 
   if ((ERRORX < -1) && (ERRORY > 0) || (ERRORY > 1 ) && (ERRORX < 0))
   {
    
    while(ERRORX < 0 && ERRORY > 0) {

      GYRO.LecturaGyro();
      //myPIDT.Compute();
      computeX();
      VALX = map(abs(OutputX), 0, 900, 0, 130);
    
      if ( ERRORWX > 0 ) {
        
         VALWX = map(abs(OutputWX), 0, 1000, 0, 50);
      
      }else{
         VALWX = -(map(abs(OutputWX), 0, 1000 , 0, 50));
         
      }
       if (  ERRORWX == 0  ) {
        myPIDWX.SetMode(MANUAL);
        OutputWX = 0;
        myPIDWX.SetMode(AUTOMATIC);
      }
      
    VALOUTX = VALX - VALWX;
    M.MOTORESX(40 - (VALX/6), 40 + VALOUTX);
      computeY();
      VALY = map(OutputY, 0, 900, 0, 130);
       if ( ERRORWY > 0) {
        
         VALWY = -(map(abs(OutputWY), 0, 1000, 0, 50));
      
      }else{
        
         VALWY = map(abs(OutputWY), 0, 1000 , 0, 50);
         
      }
     if (  ERRORWY == 0 ) {
        myPIDWY.SetMode(MANUAL);
        OutputWY = 0;
         myPIDWY.SetMode(AUTOMATIC);
      }
      VALOUTY = VALY - VALWY;
      M.MOTORESY(40 - (VALY/6), 40 + VALOUTY);
     Serial.print(" XR ");
    Serial.println(VALWX);
   Serial.print(" YR ");
    Serial.println(VALWY);
   
      
     /*Serial.print(" YL ");
    Serial.println(abs(OutputY)+ abs(OutputT));
    Serial.print(" T ");
    Serial.println(abs(OutputT));*/
    

    
    //M.MOTORESY((abs(OutputY)+ abs(OutputT)),abs(OutputT));
    //M.MOTORESX(abs(OutputT),abs(OutputT));
    
     // M.ESCYR.writeMicroseconds(abs(OutputT));  
      //M.ESCYL.writeMicroseconds(abs(OutputY) + abs(OutputT));  
  /*  };    //marca
    
   
  if ( ERRORX >= 0 ) {

     
      myPIDX.SetMode(MANUAL);
       OutputX = 0;
       
       //M.MOTORESX( 40, 40);
        myPIDX.SetMode(AUTOMATIC);
       
      
       }
       
       if ( ERRORY <= 0 ) {

     
      myPIDY.SetMode(MANUAL);
       OutputY = 0;
       
       //M.MOTORESY( 40, 40);
        myPIDY.SetMode(AUTOMATIC);
       
      
       }
}
}

void Control::PUTSP(){
 
if (Serial.available()) {
   SetpointT = Serial.parseFloat();
}

}

Control CONTROL;*/
