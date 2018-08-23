

  //LCDprint1(String(a0)+String(",")+String(a1)+String(",")+String(a2));
  
  int d0,d1,d2;  //d0左,d1中,d2右
  if (a0>thres0) d0=1;   //0=黑int vl=255;
int vr=255;

const int thres0=850;
const int thres1=850;
const int thres2=850;


int traceSense() {
  int a0=analogRead(A0);
  int a1=analogRead(A1);
  int a2=analogRead(A2);,1=白
  else           d0=0;
  if (a1>thres1) d1=1;
  else           d1=0;
  if (a2>thres2) d2=1;
  else           d2=0;

  return d0*4 + d1*2 + d2*1;
}

/*int allWhite() {
  int s;
  for (int t=50; t<=1000; t+=50) {
    speed(-vl*0.7, vr);
    delay(t);
    speed(0,0);
    s = traceSense();
    if (s!=7) return s;
    speed(vl, -vr*0.7);
    delay(t);
    speed(0,0);
    s = traceSense();
    if (s!=7) return s;
  }
}*/

int trace(float ratio=1.0) {
  int s = traceSense();

  switch(s){
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
       GStop();
      break;

    case 0:
    default:
       GStop();
      break;
  }

  return s;
}

/*int look_color(){
  int a3=analogRead(A3);
  int a4=analogRead(A4);
 

//  LCDprint1(String(a3)+String(",")+String(a4));


  int d3,d4;    //d4左,d5右

  if(a3>thres3) d3=1;
  else          d3=0;
  if(a4>thres4) d4=1;
  else          d4=0;

  int f = d3*2 + d4*1;

  return f;
}*/


