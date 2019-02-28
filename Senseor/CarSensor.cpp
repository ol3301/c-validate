#include "CarSensor.h"


double CarSensor::CurLevel() {
	printf("ћашина едет со скоростью: %f\n",level);
	return level;
}

void CarSensor::UpLevel(double level) {
	if (level > 0)
		this->level += level;
	else
		printf("Level должен быть больше 0.\n");
}

void CarSensor::DownLevel(double level) {
	if (level > 0 && this->level > 0)
		this->level -= level;
	else
		printf("Level должен быть больше 0. “екущее значение level %f\n",this->level);
}

CarSensor::CarSensor()
{
}


CarSensor::~CarSensor()
{
}
