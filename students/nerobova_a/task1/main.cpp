#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class Rational
{
	int ch;
	int zn;
	int nod;
public:
	int NOD(int ch, int zn);
	int NOK(int zn, int zn1);
	void Print();
	int Numerator(int ch, int nod);
	int Denominator(int zn, int nod);
	void  Rational::PrintRational(int ch, int zn, int nod);
	Rational() : ch(1), zn(1) {}
	Rational(int _ch) : ch(_ch), zn(1) {}
	Rational(int _ch, int _zn) : ch(_ch), zn(_zn)
	{
		if (zn == 0)
		{
			void Print();
			return;
		}
		else
		{
			nod = NOD(ch, zn);
			ch = Numerator(ch, nod);
			zn = Denominator(zn, nod);
			PrintRational(ch, zn, nod);
		}
	}
	Rational& operator+(const Rational& r)
	{
		Rational sum_zn(*this);
		Rational sum_ch(*this);
		if (zn == r.zn)
		{
			sum_ch = ch + r.ch;
			sum_zn = zn;
			return *this;
		}
		else {
			sum_zn = NOK(zn, r.zn);
			sum_ch = (sum_zn / zn*ch) + (sum_zn / r.zn*r.ch);
			return *this;
		}
	}

	Rational& operator-(const Rational& r)
	{
		Rational sub_zn(*this);
		Rational sub_ch(*this);
		if (zn == r.zn)
		{
			sub_ch = ch - r.ch;
			sub_zn = zn;
			return *this;
		}
		else {
			sub_zn = NOK(zn, r.zn);
			sub_ch = (sub_zn / zn*ch) - (sub_zn / r.zn*r.ch);
			return *this;
		}
	}


	Rational& operator*(const Rational& r)
	{
		Rational multi_ch(*this);
		Rational multi_zn(*this);
		int zn1, zn2;
		zn1 = zn * r.zn;
		zn2 = ch * r.ch;
		nod = NOD(ch, zn);
		multi_ch = Numerator(ch, nod);
		multi_zn = Denominator(zn, nod);
		return *this;
	}

	Rational& operator/(const Rational& r)
	{
		Rational div_ch(*this);
		Rational div_zn(*this);
		int zn1, zn2;
		zn1 = zn*r.ch;
		zn2 = ch*r.zn;
		nod = NOD(ch, zn);
		div_ch = Numerator(ch, nod);
		div_zn = Denominator(zn, nod);
		return *this;
	}

	Rational& operator=(const Rational& r)
	{
		ch = r.ch;
		zn = r.zn;
		return *this;
	}
};

void  Rational::Print()
{
	cout << "Fraction of incorrect\n";
}

void  Rational::PrintRational(int ch, int zn, int nod)
{
	ch = ch*nod;
	zn = zn*nod;
	cout << ch << "/" << zn;
}

int Rational::Numerator(int ch, int nod)
{
	ch = ch / nod;
	return ch;
}

int Rational::Denominator(int zn, int nod)
{
	zn = zn / nod;
	return zn;
}


int Rational::NOD(int ch, int zn)
{
	int a, b, tmp;
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

	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
	if (a != 1)
	{
		zn = zn / a;
		ch = ch / a;
	}
}

int Rational::NOK(int zn, int zn1)
{
	int i, nok;
	nok = zn * zn1;
	for (i = nok; i > 0; i--)
		if (i%zn == 0 || i%zn1 == 0)
			nok = i;
	return nok;
}

