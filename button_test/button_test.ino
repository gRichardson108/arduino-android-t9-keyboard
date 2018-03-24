/*
  Sends a keyboard message per button press to the Android device.


  The circuit:
   pushbutton attached to pin 2-11 from +5V
   10K resistor attached to pin 2-11 from ground

  created 2018
  by grichardson108 <http://www.github.com/gRichardson108>

*/
#include <stdio.h>
#include <string.h>
#include "PinChangeInt.h"

typedef struct ButtonState {
  int pin_number;
  volatile int previous_state;
  volatile int current_state;
  void (*isrFunc)();
} ButtonState;

#define BUTTON_COUNT 3
#define BUFFER_SIZE 20
ButtonState buttons[BUTTON_COUNT];
const int BUTTON_PINS[] = {2, 3, 4}; //, 5, 6, 7, 8, 9, 10, 11}; // the number of the pushbutton pin
char buffer[BUFFER_SIZE] = "\0";

void button_1(){
  Serial.write("1,");
}

void button_2(){
  Serial.write("2,");
}

void button_3(){
  Serial.write("3,");
}

void setup() {
  buttons[0].isrFunc = &button_1;
  buttons[1].isrFunc = &button_2;
  buttons[2].isrFunc = &button_3;
  
  // initialize the pushbuttons as an input:
  for (int i = 0; i < BUTTON_COUNT; i++) {
    buttons[i].pin_number = BUTTON_PINS[i];
    buttons[i].previous_state = LOW;
    buttons[i].current_state = LOW;
    attachPinChangeInterrupt(buttons[i].pin_number, *buttons[i].isrFunc, RISING);
  }
  Serial.begin(115200);
}

void loop() {
}
