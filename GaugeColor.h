// GaugeColor.h

#ifndef _GAUGECOLOR_h
#define _GAUGECOLOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class GaugeColor 
{
	public:
		virtual uint32_t GetColor(int loopCounter)  = 0;
		String _name;
};

#endif

