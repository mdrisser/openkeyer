#include <Arduino.h>

/*****
 * DEFINES
 *****/
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
#define DIT 100
#define DAH DIT*3
#define INTRACHAR DIT
#define PARIS DIT*43

#define DEBUG 1
#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#endif


/*****
 * CONSTANTS
 *****/
int ditPin = 5;     // The pin that the ring of the phono plug is connected to
int dahPin = 6;     // The pin that the tip of the phono plug is connected to
int sigOut = 12;    // Signal output, to oscillator and/or visual indicator


/*****
 * VARIABLES
 *****/



/*****
 * FUNCTIONS
 *****/

/* Sends a dit */
void sendDit() {
    digitalWrite(sigOut, DIT);
    delay(DIT);
}


/* Sends a dah */
void sendDah() {
    digitalWrite(sigOut, DAH);
    delay(DIT);
}


/* Code to be run once, at startup */
void setup() {
    // If we have debugging turned on, initalize the Serial Monitor
    if(DEBUG) {
        Serial.begin(115200);
    }

    /* Setup the interupts for the paddle/key input
     * We don't want to, and shouldn't, wait for the loop to come back
     * around, so we need to deal with input from the paddles/key as
     * soon as it happens.
     */
    pinMode(ditPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(ditPin), sendDit, CHANGE);
    pinMode(dahPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(dahPin), sendDah, CHANGE);
}


/* Code to be run repeatedly, main loop */
void loop() {

}