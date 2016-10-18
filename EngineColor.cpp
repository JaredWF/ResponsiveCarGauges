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
	_previousCount = 0;
	_previousColor = minColor.GetCombinedColor();
}

uint32_t EngineColor::GetColor(int loopCounter)
{
	if (loopCounter == _previousCount) {
		return _previousColor;
	}

	_previousCount = loopCounter;

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
	case ENGINE_TEMP:
		status = _obd->coolantTemperature(value);
		break;
	case ENGINE_LOAD:
		status = _obd->engineLoad(temp);
		value = (int)temp;
		break;
	case THROTTLE:
		status = _obd->throttlePosition(temp);
		value = (int)temp;
		break;
	}


	if (status == ELM_SUCCESS) {
		_previousColor = _interpolater->CalculateColorSlerp(value);
		return _previousColor;
	}
	else {
		return _previousColor;
	}
}
