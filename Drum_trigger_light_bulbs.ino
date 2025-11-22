/*******************************************************************************
 * Drum-Triggered Stage Lighting (Ride Cymbal Lightbulb Trigger)
 *
 * DESCRIPTION:
 * This Arduino sketch creates a drum-triggered lighting system using a piezo
 * sensor mounted under a ride cymbal and a Parallax Sound Impact Sensor. When
 * you hit the cymbal, it triggers 120V light bulbs via relay modules, creating
 * a synchronized visual effect with your drumming.
 *
 * HARDWARE:
 * - Arduino Uno/Nano
 * - Piezo disc sensor (connected to A0)
 * - Parallax Sound Impact Sensor #29132 (connected to pin 7)
 * - 2-channel 120V relay module (controlled by pins 9 & 11)
 * - Two 120V light bulbs
 *
 * HOW IT WORKS:
 * 1. Piezo sensor detects cymbal hits and toggles the system ON/OFF
 * 2. When system is ON, the sound sensor modulates light brightness
 * 3. Lights dim when sound is detected, then return to full brightness
 * 4. Built-in debouncing prevents false triggers
 *
 * SIGNAL FLOW:
 * Cymbal Hit → Piezo → Arduino (A0) → Toggle System State
 * Drum Sound → Sound Sensor → Arduino (D7) → Relay (D9/D11) → Lights
 *
 * Created: June 25, 2017
 * Author: Yen Chuang <https://github.com/antigenius0910>
 * License: Public Domain (Unlicense)
 *
 * Full documentation: https://github.com/antigenius0910/lightbulb_drumtrigger
 ******************************************************************************/

//==============================================================================
// PIN DEFINITIONS
//==============================================================================

const int ledPin = 13;          // Built-in LED for status indication
const int knockSensor = A0;     // Piezo sensor input (analog)
const int soundSensor = 7;      // Parallax Sound Impact Sensor (digital)
const int relay1Pin = 9;        // Relay 1 control (PWM) - Light bulb 1
const int relay2Pin = 11;       // Relay 2 control (PWM) - Light bulb 2

//==============================================================================
// CONFIGURATION PARAMETERS
//==============================================================================

const int threshold = 180;      // Piezo sensitivity threshold (0-1023)
                                 // Higher = less sensitive (harder hits required)
                                 // Lower = more sensitive (softer hits trigger)
                                 // Typical range: 100-300

const long debounceInterval = 2000;  // Debounce time in milliseconds
                                      // Prevents rapid toggling from multiple hits
                                      // 2000ms = 2 seconds between toggles

//==============================================================================
// GLOBAL VARIABLES
//==============================================================================

int sensorReading = 0;          // Current piezo sensor value (0-1023)
boolean systemEnabled = false;  // System ON/OFF state (toggled by cymbal hits)
                                 // false = lights off, true = lights reactive

//==============================================================================
// SETUP - Runs once at startup
//==============================================================================

void setup() {
  // Configure pin modes
  pinMode(ledPin, OUTPUT);       // Built-in LED for debugging
  pinMode(soundSensor, INPUT);   // Sound sensor digital input
  pinMode(relay1Pin, OUTPUT);    // Relay 1 output (PWM capable)
  pinMode(relay2Pin, OUTPUT);    // Relay 2 output (PWM capable)

  // Initialize relays to OFF state (0 = off for active-low relays)
  analogWrite(relay1Pin, 0);     // Light bulb 1 initially OFF
  analogWrite(relay2Pin, 0);     // Light bulb 2 initially OFF

  // Start serial communication for debugging
  Serial.begin(9600);
  Serial.println("Drum Trigger System Initialized");
  Serial.println("Hit the cymbal to toggle system ON/OFF");
  Serial.println("-------------------------------------------");
}

//==============================================================================
// MAIN LOOP - Runs continuously
//==============================================================================

void loop() {
  // Always check for cymbal hits (to toggle system on/off)
  checkCymbalHit();

  // Only run sound-reactive lighting when system is enabled
  if (systemEnabled) {
    updateLightsFromSound();
  }
  else {
    // System is OFF - ensure lights are off
    analogWrite(relay1Pin, 0);   // Turn off light bulb 1
    analogWrite(relay2Pin, 0);   // Turn off light bulb 2
  }
}

//==============================================================================
// FUNCTION: checkCymbalHit()
//
// PURPOSE:
// Reads the piezo sensor and toggles the system ON/OFF when cymbal is hit.
// Uses debouncing to prevent rapid toggling from vibrations or multiple hits.
//
// DEBOUNCING LOGIC:
// - Uses millis() for non-blocking timing (better than delay())
// - Requires 2-second interval between toggles (debounceInterval)
// - state2 tracks whether we're in "ready to toggle" or "cooldown" period
//
// PARAMETERS: None (reads global knockSensor pin)
// RETURNS: None (updates global systemEnabled variable)
//==============================================================================

void checkCymbalHit() {
  // Read current piezo sensor value (0-1023)
  sensorReading = analogRead(knockSensor);

  // Static variables retain values between function calls
  static unsigned long lastToggleTime = 0;  // Timestamp of last toggle
  static bool debounceState = false;        // Debounce state machine

  unsigned long currentTime = millis();     // Current timestamp

  // Check if piezo reading exceeds threshold (cymbal was hit)
  if (sensorReading >= threshold) {

    // DEBOUNCE STATE MACHINE
    // State 0: Ready to toggle (been more than debounceInterval since last toggle)
    if (currentTime - lastToggleTime > debounceInterval && debounceState == false) {
      debounceState = true;           // Enter cooldown state
      lastToggleTime = currentTime;   // Record toggle time
      systemEnabled = !systemEnabled; // Toggle system ON/OFF

      // Print status to serial monitor
      Serial.print("System toggled: ");
      Serial.println(systemEnabled ? "ON" : "OFF");
    }

    // State 1: Cooldown period (prevent immediate re-toggling)
    if (currentTime - lastToggleTime > debounceInterval && debounceState == true) {
      debounceState = false;          // Return to ready state
      lastToggleTime = currentTime;   // Reset timer
    }

    // Debug: Print sensor reading to help with threshold calibration
    Serial.print("Piezo reading: ");
    Serial.println(sensorReading);
  }
}

//==============================================================================
// FUNCTION: updateLightsFromSound()
//
// PURPOSE:
// Reads the Parallax Sound Impact Sensor and controls light brightness based
// on detected sound. Creates a "flash" effect where lights dim when sound is
// detected, then return to full brightness.
//
// BEHAVIOR:
// - Sound detected (HIGH) → Lights OFF (0)
// - No sound (LOW) → Lights ON at full brightness (255)
//
// This creates a dramatic "flicker" effect synchronized with drum hits.
//
// PARAMETERS: None (reads soundSensor pin)
// RETURNS: None (controls relay1Pin and relay2Pin)
//==============================================================================

void updateLightsFromSound() {
  // Read digital sound sensor state (HIGH = sound detected, LOW = quiet)
  boolean soundDetected = digitalRead(soundSensor);

  if (soundDetected == HIGH) {
    // Sound detected - turn lights OFF for dramatic flash effect
    analogWrite(relay1Pin, 0);    // Light bulb 1 OFF
    analogWrite(relay2Pin, 0);    // Light bulb 2 OFF
  }
  else {
    // No sound - lights at full brightness
    analogWrite(relay1Pin, 255);  // Light bulb 1 ON (full brightness)
    analogWrite(relay2Pin, 255);  // Light bulb 2 ON (full brightness)
  }
}

//==============================================================================
// CALIBRATION NOTES:
//==============================================================================
//
// THRESHOLD ADJUSTMENT:
// - Open Serial Monitor (Tools → Serial Monitor, 9600 baud)
// - Hit your cymbal and observe the piezo readings
// - Adjust 'threshold' constant (line 43) based on your readings
// - Typical values: 100-300 depending on piezo sensitivity and mounting
//
// DEBOUNCE INTERVAL:
// - Default: 2000ms (2 seconds) between toggles
// - Increase if system toggles too easily from vibrations
// - Decrease if you want faster response (minimum ~500ms recommended)
//
// LIGHT BEHAVIOR:
// - To invert behavior (lights ON when sound detected), swap the 0 and 255
//   values in the updateLightsFromSound() function (lines 152-154)
//
// PWM NOTES:
// - analogWrite() values: 0 = fully off, 255 = fully on
// - Intermediate values (e.g., 128) provide dimming if relay supports it
// - Most basic relay modules only support ON/OFF (0 or 255)
//
//==============================================================================
