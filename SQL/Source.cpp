#include <string>
#include <iostream>
#include <mysql.h>

class GetWorkedTime {
private:
	std::string data_name;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES *res;

	
public:
	GetWorkedTime(std::string data_name) {
		this->data_name = data_name;
		conn = mysql_init(0);
	}

	void Connect() {
		conn = mysql_real_connect(conn, "localhost", "root", "5432", data_name.c_str(), 3306, NULL, 0);
		if (!conn) {
			std::cout << "не удалось подключится к базе данных" << std::endl;
			return;
		}
		else {
			std::cout << "успешно подключились к базе данных" << std::endl;
		}
	}

	int Get(std::string emploee, std::string day) {
		//выбираем время начало и конец времени работы


		//select ca.info,
		//	date_format((select MAX(time) from archive join card on card.id = archive.card_id where card.id = ca.id), '%H:%i:%s'),
		//	date_format((select MIN(time) from archive join card on card.id = archive.card_id where card.id = ca.id), '%H:%i:%s') from card as ca
		//	join archive as arch on arch.card_id = ca.id
		//where ca.info = 'emploee' and date_format(arch.time, 'day');

		std::string querystr = "select ca.info , date_format((select MAX(time) from archive join card on card.id = archive.card_id where card.id = ca.id),'%H:%i:%s') , date_format((select MIN(time) from archive join card on card.id = archive.card_id where card.id = ca.id),'%H:%i:%s') from card as ca join archive as arch on arch.card_id = ca.id where ca.info = '"+emploee+"' and date_format(arch.time,'%y-%m-%d') = '"+day+"';";
		auto qstate = mysql_query(conn, querystr.c_str());
		std::string fio;
		std::string start_time;
		std::string end_time;

		if (!qstate) {
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res)) {
				fio = row[0];
				start_time = row[2];
				end_time = row[1];
				break;
			}
		}
		else {
			std::cout << "не удалось выполнить запрос" << std::endl;
			return -1;
		}

		if (fio == "")
			return -1;
		
		int hour1 = atoi(start_time.substr(0, 2).c_str());
		int minute1 = atoi(start_time.substr(3, 5).c_str());

		int hour2 = atoi(end_time.substr(0, 2).c_str());
		int minute2 = atoi(end_time.substr(3, 5).c_str());

		int worked_time = ((hour2 - hour1) * 60) + minute1 + minute2;

		return worked_time;
	}

	~GetWorkedTime() {
		mysql_close(conn);
	}

	int GetWorkedMinutes() {
		return 0;
	}
};

int main() {
	setlocale(LC_ALL,"rus");

	GetWorkedTime *gwt = new GetWorkedTime("test_bd");
	gwt->Connect();

	printf("%d minutes\n",gwt->Get("fio1","19-02-27"));

	delete gwt;
	system("pause");
	return 0;
}