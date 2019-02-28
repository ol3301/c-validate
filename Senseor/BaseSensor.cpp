#include "BaseSensor.h"


void BaseSensor::UpLevel(double level) {
	if (level > 0)
		this->level += level;
	else
		printf("Level ������ ���� ������ 0.");
}

void BaseSensor::DownLevel(double level) {
	if (level > 0)
		this->level -= level;
	else
		printf("Level ������ ���� ������ 0.");
}

double BaseSensor::CurLevel() {
	return level;
}


BaseSensor::BaseSensor()
{
}


BaseSensor::~BaseSensor()
{
}
