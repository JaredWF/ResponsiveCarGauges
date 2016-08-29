// EngineColor.h

#ifndef _ENGINECOLOR_h
#define _ENGINECOLOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "GaugeColor.h"
#include "LEDColor.h"
#include "ColorInterpolater.h"
#include <OBD.h>
#include <Wire.h>

class EngineColor : public GaugeColor
{
public:
	
	EngineColor(COBD *obd, byte pid, String name, LEDColor minColor, LEDColor maxColor, int minValue, int maxValue);
	uint32_t GetColor();
private:
	COBD *_obd;
	byte _pid;
	ColorInterpolater *_interpolater;
};

#endif

