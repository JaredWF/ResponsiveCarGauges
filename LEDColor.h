// LEDColor.h

#ifndef _LEDCOLOR_h
#define _LEDCOLOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	class LEDColor 
	{
		public: 
			LEDColor();
			LEDColor(uint8_t r, uint8_t g, uint8_t b);
			uint32_t GetCombinedColor();
			uint8_t _r;
			uint8_t _g;
			uint8_t _b;
	};
#else
	#include "WProgram.h"
#endif


#endif

