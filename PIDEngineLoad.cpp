// 
// 
// 

#include "PIDEngineLoad.h"

PIDEngineLoad::PIDEngineLoad()
{
}

byte PIDEngineLoad::getMode() const
{
	return B1;
}

byte PIDEngineLoad::getPID() const
{
	return B100;
}

double PIDEngineLoad::CalculateValue(long firstByte, long secondByte)
{
	return firstByte / 2.55;
}
