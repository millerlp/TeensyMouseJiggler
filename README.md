# TeensyMouseJiggler

As simple as it sounds. This program, uploaded to a Teensy 3.0+, set to act as a USB Keyboard+Mouse+Joystick,
will move the mouse cursor back and forth one pixel, once a minute, for a total of 4 hours.  Ideally the small movement (one pixel up, one pixel back down) will not
interfere with normal user actions. After the run time elapses the board needs to be reset to restart the cycle. Optionally, a pushbutton can be soldered into pins 1 and ground, and used to reset the 4 hour timer. 

The onboard LED will flash briefly after each movement while the program is running, and will flash ten times on reboot or when the 4 hour timer is reset with a pushbutton.

![Teensy Image](/images/Teensy_MouseJiggler.jpg)
 
