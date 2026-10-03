void setup() {
  volatile char*dir;
  dir=0x30;
  *dir=0xff;

}
void loop() {
  volatile long i;
  volatile char*disp;
  disp=0x30;
  char A[17]={0x00,0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  long x,y,z;
  for(x=2;x<10;x++){
    z=1;
    for(y=2;y<x;y++){
      if(x%y==0){
        z=0;
        break;
      }
    }
    if(z==1){
      *disp=A[x+1];
      for(i=0;i<500000;i++);
    }
  }
}
