#include <SoftwareSerial.h>
#include <Servo.h> 


#define bRX 11
#define bTX 12
#define SV1 10

SoftwareSerial mySerial(bTX,bRX); // RX, TX

Servo servo1;
Servo myservo;

int haveTrace = 0;
long TimeStamp=0;
const int in1Pin=2;
const int in2Pin=3;
const int in3Pin=4;
const int in4Pin=5;

void setup() {
	mySerial.begin(9600);
	Serial.begin(9600);
	Serial.println("press '0' : stop");  
	Serial.println("press '1' :  front");
	Serial.println("press '2' :  back");   
	Serial.println("press '3' : turn right");
	Serial.println("press '4' : turn left"); 
	Serial.println("press '5' : Auto Go"); 
	Serial.println("press 'a' : sensor right"); 
	Serial.println("press 'b' : sensor front"); 
	Serial.println("press 'c' : sensor left"); 
	servo1.attach(SV1);
	myservo.attach(9);
}

void loop() {
	if(mySerial.available()>0){
		char key=mySerial.read();
		Serial.print("key=");
		Serial.println(key);
		
		if(key == '0') GStop();
		if(key == '1') GFront();
		if(key == '2') GBack();
		if(key == '3') GRight();
		if(key == '4') GLeft();
		if(key == '5') haveTrace = 1-haveTrace;
		if(key == 'a') servo1.write(0);
		if(key == 'b') servo1.write(90);
		if(key == 'c') servo1.write(180);
	}
	if(haveTrace == 1) trace();
	servo();  
}

void GFront(){
    analogWrite(in1Pin,0);
    analogWrite(in2Pin,255); 
    analogWrite(in3Pin,0);
    analogWrite(in4Pin,248); 
}

void GBack(){
    analogWrite(in1Pin,255);
    analogWrite(in2Pin,0); 
    analogWrite(in3Pin,248);
    analogWrite(in4Pin,0); 
}

void GStop(){
    analogWrite(in1Pin,0);
    analogWrite(in2Pin,0); 
    analogWrite(in3Pin,0);
    analogWrite(in4Pin,0); 
}

void GLeft(){
    analogWrite(in1Pin,255);
    analogWrite(in2Pin,0); 
    analogWrite(in3Pin,0);
    analogWrite(in4Pin,255); 
}

void GRight(){
	analogWrite(in1Pin,0);
    analogWrite(in2Pin,255); 
    analogWrite(in3Pin,255);
    analogWrite(in4Pin,0);  
}

void trace(){
	int d0,d1,d2;
	int sensorValue1 = analogRead(A0);
	int sensorValue2 = analogRead(A1);
	int sensorValue3 = analogRead(A2);
	if(sensorValue1 >900 ) d0=1; //white 1,black 2;
	else d0=0;
	
	if(sensorValue2 >900 ) d1=1;
	else d1=0;
	
	if(sensorValue3 >900 ) d2=1;
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
}

void servo(){
	if(TimeStamp > 22500 && TimeStamp%250 == 0) myservo.write((45000-TimeStamp)/250);
	else if(TimeStamp%250 == 0) myservo.write(TimeStamp/250);
	
	if(TimeStamp == 45000) TimeStamp = 0;
	else TimeStamp++;
}
