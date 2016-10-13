// 
// 
// 

#include "EngineColor.h"
#include "ColorInterpolater.h"
#include "LEDColor.h"

EngineColor::EngineColor(Elm327 *obd, PID pid, String name, LEDColor minColor, LEDColor maxColor, int minValue, int maxValue)
{
	_obd = obd;
	_pid = pid;
	_name = name;
	_interpolater = new ColorInterpolater(minColor, maxColor, minValue, maxValue);
}

uint32_t EngineColor::GetColor()
{
	int value = 0;
	byte status = 0;
	byte temp = 0;
	switch (_pid) {
	case RPM:
		status = _obd->engineRPM(value);
		break;
	case SPEED:
		status = _obd->vehicleSpeed(temp);
		value = (int)temp;
		break;
	case FUEL_LEVEL:
		status = _obd->fuelLevel(temp);
		value = (int)temp;
		break;
	case ENGINE_TEMP:
		status = _obd->coolantTemperature(value);
		break;
	}


	if (status == ELM_SUCCESS) {
		uint32_t color = _interpolater->CalculateColor(value);
		return color;
	}
	else {
		return _interpolater->_minColor.GetCombinedColor();
	}
}
