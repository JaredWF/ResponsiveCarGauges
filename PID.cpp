// 
// 
// 

#include "PID.h"

double PID::Read()
{
	String request = String(getMode(), HEX) + String(getPID(), HEX) + "1"; //"1" makes the car wait for the first response, giving faster response times
	Serial.println(request);

	bool reading = false;
	String response = "";
	while (Serial.available() > 0 || !reading) {
		if (Serial.available() > 0) {
			reading = true;
			response += char(Serial.read());
		}
	}

	long firstValue = strtol(response.substring(7, 9).c_str(), NULL, 0);
	long secondValue;
	if (response.length() >= 13) {
		secondValue = strtol(response.substring(11, 13).c_str(), NULL, 0);
	} else {
		secondValue = NULL;
	}

	return CalculateValue(firstValue, secondValue);
}
