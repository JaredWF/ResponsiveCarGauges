// SolidColor.h

#ifndef _SOLIDCOLOR_h
#define _SOLIDCOLOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "GaugeColor.h"
#include "LEDColor.h"

class SolidColor: public GaugeColor 
{
	public:
		SolidColor(LEDColor color, String name);
		uint32_t GetColor(int loopCounter);
	private:
		LEDColor _color;
};

#endif

