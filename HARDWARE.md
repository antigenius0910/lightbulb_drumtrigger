# Hardware Documentation

Complete hardware guide for building the Drum-Triggered Stage Lighting system.

---

## ⚠️ Safety First

**DANGER: This project involves 120V AC mains voltage, which can be LETHAL.**

- ⚡ **120V AC can kill you** - Do not proceed unless you have experience with high-voltage wiring
- 🔌 Always disconnect power before working on circuits
- 🧰 Use properly insulated tools and wear safety equipment
- ✅ Have your AC wiring inspected by a licensed electrician
- 💡 Consider using **12V LED strips** instead of 120V bulbs for a safer alternative

**If you're not comfortable with high-voltage wiring, STOP HERE and consult a professional.**

---

## 📦 Bill of Materials (BOM)

### Core Components

| Component | Specification | Quantity | Est. Price | Notes |
|-----------|---------------|----------|------------|-------|
| **Arduino Uno/Nano** | ATmega328P, 5V | 1 | $15-25 | Any Arduino with analog inputs works |
| **Piezo Disc Sensor** | 27mm or larger | 1 | $2-5 | Larger = more sensitive |
| **Parallax Sound Impact Sensor** | #29132 | 1 | $8-12 | [Parallax product page](https://www.parallax.com/product/sound-impact-sensor/) |
| **120V AC Relay Module** | 2-channel, 10A minimum | 1 | $8-15 | **Must be rated for AC loads** |
| **Resistor** | 1MΩ | 1 | $0.10 | For piezo sensor biasing |
| **Light Bulbs** | 120V incandescent | 2 | $5-10 | Max 10A combined |

### Supporting Components

| Component | Specification | Quantity | Notes |
|-----------|---------------|----------|-------|
| Jumper wires | Male-to-male, male-to-female | 10-15 | Various lengths |
| Breadboard | Half-size or larger | 1 | Optional for prototyping |
| USB cable | Type A to Type B/Mini/Micro | 1 | For Arduino programming |
| Power supply (Arduino) | 5V USB or 7-12V DC | 1 | USB works fine |
| Power supply (Relay) | 5V DC, 500mA minimum | 1 | May use Arduino 5V if relay draws <200mA |
| Extension cord | 120V AC | 1 | To be modified for relay control |
| Electrical tape | - | 1 roll | For insulation |
| Wire nuts | Suitable for 14-16 AWG | 4-6 | For AC connections |
| Project enclosure | - | 1 | Recommended for safety |

### Optional Components

| Component | Purpose |
|-----------|---------|
| 10kΩ potentiometer | Adjustable sensitivity without reprogramming |
| Status LEDs | Visual feedback for debugging |
| Screw terminals | More reliable connections than breadboard |
| Heat shrink tubing | Professional wire insulation |
| Drum mounting bracket | Secure piezo under cymbal |

---

## 🔌 Pin Configuration

### Arduino Pin Assignments

```
Arduino Uno/Nano
================

ANALOG INPUTS:
┌─────────────────────────────┐
│ A0  ← Piezo Sensor (signal) │
└─────────────────────────────┘

DIGITAL INPUTS:
┌─────────────────────────────┐
│ D7  ← Sound Impact Sensor   │
│       (SIG pin)             │
└─────────────────────────────┘

PWM OUTPUTS:
┌─────────────────────────────┐
│ D9  → Relay 1 Control       │
│ D11 → Relay 2 Control       │
│ D13 → Built-in LED (status) │
└─────────────────────────────┘

POWER:
┌─────────────────────────────┐
│ 5V  → Sensor power (VCC)    │
│ GND → Common ground          │
└─────────────────────────────┘
```

### Piezo Sensor Circuit

```
Piezo Disc Sensor Wiring:
========================

        Piezo
         Disc
    ┌────┴────┐
    │    +    │
    └────┬────┘
         │
         ├──────────────► A0 (Arduino)
         │
        ┌┴┐
        │ │ 1MΩ Resistor
        │ │ (pull-down)
        └┬┘
         │
        GND
```

**Why the resistor?**
- Provides stable reference voltage
- Prevents floating inputs
- Reduces noise and false triggers

### Relay Module Wiring

```
Relay Module (2-Channel)
========================

Control Side (Low Voltage):
┌──────────────────────┐
│ VCC  ← 5V (Arduino)  │
│ GND  ← GND           │
│ IN1  ← Pin 9         │
│ IN2  ← Pin 11        │
└──────────────────────┘

Power Side (HIGH VOLTAGE ⚡):
┌──────────────────────────────┐
│ COM1  ← Hot wire (120V)      │
│ NO1   → Bulb 1 hot wire      │
│ COM2  ← Hot wire (120V)      │
│ NO2   → Bulb 2 hot wire      │
└──────────────────────────────┘
```

**Relay Terminal Types:**
- **COM** (Common) - Input from power source
- **NO** (Normally Open) - Connects when relay is ON
- **NC** (Normally Closed) - Not used in this project

---

## 🔧 Assembly Instructions

### Step 1: Prepare the Piezo Sensor

1. **Solder wires to piezo disc:**
   - Red/positive wire to the brass disc
   - Black/ground wire to the white ceramic disc

2. **Add the pull-down resistor:**
   - Connect 1MΩ resistor between signal wire and ground
   - Can be done on breadboard or directly soldered

3. **Mount piezo under cymbal:**
   - Use adhesive foam or mounting bracket
   - Position under the bell or edge (test for best sensitivity)
   - Ensure wire has stress relief (won't pull off)

### Step 2: Wire the Sound Impact Sensor

1. **Connect Parallax Sound Impact Sensor:**
   ```
   Sensor    → Arduino
   ─────────────────────
   VCC (+)   → 5V
   GND (-)   → GND
   SIG       → Digital Pin 7
   ```

2. **Position the sensor:**
   - Place near the drum set (within 2-3 feet)
   - Point microphone toward drums
   - Avoid placing near speakers

### Step 3: Connect the Arduino to Relay

1. **Low-voltage relay connections:**
   ```
   Relay     → Arduino
   ─────────────────────
   VCC       → 5V
   GND       → GND
   IN1       → Pin 9 (PWM)
   IN2       → Pin 11 (PWM)
   ```

2. **Test the relay (optional):**
   - Upload the sketch (before wiring AC)
   - You should hear clicking when hitting the drums
   - Relay LED indicators should light up

### Step 4: Wire 120V Circuit (⚠️ DANGER ZONE)

**DISCONNECT ALL POWER BEFORE THIS STEP**

1. **Cut the extension cord:**
   - Cut the cord, exposing 3 wires: Hot (black), Neutral (white), Ground (green)

2. **Connect to relay module:**
   ```
   Wall Plug Side:
   ───────────────
   Hot (black)    → Relay COM1 & COM2
   Neutral (white) → Direct to bulbs
   Ground (green)  → Direct to bulbs

   Light Bulb Side:
   ────────────────
   Bulb 1 Hot     ← Relay NO1
   Bulb 2 Hot     ← Relay NO2
   Neutral        ← Direct from wall
   Ground         ← Direct from wall
   ```

3. **Insulate ALL connections:**
   - Use wire nuts for all AC connections
   - Wrap with electrical tape
   - Place in an enclosure (highly recommended)

### Step 5: Upload Arduino Sketch

1. Connect Arduino to computer via USB
2. Open `Drum_trigger_light_bulbs.ino` in Arduino IDE
3. Select board and port (Tools menu)
4. Click Upload
5. Wait for "Done uploading" message

### Step 6: Testing

1. **Low-voltage test (no AC connected):**
   - Power on Arduino
   - Hit the piezo sensor
   - Check Serial Monitor for readings
   - Relays should click

2. **High-voltage test (⚠️ CAUTION):**
   - Ensure all AC connections are insulated
   - Plug in the extension cord
   - Hit the ride cymbal
   - Lights should respond to hits

---

## 📐 Circuit Diagrams

### Simplified System Diagram

```
┌─────────────────────────────────────────────────────────┐
│                    DRUM TRIGGER SYSTEM                   │
└─────────────────────────────────────────────────────────┘

   Ride Cymbal              Drums (sound)
       │                         │
       ▼                         ▼
  ┌─────────┐             ┌─────────┐
  │ Piezo   │             │ Sound   │
  │ Sensor  │             │ Sensor  │
  └────┬────┘             └────┬────┘
       │                       │
       └───────┬───────────────┘
               │
               ▼
      ┌────────────────┐
      │   Arduino      │
      │   (Controller) │
      └────────┬───────┘
               │
               ▼
        ┌──────────┐
        │  Relay   │
        │  Module  │
        └─────┬────┘
              │
              ▼
    ┌──────────────────┐
    │   120V Light     │
    │   Bulbs (x2)     │
    └──────────────────┘
```

### Detailed Wiring Diagram

> 🚧 **Coming Soon**: Full Fritzing diagram will be added in future updates.
>
> For now, refer to the ASCII diagrams and pin configuration tables above.

---

## 🛠️ Troubleshooting

### Lights Don't Turn On

**Possible causes:**
- [ ] Check 120V power supply to relay
- [ ] Verify relay is clicking when triggered
- [ ] Test light bulbs separately (may be burned out)
- [ ] Check relay module rating (must handle bulb wattage)
- [ ] Verify relay IN pins connected to PWM pins 9 & 11

### Piezo Sensor Not Detecting Hits

**Possible causes:**
- [ ] Check serial monitor for readings (should show 0-1023)
- [ ] Adjust threshold value (line 22 in code)
- [ ] Verify piezo is securely mounted
- [ ] Check 1MΩ resistor connection
- [ ] Test piezo by tapping directly

### False Triggers / Too Sensitive

**Solutions:**
- [ ] Increase threshold value (try 200-300)
- [ ] Add foam damping under piezo
- [ ] Move sensor away from vibration sources
- [ ] Increase debouncing interval (line 67 in code)

### Sound Sensor Not Working

**Possible causes:**
- [ ] Check power (5V to VCC, GND to GND)
- [ ] Verify connection to pin 7
- [ ] Test sensor LED (should flash on loud sounds)
- [ ] Adjust sensor sensitivity knob (if available)

### Relay Stays On or Won't Turn Off

**Solutions:**
- [ ] Check code logic (lightswitchstate variable)
- [ ] Verify PWM values: 0 = off, 255 = on
- [ ] Test relay with different power source
- [ ] Replace relay module (may be defective)

---

## 📸 Project Photos

> 🚧 **Coming Soon**: Project build photos will be added.
>
> **Planned photos:**
> - Piezo sensor mounted under cymbal
> - Complete Arduino circuit on breadboard
> - Relay module wiring close-up
> - Finished project in enclosure
> - Setup in use at live performance

---

## 🔄 Upgrading & Modifications

### Safer Alternative: 12V LED System

Replace 120V bulbs with 12V LED strips for a much safer build:

- Use 12V relay modules instead of 120V
- Power from 12V DC power supply
- No risk of electrocution
- Brighter, more energy efficient
- More color options available

### Adding More Light Channels

The Arduino Uno has additional PWM pins:

- Pin 3, 5, 6, 10 can control more relays
- Add more bulbs/LED strips
- Different drum triggers for different lights

### MIDI Integration

Add MIDI output to trigger lights from electronic drums:

- Use Arduino MIDI library
- Connect via 5-pin DIN or USB MIDI
- Sync with DAW or drum module

### Wireless Control

Add WiFi/Bluetooth for remote control:

- Use ESP32 or ESP8266 instead of Arduino
- Control via smartphone app
- DMX output for professional lighting

---

## 📚 Additional Resources

### Datasheets & Documentation

- [Arduino Uno R3 Schematic](https://www.arduino.cc/en/uploads/Main/Arduino_Uno_Rev3-schematic.pdf)
- [Parallax Sound Impact Sensor Datasheet](https://www.parallax.com/product/sound-impact-sensor/)
- [Piezo Sensor Application Guide](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Knock)

### Tutorials

- [Arduino PWM Tutorial](https://www.arduino.cc/en/Tutorial/Foundations/PWM)
- [Working with Relays](https://www.arduino.cc/en/Tutorial/Foundations/Relay)
- [Piezo Sensor Basics](https://learn.adafruit.com/make-it-sense-piezo)

### Safety Resources

- [Electrical Safety Basics](https://www.osha.gov/electrical)
- [Working Safely with 120V AC](https://www.allaboutcircuits.com/textbook/direct-current/chpt-3/safe-practices/)

---

## ❓ Need Help?

- **Issues/Bugs**: [Open an issue](https://github.com/antigenius0910/lightbulb_drumtrigger/issues)
- **Questions**: [Start a discussion](https://github.com/antigenius0910/lightbulb_drumtrigger/discussions)
- **Safety concerns**: Consult a licensed electrician

---

**⚠️ Remember: Safety first! If you're unsure about anything involving 120V AC, seek professional help.**
