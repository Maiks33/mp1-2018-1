#include <iostream>
#include <vector>
#include <locale.h>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class GorRailWay
{
protected:
	vector <string> L;
	vector <string> F;
	vector <string> S;
	vector <bool> LastReserv;
	vector <bool> FirmReserv;
	vector <bool> ScorReserv;
	vector <bool> CheckLastPlace;
	vector <bool> CheckFirmPlace;
	vector <bool> CheckScorPlace;
public:
	GorRailWay() :L(101), F(109), S(109), LastReserv(109), FirmReserv(109), ScorReserv(109), CheckLastPlace(101), CheckFirmPlace(109), CheckScorPlace(109)
	{
		for (int i = 1; i < 101; i++)
		{
			LastReserv[i] = false;
			CheckLastPlace[i] = false;
		}

		for (int i = 1; i < 109; i++)
		{
			FirmReserv[i] = false;
			ScorReserv[i] = false;
		}
	}
	friend class RailWayStation;
};

class RailWayStation
{
	GorRailWay train;
	string _date;
	int _TrainType;
	int _VagonType;
	int CountLast;
	int CountFirmPlac;
	int CountFirmKupe;
	int CountFirmSV;
	int CountScorPlac;
	int CountScorPKupe;
	int CountScorSV;
	int Count;
	int CountAll;
	string _name;
	string _surname;
	string _patronomic;
	string DepartureStation;
	string ArrivalStation;
	vector <int> places;
public:
	RailWayStation()
	{}
	void SetInfo(string date, string name, string surname, string patronomic, string departurestation, string arrivalstation)
	{
		_date = date;
		_name = name;
		_surname = surname;
		_patronomic = patronomic;
		DepartureStation = departurestation;
		ArrivalStation = arrivalstation;
	}
	bool CheckReserv(int TrainType, int place)
	{
		if (TrainType == 1)
		{
			return train.CheckLastPlace[place];
		}
		if (TrainType == 2)
		{
			return train.CheckFirmPlace[place];
		}
		if (TrainType == 3)
		{
			return train.CheckScorPlace[place];
		}
	}

	void ReservePlace(int TrainType, int place)
	{
		if (TrainType == 1)
		{
			train.LastReserv[place] = true;
			train.CheckLastPlace[place] = true;
			places.push_back(place);
		}
		if (TrainType == 2)
		{
			train.FirmReserv[place] = true;
			train.CheckFirmPlace[place] = true;
			places.push_back(place);
		}
		if (TrainType == 3)
		{
			train.ScorReserv[place] = true;
			train.CheckScorPlace[place] = true;
			places.push_back(place);
		}
	}

	void Calculate()
	{
		if (places.size() == 0)
		{
			cout << "У Вас нет заказа" << endl;
		}
		else
		{
			int i;
			for (i = 1; i < 101; i++)
				if (CheckReserv(1, i) == true)
				{
					CountLast++;
				}
			for (i = 1; i < 109; i++)
				if (CheckReserv(2, i) == true)
				{
					if ((1 <= i) && (i <= 54))
						CountFirmPlac++;
					else
						if ((55 <= i) && (i <= 90))
							CountFirmKupe++;
						else
							if ((91 <= i) && (i <= 108))
								CountFirmSV++;
				}
			for (i = 1; i < 109; i++)
				if (CheckReserv(3, i) == true)
				{
					if ((1 <= i) && (i <= 54))
						CountScorPlac++;
					else
						if ((55 <= i) && (i <= 90))
							CountScorPKupe++;
						else
							if ((91 <= i) && (i <= 108))
								CountScorSV++;
				}
			CountLast = CountLast * 1000;
			CountFirmPlac = CountFirmPlac * 1500;
			CountFirmKupe = CountFirmKupe * 2000;
			CountFirmSV = CountFirmSV * 2500;
			CountScorPlac = CountScorPlac * 1500;
			CountScorPKupe = CountScorPKupe * 2500;
			CountScorSV = CountScorSV * 2000;
			Count = CountLast + CountFirmPlac + CountFirmKupe + CountFirmSV + CountScorPlac + CountScorPKupe + CountScorSV;
			cout << "Стоимость Вашего заказа: " << Count << " рублей" << endl;
			CountLast = 0;
			CountFirmPlac = 0;
			CountFirmKupe = 0;
			CountFirmSV = 0;
			CountScorPlac = 0;
			CountScorPKupe = 0;
			CountScorSV = 0;
		}
	}
	void CheckPlace()
	{
		if (places.size() == 0)
		{
			cout << "Все места свободны" << endl;
		}
		else
		{
			cout << "Свободны все места, кроме:" << endl;
			for (int i = 0; i < places.size(); i++)
				cout << places[i] << " " << endl;
		}
	}
	void CancelOrder(int place)
	{

		train.LastReserv[place] = false;
		train.CheckLastPlace[place] = false;
		train.FirmReserv[place] = false;
		train.CheckFirmPlace[place] = false;
		train.ScorReserv[place] = false;
		train.CheckScorPlace[place] = false;
		places.clear();
		Count = 0;
	}
	void CreateTicket()
	{
		if (places.size() == 0)
		{
			cout << "У Вас нет заказа" << endl;
		}
		else
		{
			system("cls");
			cout << "Дата: " << _date << endl;
			cout << "Пассажир: " << _name << " " << _surname << " " << _patronomic << endl;
			cout << "Станция отправки: " << DepartureStation << endl;
			cout << "Станция прибытия: " << ArrivalStation << endl;
			cout << "Номер поезда: " << rand() % 100 + 1 << endl;
			cout << "Номер вагона: " << rand() % 11 + 1 << endl;
			cout << "Номер места: ";
			for (int i = 0; i < places.size(); i++)
				cout << places[i] << " ";	cout << endl;
		}
	}

};

int main()
{
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		RailWayStation TrainStation;
		string date;
		string name; string surname;
		string patronomic;
		string departurestation;
		string arrivalstation;
		int i;
		int menu;
		int departure;
		int place;
		int TrainType;
		int VagonType;
		cout << "Здравствуйте! Для заказа билета введите, пожалуйста, ваши данные:" << endl;
		cout << endl;
		cout << "Фамилия: "; 	cin >> surname;
		cout << "Имя: "; cin >> name;
		cout << "Отчетсво: ";	cin >> patronomic;
		system("cls");
		cout << "Введите дату поездки в формате: день.месяц.год " << endl;
		cin >> date;
		system("cls");
		cout << "Станция отправки:" << endl;
		cout << "1 - Нижний Новгород" << endl;
		cout << "2 - Москва" << endl;
		cin >> departure;
		system("cls");
		if (departure == 1)
		{
			departurestation = "Нижний Новгород";
			arrivalstation = "Москва";
		}
		else
		{
			departurestation = "Москва";
			arrivalstation = "Нижний Новгород";
		}
		TrainStation.SetInfo(date, name, surname, patronomic, departurestation, arrivalstation);
		cout << "Выберите тип поезда:" << endl;
		cout << "1 - Ласточка" << endl;
		cout << "2 - Фирменный" << endl;
		cout << "3 - Скорый" << endl;
		cin >> TrainType;
		system("cls");
		if (TrainType == 1)
			VagonType = 4;
		else
		{
			cout << "Выберите тип вагона" << endl;
			cout << "1 - Плацкарт" << endl;
			cout << "2 - Купе" << endl;
			cout << "3 - Спальный вагон" << endl;
			cin >> VagonType;
			system("cls");
		}
	rep:
		system("cls");
		cout << "1 - Проверка свободных мест" << endl;
		cout << "2 - Зарезервировать места" << endl;
		cout << "3 - Рассчитать стоимость билетов" << endl;
		cout << "4 - Сформировать билеты" << endl;
		cout << "5 - Отменить заказ билета" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			system("cls");
			TrainStation.CheckPlace();
			system("pause");
			goto rep;
			break;
		case 2:
			switch (TrainType)
			{
			case 1:
				cout << "В ласточке 100 сидячих мест" << endl;
				cout << "Введите номер места: " << endl;
				cin >> place;
				break;
			case 2:
				switch (VagonType)
				{
				case 1:
					cout << "Места с 1 по 27 - верхние, с 28 по 54 - нижние" << endl;
					cout << "Введите номер места:" << endl;
					cin >> place;
					break;
				case 2:
					cout << "Места с 55 по 72 - верхние, с 73 по 90 - нижние" << endl;
					cout << "Введите номер места:" << endl;
					break;
				case 3:
					cout << "Спальный вагон - места с 91 по 108" << endl;
					cout << "Введите номер места:" << endl;
					cin >> place;
					break;
				}
				break;
			case 3:
				switch (VagonType)
				{
				case 1:
					cout << "Места с 1 по 27 - верхние, с 28 по 54 - нижние" << endl;
					cout << "Введите номер места:" << endl;
					cin >> place;
					break;
				case 2:
					cout << "Места с 55 по 72 - верхние, с 73 по 90 - нижние" << endl;
					cout << "Введите номер места:" << endl;
					cin >> place;
					break;
				case 3:
					cout << "Спальный вагон - места с 91 по 108" << endl;
					cout << "Введите номер места:" << endl;
					cin >> place;
					break;
				}
				break;
			}
			TrainStation.ReservePlace(TrainType, place);
			goto rep;
			break;
		case 3:
			system("cls");
			TrainStation.Calculate();
			system("pause");
			goto rep;

		case 4:
			system("cls");
			TrainStation.CreateTicket();
			system("pause");
			return 0;
		case 5:
			system("cls");
			TrainStation.CancelOrder(place);
			cout << "Ваш заказ отменён!" << endl;
			system("pause");
			return 0;
		}
	}
}