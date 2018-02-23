#include <iostream>
using namespace std;

class int64 {
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

	int64()
	{
		initial();
	}

	int64(char c)
	{
		initial();
		dArray[0] = c;
	}

	int64(char c[])
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

	int64(int c)
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

	int64(long c)
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

	int64(long long c)
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

	int64 operator+(const int64 &c)
	{
		int64 tResult;
		int tSumm = 0; // Временная сумма
		int tRemndr; // Временный остаток
		for (int i = 0; i < SIZE; i++)
		{
			// Складываем сумму текущего порядка и предыдущего
			tSumm = (isNegative ? -1 : 1)*atoi(dArray[i]) + (c.isNegative ? -1 : 1)*atoi(c.dArray[i]) + tSumm;
			tRemndr = tSumm % 10;
			if (tRemndr < 0)
			{
				tRemndr += 10;
				tSumm -= 10;
			}
			tResult.dArray[i] = untoi(tRemndr);
			tSumm /= 10;
		}
		return tResult;
	}
	int64 operator-(const int64 &c)
	{
		int64 tResult;
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
	int64 operator*(const int64 &c)
	{
		int64 tSumm;
		int64 tResult;
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

	bool operator==(const int64 &c)
	{
		for (int i = 0; i < SIZE; i++)
			if (dArray[i] != c.dArray[i])
				return false;
		return true;
	}
	bool operator<(const int64 &c)
	{
		int i = SIZE;
		while (true)
		{
			if (atoi(dArray[i]) < atoi(c.dArray[i]))
				if (*this == c) // для строгого условия
					return false;
				else
					return true;

			if (atoi(dArray[i]) > atoi(c.dArray[i]))
				return false;

			i--;
		}
	}
	bool operator>(const int64 &c)
	{
		int i = SIZE;
		while (true)
		{
			if (atoi(dArray[i]) > atoi(c.dArray[i]))
				if (*this == c)
					return false;
				else
					return true;

			if (atoi(dArray[i]) < atoi(c.dArray[i]))
				return false;
			i--;
		}
	}
	bool operator<=(const int64 &c)
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
	bool operator>=(const int64 &c)
	{
		for (int i = SIZE; i >= 0; i--)
		{
			if (atoi(dArray[i]) > atoi(c.dArray[i]))
				return true;
			if (atoi(dArray[i]) < atoi(c.dArray[i]))
				return false;
		}
	}

	int64 operator/(int64 &c)
	{
		if (c == (int64)0)
		{
			throw "DEVIDE BY ZERO";
			return 0;
		}

		int i = SIZE;
		int64 tResult;
		int64 dividendPart;//Промежуточное произведение
						   //работаем с модулями чисел
		int64 divider(abs(c));// Делитель
		int64 dividend(abs(*this));// Делимое

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
	int64 operator%(int64 &c)
	{
		if (c == (int64)0)
		{
			throw "DEVIDE BY ZERO";
			return 0;
		}



		int i = SIZE;
		int64 tResult;
		int64 dividendPart;//Промежуточное произведение
						   //работаем с модулями чисел
		int64 divider(abs(c));// Делитель
		int64 dividend(abs(*this));// Делимое

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
	int64 abs(const int64 &c)
	{
		int64 tResult(c);
		for (int i = 0; i < SIZE; i++)
			if (tResult.dArray[i] == '-')
				tResult.dArray[i] = '0';
		tResult.isNegative = false;
		return tResult;
	}
	friend ostream& operator<<(ostream& os, int64 &c);
};
ostream& operator<<(ostream& os, int64 &c)
{
	bool trigger = false;
	if (c.isNegative && !(c == (int64)0))
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

	int64 t = 25;
	int64 j = 2;
	cout << t << " % " << j << " = " << t % j << endl;
	system("pause");
	return 0;
}