# Drum_trigger_light_bulbs

   See it in action

https://github.com/user-attachments/assets/636e20eb-7e4b-4cda-b489-996dc47fb586
   
   Ride with buzzer underneath acting as a trigger controlling volume sensor on or off. Volume sensor then trigger 120v power relay to lit   up the light bulbs
   
   This sketch reads a piezo element to detect a knocking sound.
   It reads an analog pin and compares the result to a set threshold.
   If the result is greater than the threshold, it writes
   "light switch on!" to the serial port, and toggles the LED on pin 13.

   1. First function active when piezo got hit.
   2. Second function send singnal to 120V power relay and lit up two light bulbs in real time.     

   created 25 June 2017
   by Yen Chuang <https://github.com/antigenius0910>
   This code is in the public domain, feel free to use it.
