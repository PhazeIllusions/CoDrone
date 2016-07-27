#include <CoDrone.h>

void setup() {
  // put your setup code here, to run once:
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x9B, 0xA5, 0x61, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);
CoDrone.LedColor(ArmDimming, 51, 225, 0, 79);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte sensor1 = digitalRead(11);
  byte sensor4 = digitalRead(14);
  byte sensor8 = digitalRead(18);
  if (sensor1 == 1) {
    CoDrone.FlightEvent(Stop);
  }
  
  else if(sensor8){
CoDrone.FlightEvent(TakeOff);

    
  }
  }
