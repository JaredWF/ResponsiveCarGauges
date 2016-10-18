// 
// 
// 

#include "ColorInterpolater.h"
//#include <Adafruit_NeoPixel.h>
#include "LEDColor.h"

ColorInterpolater::ColorInterpolater(uint8_t minR, uint8_t minG, uint8_t minB, uint8_t maxR, uint8_t maxG, uint8_t maxB, int minValue, int maxValue)
{
	_minColor = LEDColor(minR, minG, minB);
	_maxColor = LEDColor(maxR, maxG, maxB);
	_minValue = minValue;
	_maxValue = maxValue;
}

ColorInterpolater::ColorInterpolater(LEDColor minColor, LEDColor maxColor, int minValue, int maxValue)
{
	_minColor = minColor;
	_maxColor = maxColor;
	_minValue = minValue;
	_maxValue = maxValue;
}

uint32_t ColorInterpolater::CalculateColor(int value)
{
	LEDColor resultColor = LEDColor(Interpolate(_minColor._r, _maxColor._r, value),
		Interpolate(_minColor._g, _maxColor._g, value),
		Interpolate(_minColor._b, _maxColor._b, value));
	return resultColor.GetCombinedColor();
}

uint32_t ColorInterpolater::CalculateColorSlerp(int value)
{
	LEDColor resultColor = LEDColor(Slerp(_minColor._r, _maxColor._r, value),
		Slerp(_minColor._g, _maxColor._g, value),
		Slerp(_minColor._b, _maxColor._b, value));
	return resultColor.GetCombinedColor();
}

int ColorInterpolater::Clamp(int value)
{
	if (value < _minValue) return _minValue;
	else if (value > _maxValue) return _maxValue;
	else return value;
}

uint8_t ColorInterpolater::Interpolate(uint8_t min, uint8_t max, int value)
{
	value = Clamp(value);
	return (uint8_t)((max - min) * ((float)(value - _minValue) / (_maxValue - _minValue)) + min);
}

uint8_t ColorInterpolater::Slerp(uint8_t min, uint8_t max, int value)
{
	value = Clamp(value);
	int range = _maxValue - _minValue;
	float theta = (value - _minValue) / (float)range * 3.1415 / 2;
	return (int)(sin(theta) * (max - min)) + min;
}


