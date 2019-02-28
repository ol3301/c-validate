#include <iostream>
#include <Windows.h>
#include "CalculateWeighing.h"
#include "models.h"
#include <regex>

int main() {
	setlocale(LC_ALL, "rus");
	
	CalculateWeighing cw("table.txt");
	cw.Sort(true);
	cw.Dump();

	system("pause");
	return 0;
}