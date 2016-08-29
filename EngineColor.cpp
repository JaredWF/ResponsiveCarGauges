// 
// 
// 

#include "EngineColor.h"
#include "ColorInterpolater.h"
#include "LEDColor.h"

EngineColor::EngineColor(COBD *obd, byte pid, String name, LEDColor minColor, LEDColor maxColor, int minValue, int maxValue)
{
	_obd = obd;
	_pid = pid;
	_name = name;
	_interpolater = new ColorInterpolater(minColor, maxColor, minValue, maxValue);
}

uint32_t EngineColor::GetColor()
{
	int result;
	if (_obd->readPID(_pid, result)) {
		return _interpolater->CalculateColor(result);
	}
	else {
		return _interpolater->_minColor.GetCombinedColor();
	}
}
