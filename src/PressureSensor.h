#ifndef PressureSensor_h
#define PressureSensorh

#include "Arduino.h"

class PressureSensor
{
public:
	PressureSensor(int pin);
	void begin();
	int getBar();
	int getPSI();
	int getPascal();
	char* getPressureInBars();
private:
	int _pin;
	char _formatted_time[10];
};

#endif
