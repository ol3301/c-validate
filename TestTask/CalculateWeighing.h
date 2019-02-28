#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <direct.h>

#include "Models.h"

class CalculateWeighing
{
private:
	std::string path="";
	std::map<std::string, std::list<TruckStat>> truck_store;
	
public:
	void ReadRows();
	void Dump();
	//true - �� ����, false �� �������
	void Sort(bool direction);
	CalculateWeighing(std::string path);
	~CalculateWeighing();
};

