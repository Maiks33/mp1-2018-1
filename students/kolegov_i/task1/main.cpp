#include <iostream>

using namespace std;

class LengthConverter
{
private:
	double meters;
public:
	LengthConverter(int m); 

	//Мне показалась такая реализация наиболее интересной
	//Возможно как-то можно использовать enum
	const int FOOT = 1;
	const int YARD = 2;
	const int ARSHIN = 3;
	const int SAZHEN = 4;
	double ConvertTo(int MeraType);

	double GetLenght();
	void SetLength(double m);
	
	void ToConsole();



};

int main()
{
  cout << "Hello!" << endl;
  return 0;
}
