#include <iostream>
#include <locale>

using namespace std;

/*********************************************************************************************
 =============================================================================================
|      ___  ________   _________  _______   ________  _______   ________                      |
|     |\  \|\   ___  \|\___   ___\\  ___ \ |\   ____\|\  ___ \ |\   __  \                     |
|     \ \  \ \  \\ \  \|___ \  \_\ \   __/|\ \  \___|\ \   __/|\ \  \|\  \                    |
|      \ \  \ \  \\ \  \   \ \  \ \ \  \_|/_\ \  \  __\ \  \_|/_\ \   _  _\                   |
|       \ \  \ \  \\ \  \   \ \  \ \ \  \_|\ \ \  \|\  \ \  \_|\ \ \  \\  \|                  |
|        \ \__\ \__\\ \__\   \ \__\ \ \_______\ \_______\ \_______\ \__\\ _\                  |
|         \|__|\|__| \|__|    \|__|  \|_______|\|_______|\|_______|\|__|\|__|                 |
|                                                                                             |
|  ___  ___  ________   ___       ___  _____ ______   ___  _________  _______   ________      |
| |\  \|\  \|\   ___  \|\  \     |\  \|\   _ \  _   \|\  \|\___   ___\\  ___ \ |\   ___ \     |
| \ \  \\\  \ \  \\ \  \ \  \    \ \  \ \  \\\__\ \  \ \  \|___ \  \_\ \   __/|\ \  \_|\ \    |
|  \ \  \\\  \ \  \\ \  \ \  \    \ \  \ \  \\|__| \  \ \  \   \ \  \ \ \  \_|/_\ \  \ \\ \   |
|   \ \  \\\  \ \  \\ \  \ \  \____\ \  \ \  \    \ \  \ \  \   \ \  \ \ \  \_|\ \ \  \_\\ \  |
|    \ \_______\ \__\\ \__\ \_______\ \__\ \__\    \ \__\ \__\   \ \__\ \ \_______\ \_______\ |
|     \|_______|\|__| \|__|\|_______|\|__|\|__|     \|__|\|__|    \|__|  \|_______|\|_______| |
|                                                                                             |
 =============================================================================================                          
 Integer Unlimited
 Класс TUInt представляет из себя относительно новый тип данных, способный производить 
 базовые арифметические операции с большими положительными числами. Длина устанавливается 
 самим разработчиком.

 Базовая длина составляет 20 символов, что эквивалентно 2^64 значений.
 Чтобы изменить количество символов, требуется изменить значение константы SIZE

 UTF8 Code 2

 *********************************************************************************************/


class TUInt {

	#define SIZE 20
	char dArray[SIZE];
	bool isNegative = false;

private:
	void initial()
	{
		for (char i = 0; i < SIZE; i++)
			dArray[i] = '0';
	}
	//Преобразует символ в цифру
	int atoi(char t)
	{
		switch (t)
		{
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;

		default: return 0;
		}
	}
	//Преобразует цифру в символ
	char untoi(int t)
	{
		switch (t)
		{
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';

		default: return '0';
		}
	}
	void LevelUp()
	{
		bool originNegative = isNegative;
		for (int i = SIZE; i > 0; i--)
			dArray[i] = dArray[i - 1];
		dArray[0] = '0';
		isNegative = originNegative;
	}
public:

	TUInt()
	{
		initial();
	}

	TUInt(char c)
	{
		initial();
		dArray[0] = c;
	}

	TUInt(char c[])
	{
		int sLength = strlen(c);
		initial();

		if (sLength <= SIZE)
		{
			for (int i = 0, j = sLength - 1; i < SIZE && c[j] != '\0'; i++, j--)
			{
				if (c[j] == '-')
					isNegative = true;
				dArray[i] = c[j];
			}
		}
	}

	TUInt(int c)
	{
		initial();

		if (c < 0)
			isNegative = true;

		for (int i = 0; i < SIZE; i++)
		{
			dArray[i] = untoi(c % 10);
			c /= 10;
		}
	}

	TUInt(long c)
	{
		initial();

		if (c < 0)
			isNegative = true;

		for (int i = 0; i < SIZE; i++)
		{
			dArray[i] = untoi(c % 10);
			c /= 10;
		}
	}

	TUInt(long long c)
	{
		initial();

		if (c < 0)
			isNegative = true;

		for (int i = 0; i < SIZE; i++)
		{
			dArray[i] = untoi(c % 10);
			c /= 10;
		}
	}

	TUInt operator+(const TUInt &c)
	{
		TUInt tResult;
		int tSumm = 0; // Временная сумма
		int tRemndr; // Временный остаток
		for (int i = 0; i < SIZE; i++)
		{
			// Складываем сумму текущего порядка и предыдущего
			tSumm = (isNegative ? -1 : 1)*atoi(dArray[i]) + (c.isNegative ? -1 : 1)*atoi(c.dArray[i]) + tSumm;
			tRemndr = tSumm % 10; // Остаток от базы - последняя цифра
			if (tRemndr < 0)//При отправке
			{
				tRemndr += 10;
				tSumm -= 10;
			}
			tResult.dArray[i] = untoi(tRemndr);
			tSumm /= 10;
		}
		return tResult;
	}
	TUInt operator-(const TUInt &c)
	{
		TUInt tResult;
		int tSumm = 0;
		int tRemndr;
		for (int i = 0; i < SIZE; i++)
		{
			tSumm = (isNegative ? -1 : 1)*atoi(dArray[i]) - (c.isNegative ? -1 : 1)*atoi(c.dArray[i]) + tSumm;
			tRemndr = tSumm % 10;
			if (tRemndr < 0)
			{
				tRemndr = 10 + tRemndr;
				tSumm -= 10;
			}
			tResult.dArray[i] = untoi(tRemndr);
			tSumm /= 10;
		}
		return tResult;
	}
	TUInt operator*(const TUInt &c)
	{
		TUInt tSumm;
		TUInt tResult;
		int tRemndr_1 = 0; //остаток
		int tRemndr_2 = 0; //остаток на разряд выше

		for (int j = 0; j < SIZE; j++)
		{
			for (int i = 0; i < SIZE - j; i++)
			{
				if (c.dArray[j] == '0') // Пропускаем 0 при умноженииё
					continue;

				tRemndr_2 = atoi(dArray[i]) * atoi(c.dArray[j]); // Произведение двух чисел
				tSumm.dArray[i + j] = untoi((tRemndr_2 += tRemndr_1) % 10); // Записываем число в массив
				tRemndr_1 = tRemndr_2 / 10; // Сдвигаем 
			}
			tResult = tResult + tSumm; // Суммируем промежуточные произведение
			tSumm = "0"; // Обнуляем всё
		}
		tResult.isNegative = (isNegative && c.isNegative) || (isNegative && !c.isNegative) || (!isNegative && c.isNegative); // Определяем знак
		return tResult;
	}

	bool operator==(const TUInt &c)
	{
		for (int i = 0; i < SIZE; i++)
			if (dArray[i] != c.dArray[i])
				return false;
		return true;
	}
	bool operator<(const TUInt &c)
	{
	for (int i = SIZE; i >= 0; i--)
		{
			//если элемент массива меньше , возвращает true
		if (atoi(dArray[i]) < atoi(c.dArray[i]))
			if (*this == (TUInt)c)
				return false;
			else
				return true;
			//если элемент массива больше , возвращает false
			if (atoi(dArray[i]) > atoi(c.dArray[i]))
				return false;
		}
		return false;
	}
	bool operator>(const TUInt &c)
	{
		for(int i = SIZE; i <= 0; i--)
		{
			if (atoi(dArray[i]) > atoi(c.dArray[i]))
				if (*this == (TUInt)c)
					return false;
				else
					return true;

			if (atoi(dArray[i]) < atoi(c.dArray[i]))
				return false;
		}
		return false;
	}
	bool operator<=(const TUInt &c)
	{
		for (int i = SIZE; i >= 0; i--)
		{
			//если элемент массива меньше , возвращает true
			if (atoi(dArray[i]) < atoi(c.dArray[i]))
				return true;
			//если элемент массива больше , возвращает false
			if (atoi(dArray[i]) > atoi(c.dArray[i]))
				return false;
		}
	}
	bool operator>=(const TUInt &c)
	{
		for (int i = SIZE; i >= 0; i--)
		{
			if (atoi(dArray[i]) > atoi(c.dArray[i]))
				return true;

			if (atoi(dArray[i]) < atoi(c.dArray[i]))
				return false;
		}
	}

	TUInt operator/(const TUInt &c)
	{
		int i = SIZE;
		TUInt tResult;
		TUInt dividendPart;//Промежуточное произведение
						   //Работаем с модулями чисел
		TUInt divider(abs(c));// Делитель
		TUInt dividend(abs(*this));// Делимое

		if (divider == (TUInt)0)
		{
			throw "DEVIDE BY ZERO";
			return 0;
		}

		bool started = false;

		do
		{
			while (dividendPart < divider && i-- > 0)
			{
				dividendPart.LevelUp();
				dividendPart.dArray[0] = dividend.dArray[i];
				if (dividend.dArray[i] != '0')
					started = true;
				if ((dividendPart < divider) && started && dividend.dArray[i] != '0')
					tResult.LevelUp();
			}
			while (dividendPart >= divider)
			{
				dividendPart = dividendPart - divider;
				tResult = tResult + "1";
			}
			if (i <= 0)
				break;

			tResult.LevelUp();
		} while (i > 0);

		//Определяем знак
		tResult.isNegative = (isNegative && c.isNegative) || (isNegative && !c.isNegative) || (!isNegative && c.isNegative);
		return tResult;
	}
	TUInt operator%(const TUInt &c)
	{
		int i = SIZE;
		TUInt tResult;
		TUInt dividendPart;//Промежуточное произведение
		//Работаем с модулями чисел
		TUInt divider(abs(c));// Делитель
		TUInt dividend(abs(*this));// Делимое

		if (divider == (TUInt)0)
		{
			throw "DEVIDE BY ZERO";
			return 0;
		}

		bool started = false;

		do
		{
			while (dividendPart < divider && i-- > 0)
			{
				dividendPart.LevelUp();
				dividendPart.dArray[0] = dividend.dArray[i];
				if (dividend.dArray[i] != '0')
					started = true;
				if ((dividendPart < divider) && started && dividend.dArray[i] != '0')
					tResult.LevelUp();
			}
			while (dividendPart >= divider)
			{
				dividendPart = dividendPart - divider;
				tResult = tResult + "1";
			}
			if (i <= 0)
				break;

			tResult.LevelUp();
		} while (i > 0);
		//Определяем знак
		tResult.isNegative = (isNegative && c.isNegative) || (isNegative && !c.isNegative) || (!isNegative && c.isNegative);

		tResult = (*this) - tResult * c;

		return tResult;
	}
	TUInt abs(const TUInt &c)
	{
		TUInt tResult(c);
		for (int i = 0; i < SIZE; i++)
			if (tResult.dArray[i] == '-')
				tResult.dArray[i] = '0';
		tResult.isNegative = false;
		return tResult;
	}
	friend ostream& operator<<(ostream& os, TUInt &c);
	//friend ostream& operator>>(ostream& os, TUInt &c);
};
ostream& operator<<(ostream& os, TUInt &c)
{
	bool trigger = false;
	if (c.isNegative && !(c == (TUInt)0))
		os << '-';
	for (int i = 0; i < SIZE; i++)
	{
		if (c.dArray[SIZE - 1 - i] != '0')
			trigger = true;

		if (trigger)
			if (c.dArray[SIZE - 1 - i] != '-')
				os << c.dArray[SIZE - 1 - i];
	}
	if (!trigger)
		os << 0;
	return os;
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	TUInt i = 25;
	TUInt j = 5;

	cout << "Обычные числа: " << endl;
	cout << i << " + " << j << " = " << i + j << endl;
	cout << i << " - " << j << " = " << i - j << endl;
	cout << i << " * " << j << " = " << i * j << endl;
	cout << i << " / " << j << " = " << i / j << endl;
	cout << i << " % " << j << " = " << i % j << endl;
	cout << endl;

	i = "98219407219253";
	j = 2891;

	cout << "Длинные числа: " << endl;
	cout << i << " + " << j << " = " << i + j << endl;
	cout << i << " - " << j << " = " << i - j << endl;
	cout << i << " * " << j << " = " << i * j << endl;
	cout << i << " / " << j << " = " << i / j << endl;
	cout << i << " % " << j << " = " << i % j << endl;
	cout << endl;

	i = "10";
	j = 10;

	cout << "Сравнения чисел: " << endl;
	cout << i << " < " << j << " = " << (i < j ? "true" : "false") << endl;
	cout << i << " <= " << j << " = " << (i <= j ? "true" : "false") << endl;
	cout << i << " > " << j << " = " << (i > j ? "true" : "false") << endl;
	cout << i << " >= " << j << " = " << (i >= j ? "true" : "false") << endl;
	cout << endl;

	i = "2382194072192535";
	j = "9821940721925309";

	cout << i << " < " << j << " = " << (i < j ? "true" : "false") << endl;
	cout << i << " <= " << j << " = " << (i <= j ? "true" : "false") << endl;
	cout << i << " > " << j << " = " << (i > j ? "true" : "false") << endl;
	cout << i << " >= " << j << " = " << (i >= j ? "true" : "false") << endl;
	system("pause");
	return 0;
}