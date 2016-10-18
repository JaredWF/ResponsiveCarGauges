// 
// 
// 

#include "SolidColor.h"

SolidColor::SolidColor(LEDColor color, String name)
{
	_color = color;
	_name = name;
}

uint32_t SolidColor::GetColor(int loopCounter)
{
	return _color.GetCombinedColor();
}
