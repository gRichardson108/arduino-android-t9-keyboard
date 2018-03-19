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

typedef struct ButtonState {
  int pin_number;
  int previous_state;
  int current_state;
} ButtonState;

#define BUTTON_COUNT 10
#define BUFFER_SIZE 20
ButtonState buttons[BUTTON_COUNT];
const int BUTTON_PINS[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // the number of the pushbutton pin
char buffer[BUFFER_SIZE] = "\0";

void setup() {
  // initialize the pushbuttons as an input:
  for (int i = 0; i < BUTTON_COUNT; i++) {
    buttons[i].pin_number = BUTTON_PINS[i];
    buttons[i].previous_state = LOW;
    buttons[i].current_state = LOW;
    pinMode(buttons[i].pin_number, INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  //clear the current state of the buffer before reading/writing
  memset(buffer, '\0', BUFFER_SIZE * sizeof(char));
  // read the state of the pushbutton value:
  for (int i = 0; i < BUTTON_COUNT; i++) {
    buttons[i].current_state = digitalRead(buttons[i].pin_number);
    if (buttons[i].current_state == HIGH && buttons[i].previous_state == LOW) {
      itoa(buttons[i].pin_number, buffer, 10);
      Serial.write(buffer);
    }
    if (buttons[i].current_state == LOW && buttons[i].previous_state == HIGH) {
      itoa(buttons[i].pin_number, buffer, 10);
      Serial.write(buffer);
    }
    
    buttons[i].previous_state = buttons[i].current_state;
  }
}
