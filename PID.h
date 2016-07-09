// PID.h

#ifndef _PID_h
#define _PID_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	//list of PIDs can be found here: https://en.wikipedia.org/wiki/OBD-II_PIDs
	class PID
	{
		public:
			double Read();
			virtual byte getMode() const = 0;
			virtual byte getPID() const = 0;
		private:
			virtual double CalculateValue(long firstByte, long secondByte); //choosing only to support one and two byte PIDs
	};
#else
	#include "WProgram.h"
#endif


#endif

