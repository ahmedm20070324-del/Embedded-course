void setup() {
  volatile char*dir;
  dir=0x30;
  *dir=0xff;

}

void loop() {
  volatile char*c;
  c=0x31;
  *c=0x71;
}
