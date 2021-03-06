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

	FunctionTabulator(FunctionTabulator const &Tabulation) //����������� �����������
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

	FunctionTabulator& operator=(const FunctionTabulator& Tabulation) //�������� ������������
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

	~FunctionTabulator()//����������
	{
		delete[] ResultFunc;
		delete[] Argument;

	}
	void SetFunction(double(*_function)(double)) // ��������� �������
	{
		function = _function;
	}
	void SetStepsCount(double count) //������ ����� �����
	{
		StepsCount = count;
		delete[] ResultFunc;
		ResultFunc = new double[count];
		delete[] Argument;
		Argument = new double[count];
	}

	int ShowStepsCount() //������ ����� �����
	{
		return StepsCount;
	}

	void SetBorder(double x, double max) // ������ ������� �������������
	{
		left = x;
		right = max;
	}

	double ShowLeftBorder()// ������ ����� �������
	{
		return Argument[0];
	}
	double ShowRightBorder()// ������ ������ �������
	{
		return right;
	}
	void Tabulate() // ��������� ��������� �������
	{
		step = (right - left) / StepsCount;
		for (int i = 0; i < StepsCount; i++)
		{
			Argument[i] = left;
			ResultFunc[i] = function(left);
			left += step;
		}
	}
	
	void ShowResultFunc() // ������ ��������� �������������
	{
		step = (right - Argument[0]) / StepsCount;
		for (int i = 0; i < StepsCount; i++)
		{
			cout << "�������� ���������: " << Argument[i] << " �������� �������: " << ResultFunc[i] << endl;;
		}

	}

	void WorkWithFile() // ��������� ��������� ������������� � ����
	{
		step = (right - Argument[0]) / StepsCount;
		ofstream fout("�����.txt"); // ������ ������ ������ ofstream � ����� � ��������
		fout << "���������� ����� �������������: " << StepsCount << endl;
		fout << "����� ������� �������������: " << Argument[0] << endl;
		fout << "������ ������� �������������: " << right << endl;
		for (int i = 0; i < StepsCount; i++)
		{
			fout << "�������� ���������: " << Argument[i] << " �������� �������: " << ResultFunc[i] << endl;
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
		Tab.Tabulate();
		system("cls");
		cout << "����� ������� �������������� " << Tab.ShowLeftBorder() << endl;
		cout << "������ ������� �������������� " << Tab.ShowRightBorder() << endl;
		cout << "���������� ����� �������������� " << Tab.ShowStepsCount() << endl;
		Tab.ShowResultFunc();
		Tab.WorkWithFile();
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
		system("cls");
		Tab.Tabulate();
		cout << "����� ������� �������������� " << Tab.ShowLeftBorder() << endl;
		cout << "������ ������� �������������� " << Tab.ShowRightBorder() << endl;
		cout << "���������� ����� �������������� " << Tab.ShowStepsCount() << endl;
		Tab.ShowResultFunc();
		Tab.WorkWithFile();
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
		system("cls");
		Tab.Tabulate();
		cout << "����� ������� �������������� " << Tab.ShowLeftBorder() << endl;
		cout << "������ ������� �������������� " << Tab.ShowRightBorder() << endl;
		cout << "���������� ����� �������������� " << Tab.ShowStepsCount() << endl;
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