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
			cout << "� ��� ��� ������" << endl;
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
			cout << "��������� ������ ������: " << Count << " ������" << endl;
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
			cout << "��� ����� ��������" << endl;
		}
		else
		{
			cout << "�������� ��� �����, �����:" << endl;
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
			cout << "� ��� ��� ������" << endl;
		}
		else
		{
			system("cls");
			cout << "����: " << _date << endl;
			cout << "��������: " << _name << " " << _surname << " " << _patronomic << endl;
			cout << "������� ��������: " << DepartureStation << endl;
			cout << "������� ��������: " << ArrivalStation << endl;
			cout << "����� ������: " << rand() % 100 + 1 << endl;
			cout << "����� ������: " << rand() % 11 + 1 << endl;
			cout << "����� �����: ";
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
		cout << "������������! ��� ������ ������ �������, ����������, ���� ������:" << endl;
		cout << endl;
		cout << "�������: "; 	cin >> surname;
		cout << "���: "; cin >> name;
		cout << "��������: ";	cin >> patronomic;
		system("cls");
		cout << "������� ���� ������� � �������: ����.�����.��� " << endl;
		cin >> date;
		system("cls");
		cout << "������� ��������:" << endl;
		cout << "1 - ������ ��������" << endl;
		cout << "2 - ������" << endl;
		cin >> departure;
		system("cls");
		if (departure == 1)
		{
			departurestation = "������ ��������";
			arrivalstation = "������";
		}
		else
		{
			departurestation = "������";
			arrivalstation = "������ ��������";
		}
		TrainStation.SetInfo(date, name, surname, patronomic, departurestation, arrivalstation);
		cout << "�������� ��� ������:" << endl;
		cout << "1 - ��������" << endl;
		cout << "2 - ���������" << endl;
		cout << "3 - ������" << endl;
		cin >> TrainType;
		system("cls");
		if (TrainType == 1)
			VagonType = 4;
		else
		{
			cout << "�������� ��� ������" << endl;
			cout << "1 - ��������" << endl;
			cout << "2 - ����" << endl;
			cout << "3 - �������� �����" << endl;
			cin >> VagonType;
			system("cls");
		}
	rep:
		system("cls");
		cout << "1 - �������� ��������� ����" << endl;
		cout << "2 - ��������������� �����" << endl;
		cout << "3 - ���������� ��������� �������" << endl;
		cout << "4 - ������������ ������" << endl;
		cout << "5 - �������� ����� ������" << endl;
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
				cout << "� �������� 100 ������� ����" << endl;
				cout << "������� ����� �����: " << endl;
				cin >> place;
				break;
			case 2:
				switch (VagonType)
				{
				case 1:
					cout << "����� � 1 �� 27 - �������, � 28 �� 54 - ������" << endl;
					cout << "������� ����� �����:" << endl;
					cin >> place;
					break;
				case 2:
					cout << "����� � 55 �� 72 - �������, � 73 �� 90 - ������" << endl;
					cout << "������� ����� �����:" << endl;
					break;
				case 3:
					cout << "�������� ����� - ����� � 91 �� 108" << endl;
					cout << "������� ����� �����:" << endl;
					cin >> place;
					break;
				}
				break;
			case 3:
				switch (VagonType)
				{
				case 1:
					cout << "����� � 1 �� 27 - �������, � 28 �� 54 - ������" << endl;
					cout << "������� ����� �����:" << endl;
					cin >> place;
					break;
				case 2:
					cout << "����� � 55 �� 72 - �������, � 73 �� 90 - ������" << endl;
					cout << "������� ����� �����:" << endl;
					cin >> place;
					break;
				case 3:
					cout << "�������� ����� - ����� � 91 �� 108" << endl;
					cout << "������� ����� �����:" << endl;
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
			cout << "��� ����� ������!" << endl;
			system("pause");
			return 0;
		}
	}
}