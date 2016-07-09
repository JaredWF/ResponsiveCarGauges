// LED.h

#ifndef _LED_h
#define _LED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	class LED
	{
	public:
		LED(int pin);
		void on();
		void off();
	private:
		int _pin;
	};
#else
	#include "WProgram.h"
#endif


#endif

