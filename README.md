# OpenKeyer
## Overview
OpenKeyer is an open source, open hardware, modular morse code keyer, built around an Arduino Nano, or compatible, microcontroller. The modular nature of OpenKeyer allows the builder to easily configure his/her OpenKeyer build to suit their needs/desires.

## Modules
The core module and the only required one, is the microcontroller (MCU), all of the other modules connect to the MCU and are controlled by it.

The other modules are:
- Display: This allows easy access to the menu(s), and shows the current code speed
- Twin-T Oscillator: Creates a pure sine wave, which is fed into an audio amplifier, the resulting sound is then played through the onboard speaker, an external speaker or a set of headphones.
- LED Indicator: Provides a visual indication of the code elements being sent
- Battery Module: Provides power to the keyer through the use of batteries, allowing the keyer to be more portable