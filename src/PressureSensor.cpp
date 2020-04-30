#include "Arduino.h"
#include "PressureSensor.h"

PressureSensor::PressureSensor(int pin)
{
	_pin = pin;
}

void PressureSensor::begin()
{

}

int PressureSensor::getBar()
{
	/* read the sensor voltage */
	float pascal = getPascal();
	return pascal/10e5;
}

int PressureSensor::getPSI()
{
	/* read the sensor voltage */
	float sensorVoltage = analogRead(_pin);
	return ((sensorVoltage - 95) / 204) * 50;
}

int PressureSensor::getPascal()
{
	/* read the sensor voltage */
	float sensorVoltage = analogRead(_pin);
	return (3.0*((float)sensorVoltage-0.47))*1000000.0;
}

char* PressureSensor::getPressureInBars()
{
	sprintf(_formatted_time, "%02dBar",
			getBar());

	return _formatted_time;
}
