#include <Arduino.h>


/*****
 * DEFINES
 *****/

/* The following defines indicate whether or not we are using any of the various modules.
 * 1 = Module present
 * 0 = Module not present
 */
#define DISPLAY 1   // Any of the display modules, this MUST be 1 if using a display
/*#define DSPTYP  1   // 1 = 16x2 LCD Display (Serial)
                    // 2 = 20x4 LCD Display (Serial)
                    // 3 = 0.96" OLED (I2C)
                    // 4 = 16x2 LCD Display (I2C)
                    // 5 = 20x4 LCD Display (I2C)*/
#define OSC 0       // The twin-t oscillator module
#define VISUAL 0    // The visual indicator module
#define BATTERY 0   // The battery power module

/**
 * The following defines determine the timing of the generated sounds.
 * 
 * The DIT or dot, the short sound of Morse code, is one unit of time long.
 * The space between each sound in a Morse Code character, is also the same 
 * as a dit.
 * 
 * The DAH or dash, the long sound, is 3 units long or three times as long as
 * a dit.
 * 
 * The space between chracters is the length of a DAH, three times as long as
 * the spacing within each character.
 * 
 * The space between words is 7 units long, more than twice the space between
 * letters.
 * 
 * The word PARIS is used to determine words per minute, or sending speed. If
 * PARIS is sent 5 times in 1 minute, then the words per minute is 5 (5wpm).
 */
#define WPM 20          // Code speed in words per minute
#define DIT 1200/WPM    // Length of a "dit", in milliseconds
#define DAH DIT*3       // Length of a "dah", 3 times the length of a dit
#define INTRACHAR DIT   // Space between elements in a character
#define INTERSPACE DAH  // Space between characters in a word
#define WORDSPACE DIT*7 // Spacing between words
#define PARIS DIT*43    // Used to determine WPM (Words per Minute)
#define PITCH 500       // Tone pitch (frequency), in Herz, to use for the generated tone


/*
 * The following allows us to use the serial monitor for debugging, when necessary,
 * without affecting the system performance when not debugging.
 */
#define DEBUG 1
#if DEBUG == 1
    #define debug(x) Serial.print(x)
    #define debugln(x) Serial.println(x)
#endif


/*****
 * CONDITIONAL INCLUDES
 *****/
#if DISPLAY
    #include <LiquidCrystal.h>
#endif


/*****
 * CONSTANTS
 *****/
const String OKVER = "0.1a";    // The OpenKeyer version
const byte ditPin = 5;          // The pin that the ring of the phono plug is connected to
const byte dahPin = 6;          // The pin that the tip of the phono plug is connected to
const byte sigOut = 3;          // Signal output, to oscillator and/or visual indicator
const byte errInd = 4;          // The pin that the error indicator LED is connected to

#if DISPLAY
    // The pins that the LCD Display is connected to
    /*
    *    LCD PIN <--> ARDUINO PIN
    *        VSS <--> GND
    *        VCC <--> 5V
    *         V0 <--> 10k Pot <--> 3
    *         RS <--> 13
    *         RW <--> GND
    *         EN <--> 12
    *         D4 <--> 11
    *         D5 <--> 10
    *         D6 <--> 9
    *         D7 <--> 8
    *          A <--> 10K Pot <--> 5V
    *          K <--> GND
    */
    const byte rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
#endif


/*****
 * CLASS INSTANCES
 *****/
#if DISPLAY
    LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#endif


/*****
 * VARIABLES
 *****/



/*****
 * FUNCTIONS
 *****/

/**
 * @brief Blinks an LED that indicates an error has occurred
 * 
 * TODO: Figure out how to make this non-blocking
 */
void errorIndicator(String message) {
    if(DEBUG) {
        /* If we are in debug mode, print the error message */
        debugln(message);
    } else {
        /* If we aren't in debug mode, initialize the serial monitor
         * and print the message.
         */
        Serial.begin(115200);
        Serial.println(message);
    }

    /* Continually blink the LED indicating an error */
    while(true) {
        digitalWrite(errInd, HIGH);
        delay(500);
        digitalWrite(errInd, LOW);
        delay(500);
    }
}


/**
 * @brief Sends a 'dit' character element
 * 
 */
void dit() {
    // For debugging purposes
    debugln("dit");

    // Generate a tone for the dit
    tone(sigOut, PITCH, DIT);

    // We include a wait the length of one dit so that if
    // the user keeps the paddle contacts closed, like for
    // a series of dits, the appropriate spacing is included
    delay(DIT);
}


/**
 * @brief Sends a 'dah' character element
 * 
 */
void dah() {
    // For debugging purposes
    debugln("dah");

    // Generate a tone for the dah
    tone(sigOut, PITCH, DAH);

    // SEE COMMENT IN dit()
    delay(DIT);
}


/**
 * @brief Space between characters
 * 
 */
void interspace() {
    delay(INTERSPACE);
}

/**
 * @brief Space between words
 * 
 */
void wordspace() {
    delay(WORDSPACE);
}


/**
 * @brief Sends QRV (ready) followed by K; indicates that we are ready and it is OK to send
 * 
 */
void ready() {
    dah(); dah(); dit(); dah(); // Q
    interspace();
    dit(); dah(); dit();        // R
    interspace();
    dit(); dit(); dit(); dah(); // V
    wordspace();
    dah(); dit(); dah();        // K

    #if DISPLAY
        lcd.setCursor(0, 1);
        lcd.print("WPM: " + (String)WPM);
    #endif
}


/**
 * @brief Code to be run once, at startup
 * 
 */
void setup() {
    // If we have debugging turned on, initalize the Serial Monitor
    #if DEBUG
        Serial.begin(115200);
        debug("WPM: "); debugln(WPM);
        debug("DIT: "); debugln(DIT);
        debug("DAH: "); debugln(DAH);
        debug("INTRACHAR: "); debugln(INTRACHAR);
        debug("WORDSPACE: "); debugln(WORDSPACE);
        debug("PARIS: "); debugln(PARIS);
        debug("PITCH: "); debugln(PITCH);
    #endif

    debugln("Setting up error indicator LED...");
    pinMode(errInd, OUTPUT);

    /* Setup the interupts for the paddle/key input
     * We don't want to, and shouldn't, wait for the loop to come back
     * around, so we need to deal with input from the paddles/key as
     * soon as it happens.
     */
    debugln("Setting up interupts for the paddles/key...");
    pinMode(ditPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(ditPin), dit, CHANGE);

    pinMode(dahPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(dahPin), dah, CHANGE);

    debugln("Setting the pin to output the dits and dahs...");
    pinMode(sigOut, OUTPUT);

    /* Setup the display, if we are using one */
    #if DISPLAY
        debugln("Setting up the LCD display...");
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("OpenKeyer v." + OKVER);
    #endif

    ready();  // We're ready to go
}


/**
 * @brief Code to be run repeatedly, main loop
 * 
 */
void loop() {

}