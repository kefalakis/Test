#include <Servo.h>

Servo green, yellow;
int deg[2];
// int deg[13] = {0,20,40,60,80,100,120,140,160,180};
int servo_green_pin = 9, servo_yellow_pin = 10;
// int i = 1, deg =10;
// bool fwd = true;

void setup(){
  Serial.begin(9600);
  green.attach(servo_green_pin);
  yellow.attach(servo_yellow_pin);
}

void loop(){
  while (Serial.available()<2) {} // Wait 'till there are 9 Bytes waiting
    for(int read_bytes=0; read_bytes<2; read_bytes++)
      deg[read_bytes] = Serial.read(); // Then: Get them.
    // say what you got:
  Serial.print("Green servo deg: ");
  Serial.println(deg[0], DEC);
  Serial.print("Yellow servo deg: ");
  Serial.println(deg[1], DEC);
  // send command to servo motor
  green.write(deg[0]);
  yellow.write(deg[1]);
  delay(15);
}
