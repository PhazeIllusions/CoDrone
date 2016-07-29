
#include <CoDrone.h>
unsigned long startTime;
int step;
void setup() {
  CoDrone.begin(115200);
  // put your setup code here, to run once:
  byte droneAddress[6] = {0x9B, 0xA5, 0x61, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte left = digitalRead(11);
  byte middle = digitalRead(14);
  byte right = digitalRead(18);
  if (left == 1) {
    step = 0;
    CoDrone.FlightEvent(Stop);

  }
  else if (right == 1) {
    step = step + 1;
    if (step > 4) {


      step = 0;
    }
    CoDrone.Buzz( 3000, 7);
    delay(200);
  }
  else if (middle == 1) {
    //.CoDrone.Buzz(step * 10, 7);
    //step = step -100;
  }
  if (step == 1) {
    THROTTLE = 100;
    CoDrone.Control();

  }
  else if (step == 2) {
    PITCH = 100;
    CoDrone.Control();

  }
  else if (step == 3) {
    ROLL = -100;
    CoDrone.Control();

  }
  else if (step == 4) {
    PITCH = 100;
    CoDrone.Control();
  }
  else {
    CoDrone.FlightEvent(Landing);
  }
}
