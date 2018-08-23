#include <SoftwareSerial.h>
#include <Servo.h> 
Servo servo1;
Servo myservo;

#define bRX 11
#define bTX 12
SoftwareSerial mySerial(bTX,bRX); // RX, TX
const int light=13;
byte light_op=0;

int sensorValue1 = analogRead(A0);
int sensorValue2 = analogRead(A1);
int sensorValue3 = analogRead(A2);
int TimeStamp=0;
const int in1Pin=2;
const int in2Pin=3;
const int in3Pin=4;
const int in4Pin=5;
//#define TRIGPIN 8
//#define ECHOPIN 9
#define SV1 10
double dangerThresh = 10;
double distance;
int dir = 0;
char key = '0';
double distR=0;
double distL=0;
int DeTime = 1000;

void setup() 
{ 
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(light,OUTPUT);
  Serial.println("press '0' : stop");  
  Serial.println("press '1' :  front");
  Serial.println("press '2' :  back");   
  Serial.println("press '3' : turn right");
  Serial.println("press '4' : turn left"); 
  Serial.println("press '5' : Auto Go"); 
  Serial.println("press 'a' : sensor right"); 
  Serial.println("press 'b' : sensor front"); 
  Serial.println("press 'c' : sensor left"); 
//  pinMode(TRIGPIN, OUTPUT);  // 觸發腳設定成「輸出」
//  pinMode(ECHOPIN, INPUT);   // 接收腳設定成「輸入」 
  servo1.attach(SV1);
   myservo.attach(9);
} 
void loop() 
{
  
  //if(Serial.available())
  if(mySerial.available()>0)
  {
    //key=Serial.read();
    key=mySerial.read();
    Serial.print("key=");
    Serial.println(key);
    switch(key)
    {
      case '0':
        GStop();
      break;
      case '1':
        GFront(); 
      break;
      case '2':
        GBack(); 
      break;
      case '3':
        GRight();
      break;
      case '4':
        GLeft();
      break;
      case '5':
          trace();
      break;
	  case '6':
        DeTime -= 100;
		if(DeTime < 100)
			DeTime = 1000;
		Serial.print("DeTime=");
		Serial.println(DeTime);
		mySerial.print("DeTime=");
		mySerial.println(DeTime);
      break;
      case 'a':
        servo1.write(0);
      break;
      case 'b':
        servo1.write(90);
      break;
      case 'c':
        servo1.write(180); 
      break;
    }      
  }
  servo();  
}

void GFront()
{
    analogWrite(in1Pin,0);
    analogWrite(in2Pin,255); 
    analogWrite(in3Pin,0);
    analogWrite(in4Pin,248); 
}
void GBack()
{
    analogWrite(in1Pin,255);
    analogWrite(in2Pin,0); 
    analogWrite(in3Pin,248);
    analogWrite(in4Pin,0); 
}
void GStop()
{
    analogWrite(in1Pin,0);
    analogWrite(in2Pin,0); 
    analogWrite(in3Pin,0);
    analogWrite(in4Pin,0); 
}
void GLeft()
{
    analogWrite(in1Pin,255);
    analogWrite(in2Pin,0); 
    analogWrite(in3Pin,0);
    analogWrite(in4Pin,255); 
}
void GRight()
{
    analogWrite(in1Pin,0);
    analogWrite(in2Pin,255); 
    analogWrite(in3Pin,255);
    analogWrite(in4Pin,0);  
}
void trace(){
  while(true){
    int d0,d1,d2;
    int sensorValue1 = analogRead(A0);
    int sensorValue2 = analogRead(A1);
    int sensorValue3 = analogRead(A2);
    if(sensorValue1 >900 ){  //white 1,black 2;
          d0 =1;
    }
    else d0=0;
    if(sensorValue2 >900 ){
          d1=1; 
    }
    else d1=0;
    if(sensorValue3 >900 ){
          d2=1;
    }
    else d2=0;
    int  all=d0*4+d1*2+d2*1;
    switch(all){
      case 5:
        GFront(); 
        break;
      
      case 1:
      case 3:
         GLeft();
        break;
          
      case 4:
      case 6:
        GRight();
        break; 
  
      case 7:
      case 0:
      default:
         GStop();
        break;
    }
    key = mySerial.read();
    if(key=='5')break;
  }
  return;
}

void servo(){
	if(TimeStamp > 4500 ){
		if(TimeStamp%50 == 0){
			myservo.write((9000-TimeStamp)/50);
		}
	}
	else{
		if(TimeStamp%50 == 0){
			myservo.write(TimeStamp/50);
		}
	}
	if(TimeStamp == 9000) TimeStamp = 0;
	else TimeStamp++;
}
