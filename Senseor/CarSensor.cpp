#include "CarSensor.h"


double CarSensor::CurLevel() {
	printf("������ ���� �� ���������: %f\n",level);
	return level;
}

void CarSensor::UpLevel(double level) {
	if (level > 0)
		this->level += level;
	else
		printf("Level ������ ���� ������ 0.\n");
}

void CarSensor::DownLevel(double level) {
	if (level > 0 && this->level > 0)
		this->level -= level;
	else
		printf("Level ������ ���� ������ 0. ������� �������� level %f\n",this->level);
}

CarSensor::CarSensor()
{
}


CarSensor::~CarSensor()
{
}
