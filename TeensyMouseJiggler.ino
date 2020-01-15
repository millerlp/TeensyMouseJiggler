/* TeensyMouseJiggler
 *  Luke Miller 2019
 *  
 *  Code implemented on a Teensy 3.0/3.1 to "jiggle" the mouse cursor
 *  every once in a while (moveInterval) for a set amount of hours (runTimeMillis)
 *  Once the designated number of hours have elapsed, you will need to manually
 *  hit the reset button on the Teensy to restart the timer. 
 *  A button can be wired between Teensy pin 1 and ground, in which case pressing
 *  the button will reset the timer, so that the program will now run
 *  for the number of elapsed hours stored in runTimeMillis from when you hit
 *  the button.
 *  When programming the Teensy, set the Tools>USB type option to "Keyboard + Mouse + Joystick"
 *  
 */

#define myLED 13  // Onboard LED on a Teensy
#define myButton 1  // User-installed pushbutton switch between Pin 1 and Ground.

unsigned long runTimeMillis = 4 * 60 * 60 * 1000; // Number of hours to run this routine (hit reset button on Teensy to restart)
unsigned int moveInterval = 60 * 1000; // Number of milliseconds between mouse movements
unsigned long currentMillis; 
unsigned long initialMillis;

void setup() {
  currentMillis = initialMillis = millis(); // initialize currentMillis
  pinMode(myLED, OUTPUT);
  pinMode(myButton, INPUT_PULLUP);
  digitalWrite(myLED, LOW);

  // Flash the LED to notify the user that the cycle is starting
  for (int i = 0; i < 10; i++){
    digitalWrite(myLED, HIGH);
    delay(20);
    digitalWrite(myLED, LOW);
    delay(100);
  }
  attachInterrupt(1, pin_ISR, LOW);
  } 
void loop() {
  while ( (unsigned long)(millis() - initialMillis) <= runTimeMillis){
    if ((millis() - currentMillis) > moveInterval) {
      Mouse.move(0,1); // move it
      delay(10);
      Mouse.move(0,-1); // move it back    
      currentMillis = millis(); // update currentMillis
      digitalWrite(myLED, HIGH);
      delay(15);
      digitalWrite(myLED, LOW);
    }
  } // end of while loop, hold here until reset
}

void pin_ISR(){
  // Reset initialMillis to extend run time.
  initialMillis = millis();
  // Flash the light to let the user know we've reset initialMillis
  for (int i = 0; i < 10; i++){
    digitalWrite(myLED, HIGH);
    delay(20);
    digitalWrite(myLED, LOW);
    delay(100);
  }
}
