// 3. Include the CoDrone library in your code
#include <CoDrone.h>
// 1. Add the method that runs once, before anything else
void setup() {
  // put your setup code here, to run once:
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x9B, 0xA5, 0x61, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);
// for(int i = 0; i < 3.; i++){
  //CoDrone.LedColor(ArmDimming, 51, 225, 0, 79);
   //delay(500);
   //CoDrone.LedColor(ArmDimming, 119, 119, 204, 7);
   // delay(500);
    //CoDrone.LedColor(ArmDimming, 159, 159, 254, 7);
    //delay(500);
    //CoDrone.LedColor(ArmDimming, 109, 109, 214, 7);
    //delay(500);
    //CoDrone.LedColor(ArmDimming, 59, 59, 174, 7);
  //}
}

//   4. Set up the thread - HINT: 115200
void loop() {
  // put your main code here, to run repeatedly:
  byte left = digitalRead(11);
  byte middle = digitalRead(14);
  byte right = digitalRead(18);
  if (left == 1) {
    CoDrone.FlightEvent(Stop);
  }
  else if (right == 1) {
    CoDrone.FlightEvent(TakeOff);
    THROTTLE = 100;
    CoDrone.Control();
    delay(2000);
    PITCH = 80;
    THROTTLE = 80;
    CoDrone.Control();
    delay(2000);
    ROLL = 80;
    THROTTLE = 80;
    CoDrone.Control();
    delay(2000);
    PITCH = -80;
    THROTTLE = 80;
    CoDrone.Control();
    delay(2000);
        ROLL = -80;
    THROTTLE = 80;
    CoDrone.Control();
    delay(2000);
    THROTTLE = 80;
  }
}
//   5. Create a byte array that holds your specific drone address

//   6. Connect to your drone using the address - HINT: It functions as an AddressInputDrone

// 2. Add the method that runs repeatedly once the program starts
//    7. Create a variable to hold each sensor value

//    HINT: You can name them left, middle, and right (despite being digital sensors 11, 14, and 18)

//    8. Check to see if the left sensor is triggered
//        10. Kill the drone - HINT: Stop the drone with a FlightEvent

//    9. If not, check to see if the right sensor is triggered
//        11. TakeOff

//        12. Go up with a speed of 100
//        Send the command - HINT: Use .Control()
//        Wait for one second - HINT: Use delay(____);

//        13. Go forward (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        14. Go right (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        15. Go back (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        16. Go left (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        17. Land

