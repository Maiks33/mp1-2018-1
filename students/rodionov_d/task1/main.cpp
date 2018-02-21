#include <iostream>
#include <locale.h>

using namespace std;

class TWeightScales
{
private:
	double kg; // weight in kg
public:
	TWeightScales(double _kg = 0)// constructor
	{
		kg = _kg;
	}
	TWeightScales & operator=(const TWeightScales & kg1) 
	{
		kg = kg1.kg;
		return *this;
	}
	void setWeight(double _kg) //set weight 
	{
		kg = _kg;
	}
	void print() // output on display
	{
		cout << "Weight in kg: " << kg << endl;
	}
	double killograms() 
	{
		return kg;
	}
	double pharmacyPound() //conversion to the pharmacy pound 
	{
		return kg * 2.2679;
	}

	double troyOunce() // conversion to the troy ounce
	{
		return kg * 35.2739;
	}
	double pood() // conversion to the pood
	{
		return kg * 0.061;
	}
	void printPharmacyPound()
	{
		cout << "Weight in pharmacy pound:" << pharmacyPound() << endl;
	}
	void printTroyOunce()
	{
		cout << "Weight in troy ounce:" << troyOunce() << endl;
	}
	void printPood()
	{
		cout << "Weight in pood:" << pood() << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	double flag;
	int a, b;
	TWeightScales weight1, weight2, weight3(20);
	weight1 = weight3; // verification of the assignment operator
metka2:cout << "Enter the weight in kilograms:";
	cin >> flag;
	weight2.setWeight(flag);

metka3:cout << "\n Select an action:\n" << endl;
	cout << "1. Display the current weight in kilograms\n" << endl;
	cout << "2. Display the weight of the selected unit\n" << endl;
	cout << "3. Change the weight in kilograms\n" << endl;
	cin >> a;
	switch (a)
	{
	case 1: weight2.print(); break;
	case 2:
	{
	metka1:cout << "In which unit of measurement do you prefer to know the weight?\n" << endl;
		cout << "1. Pharmacy fund" << endl;
		cout << "2. Troy ounce" << endl;
		cout << "3. Pood" << endl;
		cin >> b;
		switch (b)
		{
		case 1: weight2.printPharmacyPound(); break;
		case 2: weight2.printTroyOunce(); break;
		case 3: weight2.printPood(); break;
		default: cout << "Incorrect entry. Please try again.\n"; goto metka1;
		}
		break;
	}
	case 3: goto metka2;
	default: cout << "Incorrect entry. Please try again.\n"; goto metka3;
	}
	system("pause");
}