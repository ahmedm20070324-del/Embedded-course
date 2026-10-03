void setup(){
  volatile char*dir;
  volatile char*d;
  dir=0x21;
  *dir=0xff;
  d=0x24;
  *d=0xff;
}
// Fix delay at diplaying X0
void loop(){
  volatile char*a;
  char A[11]={0x00,0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  long x,y;
  volatile long i;
  for(x=0;x<10;x++){
    a=0x25;
    *a=A[x+1]+0x80;
    for(i=0;i<200000;i++);
    for(y=0;y<10;y++){
      a=0x22;
      *a=A[y+1];
      for(i=0;i<200000;i++);
    }
    *a=A[1];
  }
}
