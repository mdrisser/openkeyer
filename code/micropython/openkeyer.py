#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  openkeyer.py
#  
#  Copyright 2022  <pi@rpi-003>
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#
import micropython
import time

from machine import Pin, SoftI2C
from ssd1306 import SSD1306_I2C


#####
# "CONSTANTS"
OKVER = "0.1a"    # OpenKeyer Software Version
IN2 = 17          # Input Pin #2 (DIT)
IN1 = 16          # Input Pin #1 (DAH)
OUT = 15          # Output Pin
DIT = 275         # Length of time, in milliseconds, for a DIT

DAH = DIT * 3     # A DAH is three times the length of a DIT in properly
                  # timed morse code

#####
# VARIABLES
wpm = 0          # Words per Minute (Code Speed)


#####
# FUNCTIONS
def get_wpm(DIT, DAH):
    intrachar = DIT
    interchar = DAH
    paris = DIT + intrachar + DAH + intrachar + DAH + intrachar + DIT + interchar
    paris = paris + DIT + intrachar + DAH + interchar
    paris = paris + DIT + intrachar + DAH + intrachar + DIT +interchar
    paris = paris + DIT + intrachar + DIT + interchar
    paris = paris + DIT + intrachar + DIT + intrachar + DIT
    
    speed = round(60000 / paris, 0)
    return speed


def initialDisplay(speed):
    oled.text(f"OpenKeyer v.{OKVER}", 0, 0)
    
    oled.text("By: KG6ECW", 0, 10)
    
    oled.text("Initializing.....", 0, 20)
    oled.show()
    
    time.sleep_ms(2000)
    
    oled.fill(0)
    
    oled.text(f"WPM: {speed}", 0, 0)
    oled.show() 


#####
# INITIALIZATION
micropython.alloc_emergency_exception_buf(100)    # Error reporting for interupts

dit = Pin(IN2, Pin.IN)
dah = Pin(IN1, Pin.IN)
out = Pin(OUT, Pin.OUT)

i2c = SoftI2C(scl=Pin(1), sda=Pin(0), freq=100_000)
i2c.scan()

oled = SSD1306_I2C(128, 32, i2c)

wpm = get_wpm(DIT, DAH)

initialDisplay(wpm)