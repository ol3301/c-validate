#pragma once
#include <string>
#include <iostream>
#include "BaseSensor.h"

class CarSensor : public BaseSensor
{
public:
	virtual double CurLevel();
	virtual void UpLevel(double level = 1);
	virtual void DownLevel(double level = 1);

	CarSensor();
	~CarSensor();
};

