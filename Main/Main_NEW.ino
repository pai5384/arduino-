int vl=255;
int vr=240;
int turnLThres=850;
int turnRThres=850;
int goStraightTime=530;

#include "move.h"
#include "trace.h"

const int T1Right=2;
const int T3Right=3;
const int T3left=4;


int choice;
void setup() {
  pinMode(13, OUTPUT);
  setup_move();
  Serial.begin(9600);
  delay(3000);
}

void loop() {
 trace();
}
