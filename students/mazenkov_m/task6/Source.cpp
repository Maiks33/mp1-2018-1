#define _CRT_SECURElenghtO_WARNINGS 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <Windows.h>

using namespace std;

class BullsAndCows
{
	int n;
	int cows;
	int bulls;
	vector <int> Player;
	vector <int> Chislo;
public:
	BullsAndCows()
	{
		n = 0;
		cows = 0;
		bulls = 0;
	}
	void SetLenght(int lenght)
	{
		n = lenght;
	}
	vector<int> RandomNumber(int n)
	{
		vector<int> tmp(10);
		srand(time(0));
		for (int i = 0; i < 10; i++)
			tmp[i] = i;
		random_shuffle(tmp.begin(), tmp.end());
		for (int i = 0; i <= n; i++)
			Chislo.push_back(tmp[i]);
		return Chislo;
	}

	bool GetNumber(string igrok)
	{
		if (n == igrok.size())
		{
			for (int i = 0; i < igrok.size(); i++)
			{
				char tmp[2];
				tmp[0] = igrok[i];
				Player.push_back(atoi(tmp));
			}
			return true;
		}
		else
			return false;
	}
	int CheckCows()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((Chislo[i] == Player[j]) && (i != j))
					cows++;
			}
		}
		return cows;
	}
	int CheckBulls()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (Chislo[i] == Player[i] && (i == j))
					bulls++;
			}
		}
		return bulls;
	}
	bool CheckWin(bool BullsAndCowsWin)
	{
		if (bulls == n)
		{
			BullsAndCowsWin = true;
		}
		return BullsAndCowsWin;
	}
	void ClearCowsBulls()
	{
		cows = 0;
		bulls = 0;
		Player.clear();
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	BullsAndCows BullsAndCows;
	int lenght, _steps;
	string(menu);
	bool BullsAndCowsWin = false;
	string num;
	cout << "Здравствуйте, это игра 'Быки и коровы'" << endl;
	cout << "Ваша задача - отгадать число посредством ввода чисел" << endl;
	cout << "Если цифра совпадает, но стоит на другом месте - это корова, если стоит на том же месте - бык" << endl;
	cout << endl;
	cout << "Начнём? (Да/Нет)" << endl;
	cin >> menu;
	if (menu == "Да" || menu == "ДА" || menu == "да")
	{
		system("cls");
		_steps = 0;
		cout << "Введите длину числа:" << endl;;
		cin >> lenght;
		system("cls");
for (int i = 0; i < lenght; i++)
			cout << BullsAndCows.RandomNumber(lenght)[i];
		BullsAndCows.SetLenght(lenght);
	m1:
		cout << endl;
		cout << "Введите ваше число:" << endl;
		cin >> num;
		cout << endl;
		if (BullsAndCows.GetNumber(num) == 1)
		{
			_steps++;
			cout << "Количество коров:" << BullsAndCows.CheckCows() << endl;
			cout << "Количество быков:" << BullsAndCows.CheckBulls() << endl;
			cout << endl;
			if (BullsAndCows.CheckWin(BullsAndCowsWin) == true)
			{
				cout << "Поздравляю! Вы отгадали число за " << _steps << " шага(-ов)" << endl;
				cout << endl;
				system("pause");
				system("cls");
				return 0;
			}
			else
			{
				BullsAndCows.ClearCowsBulls();
				goto m1;
			}
		}
	}

	else
	{
		return 0;
	}
}