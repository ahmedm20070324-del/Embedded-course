void setup() {
  volatile long*da;
  volatile long*db;
  da=0x21;
  *da=0xff;
  db=0x24;
  *db=0xff;

}

void layer1(long x){
  volatile long*a;
  a=0x22;
  *a=x;
}
void layer2(long x){
  volatile long*b;
  b=0x25;
  *b=x;
}
void mydelay(){
  volatile long i;
  for(i=0;i<400000;i++);
}
void loop(){
  long x;
  x=0x55;
  layer1(x);
  mydelay();
  layer1(0);
  mydelay();
  x=0xaa;
  layer2(x);
  mydelay();
  layer2(0);
  mydelay();
  x=0x55;
  layer2(x);
  mydelay();
  layer2(0);
  mydelay();
  x=0xaa;
  layer1(x);
  mydelay();
  layer1(0);
  mydelay();

}
