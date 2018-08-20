int vl=255;
int vr=240;
//int turnLTime=890;
//int turnRTime=800;
int turnLThres=850;
int turnRThres=850;
int goStraightTime=530;

//#define SER_DBG 1

//#include "serialDebug.h"
//#include "lcd.h"
#include "move.h"
#include "trace.h"
//#include "color.h"
//#include "raise.h"
//#include "run.h"
//#include "soccer.h"

// 0=white, 1=red, 2=yellow, 3=green
const int T1Right=2;
//const int T1Left=0;
const int T3Right=3;
const int T3left=4;


int choice;
void setup() {
  pinMode(13, OUTPUT);

  //setup_serialDbg();
  setup_move();
  //setup_lcd();
  //setup_raise();

  Serial.begin(9600);
  delay(3000);
  //serialDbg("起!");

  while (0) {
    //trace();
    look_color();
    //LCDprint1(String(color()));
    //color();
  }
  while (0) {
    //turnLeft90();
    //turnRight90();
    goStraight();
    speed(0,0);
    delay(1000);
  }

  /*blockAB();
  //choice=0;
  //return;
  if (choice==0) {
    blockBC();
  }
  else {
    blockBDE();
  }
  return;
  blockBF();
  if (choice==0) {
    blockFG();
  }
  else {
    blockFHI();
  }
}

void blockAB() {
  // 起跑線 直接前進?s
  goStraight(goStraightTime+100);
  
  debug2("tracing&finding");

  // 循跡前進,找停止線
  int f;
  do {
    trace();
    f = look_color();
  } while(f==3);
  speed(0,0);
  debug2(String("found stop line"));
  serialDbg("找到停止線");
  delay(2000);

  // 測色卡
  serialDbg("T1色卡");
  int c;
  c = color();
  serialDbg(String("T1色卡:")+String(c));
  speed(0,0);
  delay(1000);
  serialDbg("走一小段");
  goStraight();
  speed(0,0);
  delay(1000);

  // 轉彎面向下一段
  if (c==T1Right) {
    turnRight90();
    choice=0;
    debug2(String("turn right"));
    serialDbg("右轉");
  }
  else {
    speed(-170,170);
    delay(200);
    turnLeft90();
    choice=1;
    debug2(String("turn left"));
    serialDbg("左轉");
  }
}

void blockBC() {
  //down(); return;
  serialDbg("blockBC");
  // 走直線
  int t, f;
  do {
    t = trace();
    
    f = look_color();
  } while (f==3);
  serialDbg("走到停止線");
  while (f!=0) {
    if (f==2) speed(vl*0.5, vr*(-0.2)); 
    if (f==1) speed(vl*(-0.2), vr*0.5);
    if (f==3) break;
    //對車位
    f = look_color();
  }
  serialDbg("已到停止線");
  speed(0,0);
  delay(200);

  //走到槓鈴下
  speed(110, 95);
  delay(1650);
  speed(-165, -150);
  delay(345);
  speed(0,0);
  delay(100);
  raise();
  straight();
  down();
  back();
  go();
}
void blockBDE() {
  debug2("blockBDE");
  serialDbg("blockBDE");
  int r;
  r = run();
  start(r);
  //speed(vl,vr);
  //delay(2000);
  goStraight();
  goStraight();
} 

void blockBF() {
  //走直線
  int t;
  int f;
  do{
    t = trace();
    f = look_color();
  }while(f==3);

  //看顏色
  c = color();
  if (c==T3Right) {
    turnRight90();
    choice=0;
  }
  else {
    turnLeft90();
    choice=1;
  }
}

void blockFG() {
  //找停止線
  int t,f;
  do{
    t = trace();
    f = look_color();
  }while(f==3);
  soccer (); 
}

void blockFHI() {
  //直線到沙坑
  int t;
  while(true){
    t = trace();
    if(t==0 || t==7){
      break;
    }
  }
  speed(vl,vr);
  delay(6000);
  do{
    t = trace();
  }while(t!=0);
  speed(vl,vr);
  delay(600);  */
}

void loop() {
 trace();
}
