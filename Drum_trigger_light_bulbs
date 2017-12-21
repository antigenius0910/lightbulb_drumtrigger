/* Drum_trigger_light_bulbs

   This sketch reads a piezo element to detect a knocking sound.
   It reads an analog pin and compares the result to a set threshold.
   If the result is greater than the threshold, it writes
   "light switch on!" to the serial port, and toggles the LED on pin 13.

   First function active when piezo got hit.
 
   Second function send singnal to 120V power relay and lit up two light bulbs in real time.     

   created 25 June 2017
   by Yen Chuang <https://github.com/antigenius0910>
   This code is in the public domain, feel free to use it.

 */


// these constants won't change:
const int ledPin = 13;      // led connected to digital pin 13 (for Piano loop)
const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 180;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light
boolean lightswitchstate = 0;

void setup() {
  pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  pinMode(7,INPUT); //SIG of the Parallax Sound Impact Sensor connected to Digital Pin 7
  pinMode(9, OUTPUT); //OUTPUT to LED for soundimpact sensor
  analogWrite(9, 0); //lightblub1 initial state on
  analogWrite(11, 0); //lightblub2 inital state on
  Serial.begin(9600);       // use the serial port
}


void loop() {

  //boolean lightswitchstate = 0;

  if (lightswitchstate == 1) {
        knock(); 
        soundimpact();
        //Serial.println("light switch on!");
        //Serial.println(lightswitchstate);
     }
  
  else{
       knock();
       //Serial.println("light switch off!");
       //Serial.println(lightswitchstate); 
        analogWrite(9, 0); //lightblub1 initial state off
        analogWrite(11, 0); //lightblub2 inital state off
  }

}


void knock() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);

  static unsigned long lastTime2 = 0;
  const long interval2 = 2000;
  static bool state2 = 0;

  unsigned long now2 = millis();

  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
    // toggle the status of the ledPin:

    ///////delay(1000);
    if ( now2 - lastTime2 > interval2 && state2 == 0) {
    state2 = 1;
    lastTime2 = now2;
    //digitalWrite(ledPin, LOW);
    //Serial.println(now2);
    lightswitchstate =! lightswitchstate;
    
  }

  if ( now2 - lastTime2 > interval2 && state2 == 1) {
    state2 = 0;
    lastTime2 = now2;
    //digitalWrite(ledPin, LOW);
    lightswitchstate =! lightswitchstate;    
  }
    
    // send the string "Knock!" back to the computer, followed by newline
    //Serial.println("Knock!");
    Serial.println(sensorReading);
  }
}


//volume sencor
//define LEDstrip 9 & 11
//this function will make the lightbulbs dim once the Parallax Sound Impact Sensor sends a 1 signal, and then return to it’s original brightness.

void soundimpact()
{
  boolean soundstate = digitalRead(7);
  if (soundstate == 1) {
         analogWrite(9, 0);
         analogWrite(11, 0);
  }
  else{
  
    analogWrite(9,255);
    analogWrite(11, 255);
  }
}
