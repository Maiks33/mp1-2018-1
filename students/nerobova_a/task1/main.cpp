#include <iostream>
using namespace std;

class Racional
{
	int ch;
	int zn;
	int nod, tmp, a, b;
public:
	Racional() : ch(1), zn(1) {}
	Racional(int _ch) : ch(_ch), zn(1) {}
	Racional(int _ch, int _zn) : ch(_ch), zn(_zn)
	{
		if (zn == 0)
		{
			cout << "Fracion is incorrect\n";
			return;
		}
		else
		{

			if (ch > zn)
			{
				a = ch;
				b = zn;
			}
			else
			{
				a = zn;
				b = ch;
			}

			while (b != 0) {  // a - NOD
				tmp = a % b;
				a = b;
				b = tmp;
			}

			nod = a;

			if (nod != 1)	// снаходм несократимую 
			{

			}

		}
	}
	Racional operator+=(const Racional& r)
	{
		ch += r.ch;
		zn += r.zn;
		return *this;
	}

	Racional& operator=(const Racional& r)
	{
		ch = r.ch;
		zn = r.zn;
		return *this;
	}
};


int main()
{
  cout << "Hello!" << endl;
  return 0;
}
