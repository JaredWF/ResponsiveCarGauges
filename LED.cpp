// 
// 
// 

#include "LED.h"

LED::LED(int pin)
{
	_pin = pin;
	pinMode(pin, OUTPUT);
}

void LED::on()
{
	digitalWrite(_pin, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void LED::off()
{
	digitalWrite(_pin, LOW);    // turn the LED off by making the voltage LOW
}
