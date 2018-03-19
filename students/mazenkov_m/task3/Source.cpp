#include <iostream>
#include <cstdio>
#include <fstream>

#define PI 3.14

using namespace std;

class FunctionTabulator
{
	double StepsCount;
	double left;
	double right;
	double step;
	double *ResultFunc;
	double *Argument;
	double(*function)(double);
public:
	FunctionTabulator(double _StepsCount = 0, double _left = 0, double _right = 0, double _step = 0)
	{
		StepsCount = _StepsCount;
		left = _left;
		right = _right;
		step = _step;
		ResultFunc = new double[_StepsCount];
		Argument = new double[_StepsCount];
	}
	~FunctionTabulator()
	{
		delete[] ResultFunc;
		delete[] Argument;

	}
	void SetFunction(double(*_function)(double)) // установка функции
	{
		function = _function;
	}

	void SetBorder(double x, double max) // установка границ табулирования
	{
		left = x;
		right = max;
	}

	void SetStepsCount(double count) //счётчик шагов
	{
		StepsCount = count;
		delete[] ResultFunc;
		ResultFunc = new double[count];
		delete[] Argument;
		Argument = new double[count];
	}

	void Tabulate() // табулирование функции
	{
		step = (right - left) / StepsCount;
		for (int i = 0; i < StepsCount; i++)
		{
			Argument[i] = left;
			ResultFunc[i] = function(left);
			left += step;
		}
	}

	void ShowResultFunc() // вывод результата табулирования
	{
		step = (right - left) / StepsCount;
		cout << "Количество точек табулирования: " << StepsCount << endl;
		cout << "Левая граница табулирования: " << left << endl;
		cout << "Правая граница табулирования: " << right << endl;
		cout << "Шаг табуляции: " << step << endl;
		for (int i = 0; i < StepsCount; i++)
		{
			cout << "Значение аргумента: " << Argument[i] << " Значение функции: " << ResultFunc[i] << endl;;
			left += step;
		}

	}

	void WorkWithFile() // работа с файлом
	{
		step = (right - left) / StepsCount;
		ofstream fout("Отчёт.txt"); // создаём объект класса ofstream в папке с проектом
		fout << "Количество точек табулирования: " << StepsCount << endl;
		fout << "Левая граница табулирования: " << left << endl;
		fout << "Правая граница табулирования: " << right << endl;
		fout << "Шаг табуляции: " << step << endl;
		for (int i = 0; i < StepsCount; i++)
		{
			fout << "Значение аргумента: " << Argument[i] << " Значение функции: " << ResultFunc[i] << endl;
			left += step;
		}
		fout.close();
	}
};

double Square(double x) // Функция квадрат числа
{
	return x * x;
}

double Cube(double x) // Функция куб числа
{
	return x * x * x;
}

double Sin(double x) // функция синуса
{
	return sin(x * (PI / 180));
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double x;
	double max;
	int menu;
	double count;
	double(*func)(double);
rep:
	system("cls");
	cout << "Выберите, с какой функцией хотите работать:" << endl;
	cout << "1 - квадрат числа" << endl;
	cout << "2 - куб числа" << endl;
	cout << "3 - синус" << endl;
	cout << "4 - выход" << endl;
	cin >> menu;
	system("cls");
	switch (menu)
	{
	case 1:
	{
		cout << "Вы работаете с фунцией: Квадрат числа" << endl;
		func = Square;
		FunctionTabulator Tab;
		Tab.SetFunction(func);
		cout << "Введите количество точек табуляции " << endl;
		cin >> count;
		Tab.SetStepsCount(count);
		cout << "Введите границы табуляции " << endl;
		cout << "Табулировать от: "; cin >> x; cout << "До: "; cin >> max;
		Tab.SetBorder(x, max);
		Tab.Tabulate();
		Tab.ShowResultFunc();
		Tab.WorkWithFile();
		system("pause");
		goto rep;
	}
	case 2:
	{
		cout << "Вы работаете с фунцией: Куб числа" << endl;
		func = Cube;
		FunctionTabulator Tab;
		Tab.SetFunction(func);
		cout << "Введите количество точек табуляции " << endl;
		cin >> count;
		Tab.SetStepsCount(count);
		cout << "Введите границы табуляции " << endl;
		cout << "Табулировать от: "; cin >> x; cout << "До: "; cin >> max;
		Tab.SetBorder(x, max);
		Tab.Tabulate();
		Tab.ShowResultFunc();
		Tab.WorkWithFile();
		system("pause");
		goto rep;
	}
	case 3:
	{
		cout << "Вы работаете с фунцией: Синус" << endl;
		func = Sin;
		FunctionTabulator Tab;
		Tab.SetFunction(func);
		cout << "Введите количество точек табуляции " << endl;
		cin >> count;
		Tab.SetStepsCount(count);
		cout << "Введите границы табуляции " << endl;
		cout << "Табулировать от: "; cin >> x; cout << "До: "; cin >> max;
		Tab.SetBorder(x, max);
		Tab.Tabulate();
		Tab.ShowResultFunc();
		Tab.WorkWithFile();
		system("pause");
		goto rep;
	}
	case 4:
	{
		return 0;
	}
	}

}