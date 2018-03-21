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

	FunctionTabulator(FunctionTabulator const &Tabulation) //конструктор копирования
	{
		StepsCount = Tabulation.StepsCount;
		left = Tabulation.left;
		right = Tabulation.right;
		ResultFunc = new double[StepsCount];
		Argument = new double[StepsCount];
		for (int i = 0; i < StepsCount; i++)
		{
			ResultFunc[i] = Tabulation.ResultFunc[i];
			Argument[i] = Tabulation.Argument[i];
		}
	}

	FunctionTabulator& operator=(const FunctionTabulator& Tabulation) //оператор присваивания
	{
		if (this == &Tabulation)
			return *this;
		if (StepsCount != Tabulation.StepsCount)
		{
			delete[] ResultFunc;
			delete[] Argument;
			ResultFunc = new double[Tabulation.StepsCount];
			Argument = new double[Tabulation.StepsCount];
			StepsCount = Tabulation.StepsCount;
		}
		left = Tabulation.left;
		right = Tabulation.right;
		for (int i = 0; i < StepsCount; i++)
		{
			ResultFunc[i] = Tabulation.ResultFunc[i];
			Argument[i] = Tabulation.Argument[i];
		}
	}

	~FunctionTabulator()//деструктор
	{
		delete[] ResultFunc;
		delete[] Argument;

	}
	void SetFunction(double(*_function)(double)) // установка функции
	{
		function = _function;
	}
	void SetStepsCount(double count) //задать число точек
	{
		StepsCount = count;
		delete[] ResultFunc;
		ResultFunc = new double[count];
		delete[] Argument;
		Argument = new double[count];
	}

	int ShowStepsCount() //узнать число точек
	{
		return StepsCount;
	}

	void SetBorder(double x, double max) // задать отрезок табулирования
	{
		left = x;
		right = max;
	}

	double ShowLeftBorder()// узнать левую границу
	{
		return Argument[0];
	}
	double ShowRightBorder()// узнать правую границу
	{
		return right;
	}
	void Tabulate() // выполнить табуляцию функции
	{
		step = (right - left) / StepsCount;
		for (int i = 0; i < StepsCount; i++)
		{
			Argument[i] = left;
			ResultFunc[i] = function(left);
			left += step;
		}
	}
	
	void ShowResultFunc() // выдать результат табулирования
	{
		step = (right - Argument[0]) / StepsCount;
		for (int i = 0; i < StepsCount; i++)
		{
			cout << "Значение аргумента: " << Argument[i] << " Значение функции: " << ResultFunc[i] << endl;;
		}

	}

	void WorkWithFile() // сохранить результат табулирования в файл
	{
		step = (right - Argument[0]) / StepsCount;
		ofstream fout("Отчёт.txt"); // создаём объект класса ofstream в папке с проектом
		fout << "Количество точек табулирования: " << StepsCount << endl;
		fout << "Левая граница табулирования: " << Argument[0] << endl;
		fout << "Правая граница табулирования: " << right << endl;
		for (int i = 0; i < StepsCount; i++)
		{
			fout << "Значение аргумента: " << Argument[i] << " Значение функции: " << ResultFunc[i] << endl;
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
		system("cls");
		cout << "Левая граница таблурирования " << Tab.ShowLeftBorder() << endl;
		cout << "Правая граница таблурирования " << Tab.ShowRightBorder() << endl;
		cout << "Количество шагов табулироваяния " << Tab.ShowStepsCount() << endl;
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
		system("cls");
		Tab.Tabulate();
		cout << "Левая граница таблурирования " << Tab.ShowLeftBorder() << endl;
		cout << "Правая граница таблурирования " << Tab.ShowRightBorder() << endl;
		cout << "Количество шагов табулироваяния " << Tab.ShowStepsCount() << endl;
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
		system("cls");
		Tab.Tabulate();
		cout << "Левая граница таблурирования " << Tab.ShowLeftBorder() << endl;
		cout << "Правая граница таблурирования " << Tab.ShowRightBorder() << endl;
		cout << "Количество шагов табулироваяния " << Tab.ShowStepsCount() << endl;
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