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
#include "ELM327.h"

enum PID { RPM, SPEED, ENGINE_TEMP, ENGINE_LOAD, THROTTLE };

class EngineColor : public GaugeColor
{
public:
	
	EngineColor(Elm327 *obd, PID pid, String name, LEDColor minColor, LEDColor maxColor, int minValue, int maxValue);
	uint32_t GetColor(int loopCounter);
private:
	Elm327 *_obd;
	PID _pid;
	ColorInterpolater *_interpolater;
	int _previousCount;
	uint32_t _previousColor;
};

#endif

