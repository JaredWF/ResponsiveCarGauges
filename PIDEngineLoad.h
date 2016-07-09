// PIDEngineLoad.h

#ifndef _PIDENGINELOAD_h
#define _PIDENGINELOAD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include "PID.h"
#else
	#include "WProgram.h"
#endif

class PIDEngineLoad: public PID
{
	public:
		PIDEngineLoad();
		byte getMode() const;
		byte getPID() const;
	
	private:
		double CalculateValue(long firstByte, long secondByte);
};

#endif

