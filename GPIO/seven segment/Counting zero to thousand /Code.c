void setup() {
  volatile char*dir;
  dir=0x21;
  *dir=0xff;
  dir=0x24;
  *dir=0xff;
  dir=0x30;
  *dir=0xff;
  dir=0x107;
  *dir=0xff;

}

void loop() {
  volatile long i;
  volatile char*x;
  char A[11]={0x00,0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  long a,b,c,d;
  for(a=0;a<10;a++){
    x=0x22;
    *x=A[a+1];
    for(b=0;b<10;b++){
      x=0x25;
      *x=A[b+1];
      for(c=0;c<10;c++){
        x=0x31;
        *x=A[c+1];
        for(d=0;d<10;d++){
          x=0x108;
          *x=A[d+1];
          for(i=0;i<250000;i++);
        }
        *x=A[1];
      }
    }
  }

}
