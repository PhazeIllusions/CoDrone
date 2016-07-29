#include <CoDrone.h>
void setup() {
  // put your setup code here, to run once:
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x9B, 0xA5, 0x61, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);
  for (int i = 0; i < 3.; i++) {
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
  CoDrone.BattleBegin(TEAM_BLUE);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte left = digitalRead(11);
  byte middle = digitalRead(14);
  byte right = digitalRead(18);
  if (left == 1) {
    CoDrone.FlightEvent(Stop);
  }
  else if (middle == 1) {
    CoDrone.FlightEvent(Landing);
  }
  else if (right == 1) {
    CoDrone.BattleShooting();
    CoDrone.ButtonPreesHoldWait(18);
    CoDrone.Buzz(4000,010 7);
  }
  THROTTLE = CoDrone.AnalogScaleChange(analogRead(A4));
  PITCH = CoDrone.AnalogScaleChange(analogRead(A6));
  ROLL = -1 * CoDrone.AnalogScaleChange(analogRead(A5));
  YAW = -1 * CoDrone.AnalogScaleChange(analogRead(A3));
  CoDrone.Control();
}
