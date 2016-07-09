// 
// 
// 

#include "LEDColor.h"

LEDColor::LEDColor()
{
	_r = 0;
	_g = 0;
	_b = 0;
}

LEDColor::LEDColor(uint8_t r, uint8_t g, uint8_t b)
{
	_r = r;
	_g = g;
	_b = b;
}

uint32_t LEDColor::GetCombinedColor()
{
	return ((uint32_t)_r << 16) | ((uint32_t)_g << 8) | _b;
}
