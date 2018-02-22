#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class Rational
{
	int ch;
	int zn;
	int nod;
	int Numerator(int ch, int nod);
	int Denominator(int zn, int nod);
public:
	int NOD(int ch, int zn);
	int NOK(int zn, int zn1);
	void Print();
	
	void PrintRational(int ch, int zn, int nod);
	Rational() : ch(1), zn(1) {}
	Rational(int _ch) : ch(_ch), zn(1) {}
	Rational(int _ch, int _zn) : ch(_ch), zn(_zn)
	{
	nod = NOD(ch, zn);
	ch = Numerator(ch, nod);
	zn = Denominator(zn, nod);
	}
	Rational operator+(const Rational r)
	{
		Rational sum(*this);
		if (zn == r.zn)
		{
			sum.ch = ch + r.ch;
			sum.zn = zn;
			return sum;
		}
		else {
			sum.zn = NOK(zn, r.zn);
			sum.ch = (zn / zn*ch) + (zn / r.zn*r.ch);
			return sum;
		}
	}

	Rational& operator-(const Rational& r)
	{
		Rational sub(*this);
		if (zn == r.zn)
		{
			sub.ch = ch - r.ch;
			sub.zn = zn;
			return sub;
		}
		else {
			sub.zn = NOK(zn, r.zn);
			sub.ch = (sub.zn / zn*ch) - (sub.zn / r.zn*r.ch);
			return sub;
		}
	}


	Rational& operator*(const Rational& r)
	{
		Rational multi(*this);
		int zn1, ch1;
		zn1 = zn * r.zn;
		ch1 = ch * r.ch;
		nod = NOD(ch1, zn1);
		multi.ch = Numerator(ch1, nod);
		multi.zn = Denominator(zn1, nod);
		return multi;
	}

	Rational& operator/(const Rational& r)
	{
		Rational div(*this);
		int zn1, ch1;
		ch1 = ch*r.zn;
		zn1 = zn*r.ch;
		nod = NOD(ch1, zn1);
		div.ch = Numerator(ch1, nod);
		div.zn = Denominator(zn1, nod);
		return div;
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

