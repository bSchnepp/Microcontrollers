# Microcontrollers
Attempting to build a simple USB game controller, similar to ones of
more recent game consoles.

Specifically, it must have at a minimum, the same number of user inputs
as a typical modern game controller, which means 4 primary buttons, A, B, X, and
Y, a directional pad with Up, Down, Left, and Right, two joysticks, and two
shoulder buttons per hand grip, of which one on each side is analog, for a
total of 4 shoulder buttons. In addition, there should be space left over
for additional buttons for "Home", "Select", "Start".

Maybe leave some code space on the Leonardo/Micro for the possibility of adding
in an FPGA and including a small touchscreen, or a third joystick, in order
to maximize compatibility with as many older controllers as possible. Naturally,
before any of that can happen, it would be worthwhile to actually read the USB
specification to ensure we can actually do that.

Unfortunately, I'm not aware of how to write C and upload it using the USB port
to the onboard microcontroller, but this is something I'd like to do at some
point, even though the firmware for the Arduino is very small and takes up
very little code memory, that additional room could be used for more I/O, or
using one of the spare digital pins to handle a bitstream so an FPGA
could be attached to handle a touchscreen or something similar, as 
there wouldn't be enough analog ports without resorting to dangerous hackery
with multiplexing the shoulder buttons or something.

## Requirements?
Naturally, you'll need the Joystick library, 
[which is available here:](https://github.com/MHeironimus/ArduinoJoystickLibrary)

Other than that, an identically configured Arduino Leonardo (or Micro), will
probably work with the same setup:

* Joystick 1 (upper left) connected to A0 and A1, with A0 as X-axis, and A1 as Y-axis
* Joystick 1 (upper left) switch connected to digital pin 2

* Joystick 2 (bottom right) connected to A2 and A3, with A2 as X-axis, and A3 as Y-axis
* Joystick 2 (bottom right) switch connected to digital pin 3

* Button A connected to digital pin 4
* Button B connected to digital pin 5
* Button X connected to digital pin 6
* Button Y connected to digital pin 7

* Button L1 (left shoulder top) connected to digital pin 8
* Button R1 (right shoulder top) connected to digital pin 9

* A force sensing resistor, L2, connected to analog pin A4
* A force sensing resistor, R2, connected to analog pin A5

* Button SELECT, connected to digital pin 10
* Button START, connected to digital pin 11
* Button HOME, connected to digital pin 12

and of course, properly using ground and output voltage pins on the Arduino.
For now, I don't have any plans for pins 1 or 0, which would be needed for
serial communications, nor for pin 13.
