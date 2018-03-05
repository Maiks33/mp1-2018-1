#define _CRT_SECURE_NO_WARNINGS
#define NMAX "��� �������"

#include <cstdio>
#include <iostream>
#include <math.h>
#include <cstring>
#include <clocale>

using namespace std;

class Calendar
{
	int day[30];
	int	month[30];
	int year[30];
	char **event;
public:
	Calendar(char *str = 0, int index = -1, int y = 0, int m = 0, int d = 0)
	{
		event = new char*[30];
		for (int i = 0; i < 30; i++)
		{
			year[i] = 0;
			month[i] = 0;
			day[i] = 0;
			event[i] = new char[strlen(NMAX) + 1];
			strcpy(event[i], NMAX);
		}
		if ((index > -1) && (index < 30))
		{
			delete[] event[index];
			event[index] = new char[strlen(str) + 1];
			strcpy(event[index], str);
		}
	}
	~Calendar()
	{
		for (int i = 0; i < 30; i++)
			delete[] event[i];
		delete[] event;
	}
	Calendar& operator=(const Calendar& events)
	{
		for (int i = 0; i < 30; i++)
		{
			day[i] = events.day[i];
			month[i] = events.month[i];
			year[i] = events.year[i];
			event[i] = new char[strlen(events.event[i]) + 1];
			strcpy(event[i], events.event[i]);
		}
		return *this;
	}
	void EnterEvent(int index, int _day, int _month, int _year, char *str)
	{
		if ((index > 0) && (index < 31))
			if ((_year > 0 && _year < 2021) && (_month > 0 && _month < 13) && (_day > 0 && _day < 32))
			{
				day[index] = _day;
				month[index] = _month;
				year[index] = _year;
				event[index] = new char[strlen(str) + 1];
				strcpy(event[index], str);
			}
	}
	void ChooseEvent(int index)
	{
		cout << "�������� � ����� ������� ������ ��������, ����� ��� �����" << endl;
		cin >> index;
		cout << endl;
	}
	void ShowEvent(int index)
	{
		cout << "���� �������: " << event[index] << endl;
		cout << "���� ������ �������: " << day[index] << "." << month[index] << "." << year[index] << endl;
		cout << endl;
	}
	void CheckDate(int index, int _year, int _month, int _day)
	{
		int diff_day = abs(day[index] - _day);
		int diff_month = abs(month[index] - _month);
		int diff_year = abs(year[index] - _year);
		if (diff_day > 31)
		{
			diff_month++;
		}
		if (diff_month > 12)
		{
			diff_year++;
		}
		cout << "������� ���������� " << diff_day << " ����," << diff_month << " �������," << diff_year << " ���" << endl;
	}
	void SetNewDate(int index, int _day, int _month, int _year)
	{
		int menu2;
		cout << "�������� ���� ������ �������� ����" << endl;
		cout << "1 - �����" << endl;
		cout << "2 - �����" << endl;
		cin >> menu2;
		switch (menu2)
		{
		case 1:
		{
			if ((day[index] + _day) > 31)
			{
				month[index] = month[index] + 1;
				day[index] = day[index] % 31;
			}
			else
				day[index] = day[index] + _day;

			if ((month[index] + _month) > 12)
			{
				year[index] = year[index] + 1;
				month[index] = month[index] % 12;
			}
			else
				month[index] = month[index] + _month;

			year[index] = year[index] + _year;

			ShowEvent(index);
			cout << endl;
			break;
		}
		case 2:
		{
			if ((day[index] - _day) < 1)
			{
				month[index] = month[index] - 1;
				day[index] = day[index] % 31;
			}
			else
				day[index] = day[index] - _day;

			if ((month[index] - _month) < 1)
			{
				year[index] = year[index] - 1;
				month[index] = month[index] % 12;
			}
			else
				month[index] = month[index] - _month;

			year[index] = year[index] - _year;

			ShowEvent(index);
			cout << endl;
			break;
		}
		}
	}
};



int main()
{
	int d, m, y, i, k, menu;
	int index;
	char str[100];
	setlocale(LC_ALL, "Russian");
	class Calendar calendar;
	cout << "������� ������� ������ ������? " << endl;
	cin >> k;
	cout << endl;
	for (i = 0; i < k; i++)
	{
		cout << "������� ����� �������: " << endl;
		cin >> index;
		cout << endl;
		cout << "������� �������: " << endl;
		cin.ignore();
		cin.getline(str, 100);
		cout << endl;
		cout << "������� ���� ������� � �������: ����� ����� ���: " << endl;
		cin >> d >> m >> y;
		cout << endl;
		calendar.EnterEvent(index, d, m, y, str);
	}
	system("cls");
rep1:
	system("cls");
	calendar.ChooseEvent(index);
	calendar.ShowEvent(index);
	cout << endl;
	cout << "��� ������ �������?" << endl;
	cout << "1 - ������ ������� � �����" << endl;
	cout << "2 - �������� �������" << endl;
	cout << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
		cout << "������� ����, � ������� ������ ����� ������� � �������: ����� ����� ���: " << endl;
		cin >> d >> m >> y;
		cout << endl;
		calendar.CheckDate(index, d, m, y);
		cout << endl;
		system("pause");
		goto rep1;
	case 2:
		cout << "������� ����, �� ������� ������ �������� ������� � �������: ����� ����� ���: " << endl;
		cin >> d >> m >> y;
		calendar.SetNewDate(index, d, m, y);
		cout << endl;
		system("pause");
		goto rep1;
	}
	system("pause");
	return 0;
}