/* TeensyMouseJiggler
 *  Luke Miller 2019
 *  
 *  Code implemented on a Teensy 3.0 to "jiggle" the mouse cursor
 *  every once in a while (moveInterval) for a set amount of hours (runTimeMillis)
 *  Once the designated number of hours have elapsed, you will need to manually
 *  hit the reset button on the Teensy to restart the timer. 
 *  
 *  
 */

#define myLED 13

unsigned long runTimeMillis = 4 * 60 * 60 * 1000; // Number of hours to run this routine (hit reset button on Teensy to restart)
unsigned int moveInterval = 60 * 1000; // Number of milliseconds between mouse movements
unsigned int currentMillis; 

void setup() {
  currentMillis = millis(); // initialize currentMillis
  pinMode(myLED, OUTPUT);
  digitalWrite(myLED, LOW);

  // Flash the LED to notify the user that the cycle is starting
  for (int i = 0; i < 5; i++){
    digitalWrite(myLED, HIGH);
    delay(20);
    digitalWrite(myLED, LOW);
    delay(100);
  }
  } 
void loop() {
  while (millis() < runTimeMillis){
    if ( (millis() - currentMillis) > moveInterval) {
      Mouse.move(0,1); // move it
      delay(10);
      Mouse.move(0,-1); // move it back    
      currentMillis = millis(); // update currentMillis
      digitalWrite(myLED, HIGH);
      delay(15);
      digitalWrite(myLED, LOW);
    }
  } // end of while loop, reset to restart everything
}
