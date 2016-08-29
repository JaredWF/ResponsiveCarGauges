// AnalogButtonsDown.h

#ifndef _ANALOGBUTTONSDOWN_h
#define _ANALOGBUTTONSDOWN_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class AnalogButtonsDown
{
public:
	AnalogButtonsDown(int pin, int buttonCount, int* analogValues, int tolerance);
	int GetButtonDown(); //returns only when the button is first pressed, not held. Returns -1 for no button.

private:
	int _pin;
	int _buttonCount;
	int* _analogValues;
	int _tolerance;
	int lastValue;
};


#endif

