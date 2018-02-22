#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

class ConverterLength
{
	double metre;

public:
	ConverterLength(double met = 1) : metre(met) {} //Constructor//

	ConverterLength& operator=(double m)
	{
		metre = m;
		return *this;
	}
	ConverterLength& operator=(const ConverterLength&length)
	{
		metre = length.metre;
		return *this;
	}
	double GetMetre()
	{
		return metre;
	}
	double GetArshin()
	{
		return metre*0.7112;
	}
	double GetFoot()
	{
		return metre*0.3048;
	}
	double GetYard()
	{
		return metre*0.9144;
	}
	double GetSazhen()
	{
		return metre*2.1336;
	}
	double GetPyad()
	{
		return metre*0.1778;
	}
	double GetInch()
	{
		return metre*39.37;
	}
	double GetMile()
	{
		return metre*1609.34;
	}

	void SetMetre(int met)
	{
		metre = met;
	}
	void Metre()
	{
		cout << "Lenght in metres =" << GetMetre() << "\n";
	}
	void Arshin()
	{
		cout << "Lenght in arshin`s =" << GetArshin() << "\n";
	}
	void Foot()
	{
		cout << "Lenght in foot =" << GetFoot() << "\n";
	}
	void Yard()
	{
		cout << "Lenght in yard =" << GetYard() << "\n";
	}
	void Sazhen()
	{
		cout << "Lenght in sazhen`s =" << GetSazhen() << "\n";
	}
	void Pyad()
	{
		cout << "Lenght in pyad =" << GetPyad() << "\n";
	}
	void Inch()
	{
		cout << "Lenght in Inch =" << GetInch() << "\n";
	}
	void Mile()
	{
		cout << "Lenght in mile =" << GetMile() << "\n";
	}
	void SeeAllLenght()
	{
		cout << "Lenght in metres =" << GetMetre() << "\n";
		cout << "Lenght in arshin`s =" << GetArshin() << "\n";
		cout << "Lenght in foot =" << GetFoot() << "\n";
		cout << "Lenght in yard =" << GetYard() << "\n";
		cout << "Lenght in sazhen`s =" << GetSazhen() << "\n";
		cout << "Lenght in pyad =" << GetPyad() << "\n";
		cout << "Lenght in inch =" << GetInch() << "\n";
		cout << "Lenght in mile =" << GetMile() << "\n";
	}
};

void main()
{
	double _m = 0;
	int a, b, c = 1;
	ConverterLength K;
	while (c == 1)
	{
		cout << "Select section:" << "\n" << "1 - Set lenght in meters" << "\n" << "2 - Get lenght in metres" << "\n" << "3 - Get length in all values" << "\n" << "4 - Exit" << "\n";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << "Lenght in metres =";
			cin >> _m;
			K.SetMetre(_m);
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			K.Metre();
			system("pause");
			system("cls");
			break;
		}
		case 3:
			cout << "Select value:" << "\n" << "1 - Arshin\n" << "2 - Foot\n" << "3 - Yard\n" << "4 - Sazhen\n" << "5 - Pyad\n" << "6 - Inch\n" << "7 - mile\n";
			cin >> b;
			switch (b)
			{
			case 1:
			{
				K.Arshin();
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				K.Foot();
				system("pause");
				system("cls");
				break;
			}
			case 3:
			{
				K.Yard();
				system("pause");
				system("cls");
				break;
			}
			case 4:
			{
				K.Sazhen();
				system("pause");
				system("cls");
				break;
			}
			case 5:
			{
				K.Pyad();
				system("pause");
				system("cls");
				break;
			}
			case 6:
			{
				K.Inch();
				system("pause");
				system("cls");
				break;
			}
			case 7:
			{
				K.Mile();
				system("pause");
				system("cls");
				break;
			}
			}
		case 4:
		{
			c = 0;
		}
		}
	}
	system("pause");

}
