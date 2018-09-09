const int thres0=850;
const int thres1=850;
const int thres2=850;
const int thres3=630;
const int thres4=630;

int traceSense() {
  int a0=analogRead(A0);
  int a1=analogRead(A1);
  int a2=analogRead(A2);

  //LCDprint1(String(a0)+String(",")+String(a1)+String(",")+String(a2));
  
  int d0,d1,d2;  //d0左,d1中,d2右
  if (a0>thres0) d0=1;   //0=黑,1=白
  else           d0=0;
  if (a1>thres1) d1=1;
  else           d1=0;
  if (a2>thres2) d2=1;
  else           d2=0;

  return d0*4 + d1*2 + d2*1;
}

int trace(float ratio=1.0) {
  int s = traceSense();

  switch(s){
    case 5:
      if (ratio>0.0) speed(vl*ratio, vr*ratio);
      else           speed(vl*(-ratio), vr*(-ratio));
      break;
    
    case 1:
    case 3:
      if (ratio>0.0) speed(0*ratio, vr*ratio);
      else           speed(vl*ratio, vr);
      break;
        
    case 4:
    case 6:
      if (ratio>0.0) speed(vl*ratio, 0*ratio);
      else           speed(vl, vr*ratio);
      break; 

    case 7:
      speed(0,0);
      break;

    case 0:
    default:
      speed(0, 0);
      break;
  }

  return s;
}

