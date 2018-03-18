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
	double *Result;
	double(*function)(double);
public:
	FunctionTabulator(double _StepsCount = 0, double _left = 0, double _right = 0, double _step = 0)
	{
		StepsCount = _StepsCount;
		left = _left;
		right = _right;
		step = _step;
		Result = new double[_StepsCount];
	}

	void SetFunction(double(*_function)(double)) // ��������� �������
	{
		function = _function;
	}

	void SetBorder(double x, double max) // ��������� ������ �������������
	{
		left = x;
		right = max;
	}

	void SetStepsCount(double count) //������� �����
	{
		StepsCount = count;
		delete[] Result;
		Result = new double[count];
	}

	void Tabulate(double x) // ������������� �������
	{
		step = (right - x) / StepsCount;
		for (int i = 0; i < StepsCount; i++)
		{
			Result[i] = function(x);
			x += step;
		}
	}

	void ShowResult(double x) // ����� ���������� �������������
	{
		step = (right - x) / StepsCount;
		cout << "���������� ����� �������������: " << StepsCount << endl;
		cout << "����� ������� �������������: " << x << endl;
		cout << "������ ������� �������������: " << right << endl;
		cout << "��� ���������: " << step << endl;
		for (int i = 0; i < StepsCount; i++)
		{
			cout << "�������� ���������: " << x << endl;
			cout << "�������� �������: " << Result[i] << endl;
			x += step;
		}

	}

	void WorkWithFile(double x) // ������ � ������
	{
		step = (right - x) / StepsCount;
		ofstream fout("�����.txt"); // ������ ������ ������ ofstream � ����� � ��������
		fout << "���������� ����� �������������: " << StepsCount << endl;
		fout << "����� ������� �������������: " << x << endl;
		fout << "������ ������� �������������: " << right << endl;
		fout << "��� ���������: " << step << endl;
		for (int i = 0; i < StepsCount; i++)
		{
			fout << "�������� ���������: " << x << endl;
			fout << "�������� �������: " << Result[i] << endl;
			x += step;
		}
		fout.close();
	}
};

double Square(double x) // ������� ������� �����
{
	return x * x;
}

double Cube(double x) // ������� ��� �����
{
	return x * x * x;
}

double Sin(double x) // ������� ������
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
	cout << "��������, � ����� �������� ������ ��������:" << endl;
	cout << "1 - ������� �����" << endl;
	cout << "2 - ��� �����" << endl;
	cout << "3 - �����" << endl;
	cout << "4 - �����" << endl;
	cin >> menu;
	system("cls");
	switch (menu)
	{
	case 1:
	{
		cout << "�� ��������� � �������: ������� �����" << endl;
		func = Square;
		FunctionTabulator Tab;
		Tab.SetFunction(func);
		cout << "������� ���������� ����� ��������� " << endl;
		cin >> count;
		Tab.SetStepsCount(count);
		cout << "������� ������� ��������� " << endl;
		cout << "������������ ��: "; cin >> x; cout << "��: "; cin >> max;
		Tab.SetBorder(x, max);
		Tab.Tabulate(x);
		Tab.ShowResult(x);
		Tab.WorkWithFile(x);
		system("pause");
		goto rep;
	}
	case 2:
	{
		cout << "�� ��������� � �������: ��� �����" << endl;
		func = Cube;
		FunctionTabulator Tab;
		Tab.SetFunction(func);
		cout << "������� ���������� ����� ��������� " << endl;
		cin >> count;
		Tab.SetStepsCount(count);
		cout << "������� ������� ��������� " << endl;
		cout << "������������ ��: "; cin >> x; cout << "��: "; cin >> max;
		Tab.SetBorder(x, max);
		Tab.Tabulate(x);
		Tab.ShowResult(x);
		Tab.WorkWithFile(x);
		system("pause");
		goto rep;
	}
	case 3:
	{
		cout << "�� ��������� � �������: �����" << endl;
		func = Sin;
		FunctionTabulator Tab;
		Tab.SetFunction(func);
		cout << "������� ���������� ����� ��������� " << endl;
		cin >> count;
		Tab.SetStepsCount(count);
		cout << "������� ������� ��������� " << endl;
		cout << "������������ ��: "; cin >> x; cout << "��: "; cin >> max;
		Tab.SetBorder(x, max);
		Tab.Tabulate(x);
		Tab.ShowResult(x);
		Tab.WorkWithFile(x);
		system("pause");
		goto rep;
	}
	case 4:
	{
		return 0;
	}
	}

}