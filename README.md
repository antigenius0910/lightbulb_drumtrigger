# Drum_trigger_light_bulbs

   See it in action
   1. https://www.facebook.com/yenkuang.chuang/videos/a.10213879098592069/10213879098712072/?type=3
   2. https://www.facebook.com/yenkuang.chuang/videos/vb.1246561742/10214486585338858/?type=3&theater
   
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
