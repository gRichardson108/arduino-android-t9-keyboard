# Arduino-Android T9 keyboard
This is an example implementation of a [T9 keyboard](https://en.wikipedia.org/wiki/T9_(predictive_text) for an android device, using an Arduino as the keyboard controller. While something of a technological step backwards, a T9 keyboard could be potentially useful as an accessibility add-on for modern smartphones, if well-integrated with a case that made the buttons more accessible than a software keyboard (especially people with deteriorated motor skills, less-sensitive fingers, etc).

This example was created to help CSUN's iCorp team demo their phone case. Ideally, the arduino would be eliminated and the logic brought into more suitable hardware for a portable smartphone case.

## Laying out a breadboard
See the example image `buttons_parallel.jpg` for a sample layout on a breadboard. I used cheap pushbuttons from amazon (Should run about $10 for a set with a bunch of colored buttons). You also need some 10 ohm resistors to act as pulldown resistors - the button layout is essentially the layout from the arduino tutorial, just extended to more buttons in parallel: see here [https://www.arduino.cc/en/Tutorial/Button](https://www.arduino.cc/en/Tutorial/Button).

## Installing software on the phone.

More to come soon.
