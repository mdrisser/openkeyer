#####
# IMPORTS
import time

from machine import Pin, I2C
from ssd1306 import SSD1306_I2C


#####
# "CONSTANTS", well, as close as we can get
# in Python
OKVER = "0.1a"
WIDTH = 128
HEIGHT = 96


#####
# GLOBAL VARIABLES
sig_out = Pin(GP22, Pin.OUT)
i2c = I2C(0)        # Initialize I2C using
                    # the I2C0 defaults
                    # SCL = Pin(GP9)
                    # SDA = Pin(GP8)
                    # freq = 400000
oled = SSD1306_I2C(WIDTH, HEIGHT, i2c)


#####
# FUNCTIONS
def initial_display():
    # Initial text to display
    oled.text("OPENKEYER V." + OKVER, 0, 0)
    oled.text("BY: KG6ECW", 0, 10)
    oled.show()
    
    # Wait 2 seconds
    time.sleep_ms(2000)     # Using time.sleep_ms() avoids
                            # possible incompatibilties
                            # with other microcontollers
    # Clear the display

def main():
    #|--REMOVE BEFORE FLIGHT-->
    # Show the I2C info on the console
    print("I2C Address: " + hex(i2c.scan()[0].upper()))
    print(" I2C Config: " + src(i2c))
    #<--REMOVE BEFORE FLIGHT--|
    
    initial_display()


#####
# RUNTIME
if __name__ == "__main__":
    main()