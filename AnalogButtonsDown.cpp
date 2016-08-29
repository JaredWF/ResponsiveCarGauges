// 
// 
// 

#include "AnalogButtonsDown.h"

AnalogButtonsDown::AnalogButtonsDown(int pin, int buttonCount, int *analogValues, int tolerance)
{
	_pin = pin;
	_buttonCount = buttonCount;
	_analogValues = analogValues;
	_tolerance = tolerance;
}

int AnalogButtonsDown::GetButtonDown()
{
	int value = analogRead(_pin);
	int button = -1;

	if (lastValue == 0) {
		for (int i = 0; i < _buttonCount; i++) {
			if (abs(value - _analogValues[i]) <= _tolerance) {
				button = i;
				break;
			}
		}
	}

	lastValue = value;
	return button;
}
