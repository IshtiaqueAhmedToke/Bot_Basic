int L_EN_FOR_ONE=11;
int R_EN_FOR_ONE=12;
int L_PWM_FOR_ONE=9;
int R_PWM_FOR_ONE=10;
int L_EN_FOR_TWO=7;
int R_EN_FOR_TWO=8;
int L_PWM_FOR_TWO=5;
int R_PWM_FOR_TWO=6;

int incomingByte=0; // for incoming serial data




void left();
void right();
void forward();
void backward();
void stopo();

void setup() {

Serial.begin(9600);
pinMode(L_EN_FOR_ONE,OUTPUT);
pinMode(R_EN_FOR_ONE,OUTPUT);
pinMode(L_PWM_FOR_ONE,OUTPUT);
pinMode(R_PWM_FOR_ONE,OUTPUT);
pinMode(L_EN_FOR_TWO,OUTPUT);
pinMode(R_EN_FOR_TWO,OUTPUT);
pinMode(L_PWM_FOR_TWO,OUTPUT);
pinMode(R_PWM_FOR_TWO,OUTPUT);

digitalWrite(L_EN_FOR_ONE,HIGH);
digitalWrite(R_EN_FOR_ONE,HIGH);
digitalWrite(L_EN_FOR_TWO,HIGH);
digitalWrite(R_EN_FOR_TWO,HIGH);
}


void loop() {
if (Serial.available() > 0) {
    incomingByte = Serial.read();
    }
  switch(incomingByte)
  {
     case 'S':
      {
        stopo();
       //Serial.println("Stop\n"); 
       incomingByte='*';}
     break;
    
   
     case 'F':
    
     {  
        forward(); 
     
       incomingByte='*';}
     break;
    case 'B' :
    {
        backward();
        incomingByte = '*';}
    
        break;
   
    case 'R' :
    {
    right();
    incomingByte = '*' ;}
    break; 
    
    case 'L' :
    {
    left();
    incomingByte = '*';}
    break; 

    }




 }

  void forward(){
  analogWrite(R_PWM_FOR_ONE,0);
  analogWrite(L_PWM_FOR_ONE,220);
  analogWrite(R_PWM_FOR_TWO,220);
  analogWrite(L_PWM_FOR_TWO,0);
  };
   
  void backward(){
  analogWrite(R_PWM_FOR_ONE,200);
  analogWrite(L_PWM_FOR_ONE,0);
  analogWrite(R_PWM_FOR_TWO,0);
  analogWrite(L_PWM_FOR_TWO,200);
  };
  
  void left(){
  analogWrite(R_PWM_FOR_ONE,0);
  analogWrite(L_PWM_FOR_ONE,180);
  analogWrite(R_PWM_FOR_TWO,0);
  analogWrite(L_PWM_FOR_TWO,0);
  };
  
  void right(){
  analogWrite(R_PWM_FOR_ONE,0);
  analogWrite(L_PWM_FOR_ONE,0);
  analogWrite(R_PWM_FOR_TWO,180);
  analogWrite(L_PWM_FOR_TWO,0);
  };
  
   void stop(){
  analogWrite(R_PWM_FOR_ONE,0);
  analogWrite(L_PWM_FOR_ONE,0);
  analogWrite(R_PWM_FOR_TWO,0);
  analogWrite(L_PWM_FOR_TWO,0);
  }:
