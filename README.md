# Drum-Triggered Stage Lighting (Ride Cymbal Lightbulb Trigger)

<div align="center">

[![License](https://img.shields.io/badge/license-Public%20Domain-blue.svg)](LICENSE)
[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![Hardware](https://img.shields.io/badge/Hardware-Open%20Source-orange.svg)](HARDWARE.md)
[![GitHub Stars](https://img.shields.io/github/stars/antigenius0910/lightbulb_drumtrigger?style=social)](https://github.com/antigenius0910/lightbulb_drumtrigger/stargazers)
[![GitHub Forks](https://img.shields.io/github/forks/antigenius0910/lightbulb_drumtrigger?style=social)](https://github.com/antigenius0910/lightbulb_drumtrigger/network/members)

[![Code Size](https://img.shields.io/github/languages/code-size/antigenius0910/lightbulb_drumtrigger)](https://github.com/antigenius0910/lightbulb_drumtrigger)
[![Platform](https://img.shields.io/badge/platform-Arduino-lightgrey.svg)](https://www.arduino.cc/)
[![C++](https://img.shields.io/badge/language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](CONTRIBUTING.md)
[![Made with Love](https://img.shields.io/badge/Made%20with-❤-red.svg)](https://github.com/antigenius0910)

</div>

**Turn every cymbal hit into a light show.**

This project uses a piezo sensor mounted under a ride cymbal to detect hits and control a 120V power relay in real time, lighting up two household bulbs on every strong hit.

---

## Demo

**Live performance with the ride cymbal triggering the lights:**

<video src="https://github.com/user-attachments/assets/636e20eb-7e4b-4cda-b489-996dc47fb586" autoplay muted controls loop width="100%"></video>

*🔊 Click the unmute button (🔇) to hear the cymbal hits sync with the lights!*

---

## Motivation

I wanted a cheap, DIY way to sync drum hits with stage lights without buying an expensive commercial drum trigger + DMX lighting system.

**Goals:**

- Trigger real 120V bulbs directly from a cymbal
- Keep latency low enough to feel "instant"
- Use simple, hobby-friendly parts (Arduino + relay module)
- Add visual impact to live performances on a budget

---

## How It Works

**Signal path:**

1. **Piezo sensor** under ride cymbal converts vibration → voltage
2. **Arduino** reads analog input and compares to a threshold
3. When the threshold is exceeded:
   - Turn on digital output pin
   - Drive a 120V relay module
4. **Relay** closes the circuit to power two light bulbs

**Two-stage control:**

- **Stage 1 (Piezo):** Toggles the system on/off with 2-second debouncing
- **Stage 2 (Sound sensor):** Modulates light brightness based on volume

When you hit the ride cymbal hard enough, the piezo triggers the Arduino, which instantly activates the relay. The lights respond in real-time, creating a synchronized visual effect with your drumming.

---

## Features

- **Real-time drum detection** using piezo sensor technology
- **Sound-reactive lighting** with Parallax Sound Impact Sensor
- **Two-stage control system**:
  - Piezo sensor toggles the system on/off
  - Volume sensor controls light brightness dynamically
- **120V power relay** control for professional lighting
- **Debouncing logic** to prevent false triggers
- **Dual light bulb support** with independent PWM control
- **Serial monitoring** for debugging and threshold calibration

## 🔧 Hardware Requirements

📖 **For complete hardware documentation, assembly instructions, and wiring diagrams, see [HARDWARE.md](HARDWARE.md)**

### Bill of Materials (BOM)

| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Board (Uno/Nano) | 1 | Any Arduino with analog inputs |
| Piezo Element/Sensor | 1 | For drum hit detection |
| Parallax Sound Impact Sensor | 1 | For volume-based control |
| 120V Power Relay Module | 1 | ⚠️ Must be rated for AC loads |
| Light Bulbs (120V) | 2 | Incandescent or compatible |
| Resistors | As needed | For piezo sensor circuit |
| Jumper Wires | Multiple | Male-to-male and male-to-female |
| Breadboard or PCB | 1 | Optional for prototyping |
| Power Supply for Arduino | 1 | 5V USB or 7-12V DC |

### Pin Configuration

| Pin | Component | Type |
|-----|-----------|------|
| A0 | Piezo Sensor | Analog Input |
| 7 | Parallax Sound Impact Sensor (SIG) | Digital Input |
| 9 | Light Bulb 1 Control | PWM Output |
| 11 | Light Bulb 2 Control | PWM Output |
| 13 | Status LED | Digital Output |

## 📐 Circuit Diagram

> 🚧 **Note**: Circuit diagram will be added in future updates. Please refer to the pin configuration table above for wiring guidance.

**Basic Wiring Overview**:
1. Connect piezo sensor to analog pin A0 (with appropriate voltage divider if needed)
2. Connect Parallax Sound Impact Sensor signal pin to digital pin 7
3. Connect relay control pins to PWM pins 9 and 11
4. Connect 120V light bulbs through relay switches

⚠️ **SAFETY WARNING**: Working with 120V AC is dangerous. If you're not experienced with high-voltage circuits, please consult an electrician or use low-voltage alternatives (12V LEDs).

## 📋 Prerequisites

### Software
- [Arduino IDE](https://www.arduino.cc/en/software) 1.8.x or higher
- USB cable for Arduino programming

### Knowledge
- Basic Arduino programming
- Understanding of electrical circuits
- **Safety precautions for 120V AC wiring**

## 🚀 Installation

### 1. Hardware Setup

1. **Assemble the circuit** following the pin configuration table
2. **Mount the piezo sensor** under your drum or cymbal
3. **Position the sound sensor** near the drum set
4. **Connect the relay module** to control the light bulbs
5. **Double-check all connections** before powering on

⚠️ **Important**: Ensure the 120V relay wiring is done safely and all AC connections are properly insulated.

### 2. Software Setup

1. Clone this repository:
   ```sh
   git clone https://github.com/antigenius0910/lightbulb_drumtrigger.git
   cd lightbulb_drumtrigger
   ```

2. Open `Drum_trigger_light_bulbs.ino` in Arduino IDE

3. Connect your Arduino board via USB

4. Select your board and port:
   - **Tools** → **Board** → Select your Arduino model
   - **Tools** → **Port** → Select the correct COM/USB port

5. Upload the sketch:
   - Click **Upload** button or press `Ctrl+U` (Windows/Linux) / `Cmd+U` (Mac)

## 🎮 Usage

### Basic Operation

1. **Power on** the Arduino and ensure the relay module has power
2. **Hit the piezo-equipped drum** to toggle the system on/off
   - The system uses a 2-second interval debouncing
3. When **system is ON**:
   - Light bulbs respond to drum hits detected by the volume sensor
   - Lights dim momentarily when sound is detected, then return to full brightness
4. When **system is OFF**:
   - Light bulbs remain off regardless of sound input

### Calibration

The default threshold for drum hit detection is set to `180`. To adjust:

1. Open the Serial Monitor (`Tools` → `Serial Monitor` or `Ctrl+Shift+M`)
2. Set baud rate to **9600**
3. Hit your drum and observe the sensor readings
4. Adjust the `threshold` constant in the code:
   ```cpp
   const int threshold = 180;  // Modify this value
   ```
5. Re-upload the sketch after changes

**Tuning Tips**:
- Higher threshold = less sensitive (harder hits required)
- Lower threshold = more sensitive (softer hits trigger)
- Typical range: 100-300 depending on your setup

## Technical Implementation

### Stage 1: System Activation (Piezo Sensor)
- Reads analog input from piezo sensor on pin A0
- Compares reading against threshold (default: 180)
- Toggles system state with 2-second debouncing to prevent rapid switching
- State is stored in `lightswitchstate` boolean variable

### Stage 2: Light Control (Sound Impact Sensor)
- When system is active, reads digital signal from Parallax sensor
- **Sound detected (HIGH)**: Dims lights to 0 (off)
- **No sound (LOW)**: Sets lights to full brightness (255)
- Uses PWM on pins 9 and 11 for smooth dimming control

### Key Technical Details
- **Debouncing**: Prevents false triggers using `millis()` timing instead of `delay()`
- **Non-blocking code**: Main loop runs continuously without delays
- **PWM Control**: `analogWrite()` provides 0-255 brightness levels
- **Serial debugging**: Outputs sensor readings for calibration

## 🗺️ Roadmap

- [ ] Add detailed circuit schematic diagram
- [ ] Create Fritzing diagram for easy replication
- [ ] Add photos of completed project setup
- [ ] Implement adjustable sensitivity via potentiometer
- [ ] Add MIDI trigger capability
- [ ] Support for more light channels
- [ ] Web interface for wireless control
- [ ] Add audio sync visualization modes

## 🤝 Contributing

Contributions are welcome! This is a public domain project, so feel free to fork, modify, and improve.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

See [CONTRIBUTING.md](CONTRIBUTING.md) for more details.

## 📄 License

This project is in the **public domain**. You are free to use, modify, and distribute this code for any purpose without restriction.

See the [LICENSE](LICENSE) file for details.

## 👤 Author

**Yen Chuang**
- GitHub: [@antigenius0910](https://github.com/antigenius0910)
- Project Link: [https://github.com/antigenius0910/lightbulb_drumtrigger](https://github.com/antigenius0910/lightbulb_drumtrigger)

## 🙏 Acknowledgments

- Arduino community for excellent documentation and libraries
- Parallax Inc. for the Sound Impact Sensor
- Inspiration from interactive art installations and music visualization projects
- Created: June 25, 2017

---

⚡ **Made with ❤️ and Arduino** | ⭐ Star this repo if you found it helpful!
