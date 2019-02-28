#pragma once
#include <string>
#include <iostream>


class BaseSensor
{
protected:
	double level=0;
public:
	virtual void UpLevel(double level=1);
	virtual void DownLevel(double level=1);
	virtual double CurLevel();
	BaseSensor();
	~BaseSensor();
};

