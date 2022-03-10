# OpenKeyer
## Overview
OpenKeyer is an open source, open hardware, modular morse code keyer, built around an Arduino Nano, or compatible, microcontroller. The modular nature of OpenKeyer allows the builder to easily configure his/her OpenKeyer build to suit their needs/desires.

## Modules
The core module and the only required one, is the microcontroller (MCU), all of the other modules connect to the MCU and are controlled by it.

The other modules are:
- Display: This allows easy access to the menu(s), and shows the current code speed. The display is listed as a module simply because there will be support for different display modules, depending on the builder's preference and/or budget. The display can be a 2 or 4 line LCD display, an OLED display or any other type of display provided that the proper code is written to support it. While it is listed as a module, it really should be considered a necessary part of the keyer due to its functionality.
- Twin-T Oscillator: Creates a pure sine wave, which is fed into an audio amplifier, the resulting sound is then played through the onboard speaker, an external speaker or a set of headphones.
- Square-wave oscillator: Uses a 555 timer to produce the tone. Not as pleasant to listen to as a sine wave oscillator, but I will be providing the schematics to incorporate it anyway.
- LED Indicator: Provides a visual indication of the code elements being sent.
- Battery Module: Provides power to the keyer through the use of batteries, allowing the keyer to be more portable.
- Memory: Will allow for storing and replaying morse code strings, such as call sign, SKCC/FISTS/NAQCC number, etc.
