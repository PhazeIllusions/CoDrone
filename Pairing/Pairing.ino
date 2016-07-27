#include <CoDrone.h>

void setup() {
  // put your setup code here, to run once:
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x9B, 0xA5, 0x61, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);

 for(int i = 0; i < 100; i++){
  CoDrone.LedColor(ArmDimming, 51, 225, 0, 79);
   delay(500);
   CoDrone.LedColor(ArmDimming, 119, 119, 204, 7);
    delay(500);
    CoDrone.LedColor(ArmDimming, 159, 159, 254, 7);
    delay(500);
    CoDrone.LedColor(ArmDimming, 109, 109, 214, 7);
    delay(500);
    CoDrone.LedColor(ArmDimming, 59, 59, 174, 7);
  }
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
  
