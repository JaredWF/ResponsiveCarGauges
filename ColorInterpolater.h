// ColorInterpolater.h

#ifndef _COLORINTERPOLATER_h
#define _COLORINTERPOLATER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include "LEDColor.h"

	class ColorInterpolater
	{
	public:
		ColorInterpolater(uint8_t minR, uint8_t minG, uint8_t minB, uint8_t maxR, uint8_t maxG, uint8_t maxB, int minValue, int maxValue);
		ColorInterpolater(LEDColor minColor, LEDColor maxColor, int minValue, int maxValue);
		uint32_t CalculateColor(int value);
	private:
		int Clamp(int value);
		uint8_t Interpolate(uint8_t min, uint8_t max, int value);
		LEDColor _minColor;
		LEDColor _maxColor;
		int _minValue;
		int _maxValue;
	};
#else
	#include "WProgram.h"
#endif


#endif

