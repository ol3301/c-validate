#include "CalculateWeighing.h"

void CalculateWeighing::ReadRows() {
	std::ifstream file(path);

	if (!file.is_open()) {
		printf("Ошибка открытия файла\n");
		return;
	}

	std::string s;

	while (std::getline(file, s)) {
		if (s != "") {
			TruckStat ts(s);
			truck_store[ts.name].push_back(ts);
		}
	}


	file.close();
}

void CalculateWeighing::Dump() {
	for (auto data : truck_store) {
		std::ofstream file(data.first+".txt", std::ofstream::out);
		int totale_weigh = 0;
		for (auto truck : data.second) {
			file << truck.GetData() << std::endl;
			totale_weigh += atoi(truck.weight.c_str());
		}
		file << "всего веса: "+std::to_string(totale_weigh) << std::endl;
		file.close();
	}

}

void CalculateWeighing::Sort(bool direction) {
	//сортируем по дате
	if (direction == true) {
		for (auto &store : truck_store) {
			store.second.sort([](TruckStat ts1, TruckStat ts2) {
				if (ts1.datetime.year > ts2.datetime.year) return true; else if (ts1.datetime.year < ts2.datetime.year) return false;
				if (ts1.datetime.month > ts2.datetime.month) return true; else if (ts1.datetime.month < ts2.datetime.month) return false;
				if (ts1.datetime.day > ts2.datetime.day) return true; else if (ts1.datetime.day < ts2.datetime.day) return false;
			});
		}
	}
	else if (!direction) {
		//сортируем по времени
		for (auto &store : truck_store) {
			store.second.sort([](TruckStat ts1, TruckStat ts2) {
				if (ts1.datetime.hours > ts2.datetime.hours) return true; else if (ts1.datetime.hours < ts2.datetime.hours) return false;
				if (ts1.datetime.minutes > ts2.datetime.minutes) return true; else if (ts1.datetime.minutes < ts2.datetime.minutes) return false;
			});
		}
	}
}


CalculateWeighing::CalculateWeighing(std::string path)
{
	this->path = path;
	ReadRows();
}


CalculateWeighing::~CalculateWeighing()
{
}
