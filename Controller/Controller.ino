#include <Joystick.h>

const int JS1_SW = 2;
const int JS2_SW = 3;

const int JS1_AXISX = A0;
const int JS1_AXISY = A1;

const int JS2_AXISX = A2;
const int JS2_AXISY = A3;

const int BTN_A = 4;
const int BTN_B = 5;
const int BTN_X = 6;
const int BTN_Y = 7;

const int Deadzone = 16;

Joystick_ Joystick1(
	JOYSTICK_DEFAULT_REPORT_ID, 
	JOYSTICK_TYPE_GAMEPAD,
	1, 0,	/* It has one switch */
	true, true, false, /* Not a flight stick, so only XY plane. */
	false, false, false, false, false); /* None of the rest of this */



void setup() 
{
	/* This is the JS1 input */
	pinMode(JS1_SW, INPUT);

	/* JS2 NYI */

	/* These are ABXY, respectively. 
	 * I just use a pull-down resistor to save some
	 * sanity and avoid inverted logic, since these are pretty
	 * plentiful.
	 */
	pinMode(BTN_A, INPUT);
	pinMode(BTN_B, INPUT);
	pinMode(BTN_X, INPUT);
	pinMode(BTN_Y, INPUT);

	/* Alright, let's initialize the sole joystick I have for now. */
	Joystick1.begin();
	Joystick1.setXAxisRange(0, 1023);
	Joystick1.setYAxisRange(0, 1023);
}

/**
 * Reads in an analog pin, mapping it from a range -1 to 1.
 */
int RawReadAxis(int AnalogPin)
{
	int Reading = analogRead(AnalogPin);
	if (Reading < Deadzone)
	{
		return 0;
	}

	/* Wiki says to do this, to prevent noise on analog read */
	delay(1);

	return Reading;
}

/**
 * The main event loop, in which the inputs will be checked for
 * any current work to be done.
 * 
 * This shouldn't be confused with some sort of ISR handler, but
 * we'd do that sort of thing here with some function calls.
 */
void loop() 
{
	/* We might be better off manually unrolling. This ok? */

	/* read buttons twice as a lazy way to debounce */
	digitalRead(BTN_A);
	int BtnAState = digitalRead(BTN_A);

	digitalRead(BTN_B);
	int BtnBState = digitalRead(BTN_B);

	digitalRead(BTN_X);
	int BtnXState = digitalRead(BTN_X);

	digitalRead(BTN_Y);
	int BtnYState = digitalRead(BTN_Y);

	int JS1_X = RawReadAxis(JS1_AXISX);
	int JS1_Y = RawReadAxis(JS1_AXISY);

	if (JS1_X < Deadzone)
	{
		JS1_X = 0;
	}

	if (JS1_Y < Deadzone)
	{
		JS1_Y = 0;
	}

	Joystick1.setXAxis(JS1_X);
	Joystick1.setYAxis(JS1_Y);
	
}
