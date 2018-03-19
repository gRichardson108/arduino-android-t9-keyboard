/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */
#include <stdio.h>
#include <string.h>

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin[] = {2,3,4,5,6,7,8,9,10,11};     // the number of the pushbutton pin
const int BUTTON_COUNT = 10;
const int BUFFER_SIZE = 20;
char buffer[BUFFER_SIZE] = "\0";
//const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  
  // initialize the pushbutton pin as an input:
  for (int i = 0; i < BUTTON_COUNT; i++){
    pinMode(buttonPin[i], INPUT);
  }
}

void loop() {
  memset(buffer, '\0', BUFFER_SIZE*sizeof(char));
  // read the state of the pushbutton value:
  for (int i = 0; i < BUTTON_COUNT; i++){
    buttonState = digitalRead(buttonPin[i]);
    if (buttonState == HIGH) {
      // turn LED on:
      itoa(buttonPin[i], buffer, 10);
      Serial.write(buffer);
    }
  }
}
