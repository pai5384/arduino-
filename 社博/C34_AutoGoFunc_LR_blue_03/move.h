const int ena = 7;
const int in1 = 9;
const int in2 = 10;
const int in3 = 11;
const int in4 = 12;
const int enb = 2;

void setup_move() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
}

void speed(int l, int r) {
  if (l>0) {
    // 左 正轉
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  else if (l<0) {
    // 左 反轉
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  else {
    // 左 停
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }

  if (r>0) {
    // 右 正轉
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if (r<0) {
    // 右 反轉
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else {
    // 右 停
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }

  analogWrite(ena, abs(l));
  analogWrite(enb, abs(r));
}

void goStraight(int t=goStraightTime) {
  speed(0,0);
  delay(100);
  speed(vl, vr);
  delay(t);
  speed(0,0);
  delay(100);
}

void turnRight90() {
  speed(vl, -vr);
  delay(100);
  speed(150, -150);
  int a2;
  do {
    a2 = analogRead(A2);
  } while (a2>turnRThres);
  //delay(turnRTime);
  speed(-vl, 0);
  delay(50);
  speed(0, 0);
}

void turnLeft90() {
  speed(-vl, vr);
  delay(100);
  speed(-150, 150);
  int a0;
  do {
    a0 = analogRead(A0);
  } while (a0>turnLThres);
  //delay(turnLTime);
  speed(0, vr);
  delay(30);
  speed(0,0);
  delay(500);
  speed(0,0);
}
