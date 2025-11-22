# Contributing to Drum-Triggered Stage Lighting

Thank you for your interest in contributing to this project! 🥁💡

This document provides guidelines for contributing code, hardware designs, documentation, and ideas. Whether you're fixing a bug, adding a feature, or improving documentation, your contribution is welcome!

---

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [Ways to Contribute](#ways-to-contribute)
- [Getting Started](#getting-started)
- [Development Setup](#development-setup)
- [Contributing Code](#contributing-code)
- [Contributing Hardware Designs](#contributing-hardware-designs)
- [Contributing Documentation](#contributing-documentation)
- [Code Style Guidelines](#code-style-guidelines)
- [Testing Guidelines](#testing-guidelines)
- [Submitting Changes](#submitting-changes)
- [Safety Guidelines](#safety-guidelines)
- [Community](#community)

---

## Code of Conduct

This project is released with a simple code of conduct:

- **Be respectful** - Treat everyone with respect and kindness
- **Be constructive** - Provide helpful feedback and suggestions
- **Be safe** - Always prioritize safety, especially with 120V AC
- **Be open** - Share your knowledge and learn from others
- **Be patient** - Remember everyone has different skill levels

---

## Ways to Contribute

There are many ways to contribute to this project:

### 🐛 Report Bugs
Found a bug? [Open an issue](https://github.com/antigenius0910/lightbulb_drumtrigger/issues/new?template=bug_report.md) using the bug report template.

### 💡 Suggest Features
Have an idea for improvement? [Request a feature](https://github.com/antigenius0910/lightbulb_drumtrigger/issues/new?template=feature_request.md).

### 📝 Improve Documentation
- Fix typos or clarify instructions
- Add more detailed explanations
- Create video tutorials
- Translate documentation to other languages

### 🔧 Hardware Improvements
- Design better mounting solutions
- Create circuit diagrams or Fritzing files
- Test with different Arduino boards or sensors
- Share safer 12V LED alternatives

### 💻 Code Contributions
- Fix bugs or optimize code
- Add new features (MIDI support, WiFi control, etc.)
- Improve error handling
- Add unit tests

### 📸 Share Your Build
- Post photos or videos of your setup
- Share performance footage
- Write blog posts about your experience
- Share on social media with `#DrumTriggerLights`

---

## Getting Started

### Prerequisites

Before contributing, make sure you have:

- **Arduino IDE** 1.8.x or higher ([Download](https://www.arduino.cc/en/software))
- **Git** for version control ([Download](https://git-scm.com/))
- **GitHub account** ([Sign up](https://github.com/join))
- **Text editor** (Arduino IDE, VS Code, or your preferred editor)

### Optional Tools

- **Fritzing** - For creating circuit diagrams
- **Serial Monitor** - For debugging (included in Arduino IDE)
- **Multimeter** - For testing hardware

---

## Development Setup

### 1. Fork the Repository

Click the "Fork" button at the top of this repository to create your own copy.

### 2. Clone Your Fork

```bash
git clone https://github.com/YOUR-USERNAME/lightbulb_drumtrigger.git
cd lightbulb_drumtrigger
```

### 3. Add Upstream Remote

```bash
git remote add upstream https://github.com/antigenius0910/lightbulb_drumtrigger.git
```

### 4. Create a Branch

```bash
git checkout -b feature/your-feature-name
```

**Branch naming conventions:**
- `feature/` - New features (e.g., `feature/add-midi-support`)
- `fix/` - Bug fixes (e.g., `fix/debounce-timing`)
- `docs/` - Documentation changes (e.g., `docs/improve-wiring-guide`)
- `hardware/` - Hardware improvements (e.g., `hardware/12v-led-design`)

### 5. Keep Your Fork Updated

```bash
git fetch upstream
git merge upstream/master
```

---

## Contributing Code

### Before You Code

1. **Check existing issues** - Someone might already be working on it
2. **Open an issue first** - Discuss your idea before investing time
3. **Keep changes focused** - One feature or fix per pull request
4. **Test thoroughly** - Verify your changes work with real hardware

### Making Changes

1. **Write clean code** - Follow the style guidelines below
2. **Add comments** - Explain complex logic and hardware interactions
3. **Update documentation** - Reflect your changes in README.md or HARDWARE.md
4. **Test on hardware** - If possible, test with actual Arduino and sensors

### Code Review Process

1. Submit a pull request
2. Maintainers will review your code
3. Address any feedback or requested changes
4. Once approved, your PR will be merged!

---

## Contributing Hardware Designs

### Hardware Contributions Welcome

- Circuit diagrams (Fritzing, KiCad, or hand-drawn)
- PCB designs
- 3D-printed enclosures or mounting brackets
- Safer 12V alternatives to 120V design
- Alternative sensor configurations
- Photos of working setups

### Hardware Documentation

When contributing hardware designs, please include:

1. **Bill of Materials (BOM)** - List all components with part numbers
2. **Wiring Diagram** - Clear connection instructions
3. **Photos** - Multiple angles of your build
4. **Testing Notes** - What worked, what didn't
5. **Safety Considerations** - Especially for high-voltage designs

### File Formats

- **Circuit diagrams**: `.fzz` (Fritzing), `.png`, `.svg`, `.pdf`
- **3D models**: `.stl`, `.step`, `.f3d` (Fusion 360)
- **Photos**: `.jpg`, `.png` (high resolution preferred)
- **Videos**: Link to YouTube, Vimeo, or similar

---

## Contributing Documentation

### Documentation Needs

- Beginner-friendly tutorials
- Troubleshooting guides
- Video walkthroughs
- Translation to other languages
- Better explanations of complex topics

### Documentation Standards

- **Clear and concise** - Explain as if teaching a beginner
- **Include examples** - Show, don't just tell
- **Add visuals** - Photos, diagrams, screenshots help immensely
- **Test instructions** - Follow your own guide to ensure it works
- **Check spelling/grammar** - Use a spell checker

---

## Code Style Guidelines

### Arduino/C++ Code

Follow these conventions to maintain consistency:

#### Indentation and Formatting
```cpp
// Use 2 spaces for indentation (no tabs)
void functionName() {
  if (condition) {
    doSomething();
  }
}
```

#### Naming Conventions
```cpp
// Constants: camelCase with descriptive names
const int knockSensor = A0;
const int threshold = 180;

// Variables: camelCase
int sensorReading = 0;
boolean systemEnabled = false;

// Functions: camelCase, descriptive verb-noun pairs
void checkCymbalHit() { }
void updateLightsFromSound() { }
```

#### Comments
```cpp
// Single-line comments for brief explanations
int value = 0;  // Inline comments when needed

/*
 * Multi-line comments for function documentation
 * Include: purpose, parameters, return values
 */
void myFunction() {
  // Explain complex logic
  // One comment per logical block
}
```

#### Function Documentation
```cpp
//==============================================================================
// FUNCTION: functionName()
//
// PURPOSE:
// Clear description of what this function does
//
// PARAMETERS:
// - param1: description
// - param2: description
//
// RETURNS: description of return value
//==============================================================================
```

#### Constants and Magic Numbers
```cpp
// Good: Named constants
const int debounceInterval = 2000;

// Bad: Magic numbers
delay(2000);  // What is 2000? Why 2000?
```

### Code Organization

Structure your code in this order:

1. **Header comment** - Project description, hardware, author
2. **Pin definitions** - All pin constants grouped together
3. **Configuration parameters** - Adjustable settings
4. **Global variables** - Minimize use of globals
5. **setup()** - Initialization code
6. **loop()** - Main program loop
7. **Helper functions** - Supporting functions with documentation

### Example

See `Drum_trigger_light_bulbs.ino` for a well-documented example following all these conventions.

---

## Testing Guidelines

### Before Submitting

Test your changes thoroughly:

#### Software Testing
- [ ] Code compiles without errors or warnings
- [ ] No new compiler warnings introduced
- [ ] Serial Monitor output is correct
- [ ] Threshold values work as expected
- [ ] Debouncing logic prevents false triggers

#### Hardware Testing (if applicable)
- [ ] Tested on Arduino Uno or Nano
- [ ] Piezo sensor responds correctly
- [ ] Sound sensor triggers properly
- [ ] Relay modules activate as expected
- [ ] No unexpected behavior or crashes
- [ ] System runs stable for extended period (10+ minutes)

#### Safety Testing (for 120V changes)
- [ ] All AC connections are properly insulated
- [ ] Relay is rated for AC loads
- [ ] No exposed high-voltage conductors
- [ ] Tested with circuit breaker nearby
- [ ] Have first aid/emergency plan ready

### Test Report Template

When submitting hardware-related PRs, include a test report:

```markdown
## Test Report

**Hardware:**
- Arduino: Uno R3
- Piezo: 27mm disc sensor
- Relay: 2-channel 10A module
- Power: 9V DC adapter

**Test Results:**
- ✅ Piezo detection working (threshold: 180)
- ✅ Sound sensor triggering correctly
- ✅ Relays switching reliably
- ✅ No false triggers observed
- ✅ Ran for 30 minutes without issues

**Photos/Videos:**
[Link to test footage]
```

---

## Submitting Changes

### Pull Request Process

1. **Commit your changes** with clear commit messages:
   ```bash
   git add .
   git commit -m "feat: Add MIDI output support for drum triggers"
   ```

2. **Push to your fork**:
   ```bash
   git push origin feature/your-feature-name
   ```

3. **Open a Pull Request** on GitHub

4. **Fill out the PR template** completely

5. **Respond to feedback** from reviewers

### Commit Message Format

Use clear, descriptive commit messages:

**Format:**
```
<type>: <short description>

<optional longer description>
```

**Types:**
- `feat:` - New feature
- `fix:` - Bug fix
- `docs:` - Documentation changes
- `style:` - Code formatting (no functional changes)
- `refactor:` - Code restructuring
- `test:` - Adding or updating tests
- `hardware:` - Hardware design changes

**Examples:**
```bash
git commit -m "feat: Add support for ESP32 WiFi control"
git commit -m "fix: Correct debounce timing calculation"
git commit -m "docs: Update wiring diagram in HARDWARE.md"
git commit -m "hardware: Add Fritzing diagram for relay module"
```

### Pull Request Checklist

Before submitting, ensure:

- [ ] Code follows style guidelines
- [ ] Comments added to complex sections
- [ ] Documentation updated (README, HARDWARE.md)
- [ ] Tested on real hardware (if applicable)
- [ ] Commit messages are descriptive
- [ ] PR description explains what and why
- [ ] Related issue linked (if applicable)
- [ ] No merge conflicts with master branch

---

## Safety Guidelines

**⚠️ CRITICAL: This project involves 120V AC which can be LETHAL**

### For Contributors

When contributing code or hardware involving high voltage:

1. **Always include safety warnings** in documentation
2. **Test 120V changes personally** - Don't assume untested code is safe
3. **Document safety measures** - Explain what precautions to take
4. **Consider safer alternatives** - Suggest 12V options when possible
5. **Include emergency procedures** - What to do if something goes wrong

### Code Safety Requirements

- Validate all input values (prevent out-of-range relay control)
- Add failsafe modes (default to lights OFF on error)
- Include timeout mechanisms (prevent relays stuck ON)
- Document maximum load ratings in comments
- Test edge cases (what happens if sensor fails?)

### Hardware Safety Requirements

- All AC wiring must be in enclosures
- Use properly rated components (relay amperage, wire gauge)
- Include fuses or circuit breakers
- Provide clear safety warnings in documentation
- Show proper grounding and isolation

### If You're Unsure

**When in doubt, ask!** Open an issue to discuss safety concerns. Better to ask than to risk injury.

---

## Community

### Getting Help

- **GitHub Issues** - For bugs and feature requests
- **GitHub Discussions** - For questions and general chat (if enabled)
- **README.md** - Check documentation first

### Recognition

Contributors will be recognized in:
- Pull request acknowledgments
- Release notes (for significant contributions)
- Community shout-outs

### License

By contributing to this project, you agree that your contributions will be licensed under the same [Unlicense](LICENSE) (Public Domain) as the project.

This means:
- Your code becomes public domain
- Anyone can use it for any purpose
- No attribution required (though appreciated!)

---

## Questions?

If you have any questions about contributing:

1. Check existing issues and discussions
2. Read the documentation (README.md, HARDWARE.md)
3. Open an issue with the `question` label
4. Reach out to [@antigenius0910](https://github.com/antigenius0910)

---

## Thank You! 🎉

Every contribution, no matter how small, helps make this project better for everyone. Whether you're fixing a typo, adding a feature, or sharing your build photos, your contribution is valued!

**Happy contributing!** 🥁💡✨

---

*Last Updated: 2024-11-22*
