#pragma once
#include <string>
#include <regex>

struct DateTime {
	std::string data;

	int year;
	int month;
	int day;

	int hours;
	int minutes;
	int seconds=0;

public:
	DateTime() {

	}
	DateTime(std::string data) {
		this->data = data;
		Parse(data);
	}

	void Parse(std::string data) {
		std::regex reg("(\\d+).(\\d+).(\\d+) (\\d+):(\\d+)");
		std::cmatch result;
		if (std::regex_search(data.c_str(), result, reg)) {
			try {
				this->data = result[0];
				day = atoi(result[1].str().c_str());
				month = atoi(result[2].str().c_str());
				year = atoi(result[3].str().c_str());

				hours = atoi(result[4].str().c_str());
				minutes = atoi(result[5].str().c_str());
			}
			catch (...) {
				std::cout << "ошибка при парсинге данных. не корректная строка" << std::endl;
			}
		}
	}

	std::string GetData() {
		return data;
	}
};

struct TruckStat {
	std::string data;
	DateTime datetime;
	std::string name;
	std::string weight;

public:
	TruckStat(std::string data) {
		this->data = data;
		Parse(data);
	}

	void Parse(std::string data) {
		std::regex reg("(\\d+.\\d+.\\d+\\s*\\d+:\\d+),\\s+(\.*),\\s*(\\d+)");
		std::cmatch result;
		if (std::regex_search(data.c_str(), result, reg)) {
			try {
				this->data = result[0];
				name = result[2];
				weight = result[3];

				datetime = DateTime(result[1]);
			}
			catch (...) {
				std::cout << "ошибка при парсинге данных. не корректная строка" << std::endl;
			}
		}
	}

	std::string GetData() {
		return data;
	}
};