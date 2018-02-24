#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

void Vlogenie(int &hor, int &min, int &sec)//ввод данных
{
	cout << "Введите ЧЧ : ММ: СС " << endl;
	cin >> hor;cout << ":";cin >> min;cout << ":";cin >> sec;
}


class Time
{
private:
	int hor, min, sec;
	void time()//оптимизация переменных
	{
		if (sec > 59)
		{
			min = min + sec / 60;
			sec = sec % 60;
		}
		if (min > 59)
		{
			hor = hor + min / 60;
			min = min % 60;
		}
		if (hor > 23)
		{
			hor = hor % 24;
		}
	}
public:
	//конструктор
	Time(int _hor, int _min, int _sec)
	{
		setTime(_hor, _min, _sec);
	}
	//Вывод на экран
	void ShowTime()
	{
		cout << hor << " : " << min << " : " << sec << endl;
	}
	//Установка времени
	void setTime(int _hor, int _min, int _sec)
	{
		hor = _hor;
		min = _min;
		sec = _sec;
	}
	//Оператор присваивания
	Time operator = (const Time& obj)
	{
		hor = obj.hor;
		min = obj.min;
		sec = obj.sec;
		return *this;
	}
	//сдвиг времени в меньшую сторону
	Time operator - (Time t2)
	{
		int sec_ = sec - t2.sec;
		int min_ = min - t2.min;
		int hor_ = hor - t2.hor;
		if (sec_ < 0)
			sec_ = 60 - sec_ % 60;
		min_ = min_ - (1 + abs(sec / 60));
		if (min_ < 0)
			min_ = 60 - min_ % 60;
		hor_ = hor_ - (1 + abs(min / 60));
		if (hor_ < 0)
			hor_ = 24 - hor_ % 24;
	}
	//Сдвиг времени в большую сторону
	Time operator + (Time t2)
	{
		int sec_ = sec + t2.sec;
		int min_ = min + t2.min;
		int hor_ = hor + t2.hor;
		if (sec > 59)
		{
			min = min + sec / 60;
			sec = sec % 60;
		}
		if (min > 59)
		{
			hor = hor + min / 60;
			min = min % 60;
		}
		if (hor > 23)
		{
			hor = hor % 24;
		}
	}
};
int main()
{
	int choice, change;
	int hor = 0;
	int min = 0;
	int sec = 0;
	Time T;
	Time time2;
	Time time3;
	cout << "Желаете задать время?" << endl;
in:		cout << "1-Да,2-Нет" << endl;
	cin >> choice;
	if (choice == 1)
	{
		Vlogenie(hor, min, sec);
		T.setTime(hor, min, sec);
		T.ShowTime();
		cout << T.ShowTime() << endl;
		system("pause");
		system("cls");
	}
	if (choice != 0)
		goto in;
	choice = 0;
	cout << "Какие операции хотите сделать" << endl;
	cout << "1-сдвинуть время,2-вычислить разницу,3-выход" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "В большую сторону-1,в меньшую сторону-2" << endl;
		cin >> change;
		if (change == 1)
			Vlogenie(hor, min, sec);
		time2.setTime(hor, min, sec);
		T = T + time2;
		T.ShowTime();
		cout << T.ShowTime << endl;
		if (change == 2)
			Vlogenie(hor, min, sec);
		time2.setTime(hor, min, sec);
		T = T - time2;
		T.ShowTime();
		cout << T.ShowTime << endl;
	}
	if (choice == 2)
		//Разница будет операций в главной функции,а не методом класса
		Vlogenie(hor, min, sec);
	time2.setTime(hor, min, sec);
	time3 = T - time2;
	time3.ShowTime();
	cout << time3.ShowTime << endl;
	if (choice == 3)
		return 0;
}