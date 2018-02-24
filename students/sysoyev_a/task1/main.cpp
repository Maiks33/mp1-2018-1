#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <math.h>
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
			while (sec >= 60)
				min++;
			sec -= 60;
		}
		if (min >= 59)
		{
			while (min >= 60)
				hor++;
			min -= 60;
		}
		if (hor >= 23)
		{
			while (hor >= 23)
				hor = hor - 23;
		}
	}
public:
	//конструктор
	void ConstructTime(int _hor, int _min, int _sec)
	{
		int hor(_hor);
		int min(_min);
		int sec(_sec);
	}
	//Вывод на экран
	void ShowTime()
	{
		cout << hor << " : " << min << " : " << sec << endl;
	}
	//Оператор присваивания
	Time operator = (const Time obj)
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
			sec_ = 60 + sec_;
		min_--;
		if (min_ < 0)
			min_ = 60 + min_;
		hor_--;
		return *this;
	}
	//Сдвиг времени в большую сторону
	Time operator + (Time t2)
	{
		int sec_ = sec + t2.sec;
		int min_ = min + t2.min;
		int hor_ = hor + t2.hor;
		if (sec_ > 59)
			sec_ = sec_ - 60;
		min_++;
		if (min_ > 59)
			min_ = min_ - 60;
		hor_++;
		if (hor_ > 23)
			hor_ = hor_ - 23;
		return *this;
	}
	//Разница между заданными временами
	/*Time Raznica(Time t1,Time t2,Time t3)
	{
	int choice;

	if (t1.hor > t2.hor)
	t3 = t1 - t2;
	if (t1.hor < t2.hor)
	t3 = t2 - t1;
	cout << "Разница в чем:" << endl;
	cout << "1-в часах" << endl;
	cout << "2-в минутах" << endl;
	cout << "3-в секундах" << endl;
	cout << "4-просто вывести" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	t3.hor = t3.hor;
	t3.min = 0;
	t3.sec = 0;
	cout << "Время в часах :" << t3.hor << endl;
	case 2:
	t3.min = t3.min + 60 * t3.hor;
	t3.hor = 0;
	t3.sec = 0;
	cout << "Время в минутах :" << t3.min << endl;
	case 3:
	t3.min = t3.min + 60 * t3.hor;
	t3.sec = t3.sec + 60 * t3.min;
	t3.hor = 0;
	t3.min = 0;
	cout << "Время в секундах :" << t3.sec << endl;
	case 4:
	t3.ShowTime();
	}
	return *this;
	}*/
};

int main()
{
  cout << "Hello!" << endl;
  int choice, change;
  int hor = 0;
  int min = 0;
  int sec = 0;
  Time T;
  Time time2;
  Time time3;
  time3.ConstructTime(hor, min, sec);
  cout << "Желаете задать время?" << endl;
in:		cout << "1-Да,2-Нет" << endl;
  cin >> choice;
  if (choice == 1)
  {
	  Vlogenie(hor, min, sec);
	  T.ConstructTime(hor, min, sec);
	  T.ShowTime();
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
	  time2.ConstructTime(hor, min, sec);
	  T = T + time2;
	  if (change == 2)
		  Vlogenie(hor, min, sec);
	  time2.ConstructTime(hor, min, sec);
	  T = T - time2;
  }
  if (choice == 2)
	  Vlogenie(hor, min, sec);
  time2.ConstructTime(hor, min, sec);
  time3 = T - time2;
  time3.ShowTime();
  if (choice == 3)
	  return 0;
}
