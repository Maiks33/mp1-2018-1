#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <ctime>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>


using namespace std;


void Input(int &, int &, int &);
class TTime {

private : 
	int hour, min, sec;
public :
	TTime(int _hour = 0, int _min = 0, int _sec = 0);
	void setTime();
	void timeDiff(int &_hour, int &_min, int &_sec);
	void changeTime(int &_hour, int &_min, int &_sec, int &d);
	void showTime();

	TTime& operator=(const TTime& obj) {
		hour = obj.hour;
		min = obj.min;
		sec = obj.sec;
		return *this;
	}
};



int main(){
	int cur = 1, mode1, mode2, mode3, d = 0;
	int _h = 0, _m = 0, _s = 0;
	TTime T1;
	system("cls");
	while (cur) {
		
		cout << "1. Set time" << endl;
		cout << "2. Exit" << endl;
		cout << "Your choice: ";
		cin >> mode1;

		switch (mode1) {
		case 1: {
		settime:
			T1.setTime();
			system("pause");
			system("cls");
			break;

		}
		case 2: {
			cur = 0;
			break;
		}
		}

		while (cur) {
			system("cls");
			cout << "Current Time: ";
			T1.showTime();
			cout << "1. Move time" << endl;
			cout << "2. Enter time and calculate difference" << endl;
			cout << "3. Exit" << endl;
			cout << "4. Set new time" << endl;
			cout << "Your choice: ";
			cin >> mode2;

			switch (mode2) {
			case 1: {
				cout << "Enter time you want to change it" << endl << endl;
				Input(_h, _m, _s);
				cout << "Select direction" << endl;
				cout << "1. Forward" << endl;
				cout << "2. Backward" << endl;
				cout << "Your choice: ";
				cin >> mode3;
				switch (mode3) {
				case 1: {
					d = 1;
					break;
				}
				case 2: {
					d = 0;
					break;
				}
				
				}
				T1.changeTime(_h, _m, _s, d);
				break;


			}
			case 2: {
				Input(_h, _m, _s);
				T1.timeDiff(_h, _m, _s);
				break;

			}
			case 3: {
				cur = 0;
				break;
			}
			case 4: {
				goto settime;

			}
			}


		}
		
	}
	system("pause");
}
void Input(int &hour, int &min, int &sec) {
	cout << "Enter hour minutes and seconds separately" << endl;
	do {
		cout << "hours from 0 to 23: ";

		cin >> hour;
	} while (hour < 0 || hour > 23);

	do {
		cout << "minutes from 0 to 59: ";
		cin >> min;
	} while (min < 0 || min > 59);
	do {
		cout << "seconds from 0 to 59: ";
		cin >> sec;
	} while (sec < 0 || sec > 59);
	
}
void TTime::showTime() {
	hour %= 24;
	min %= 60;
	sec %= 60;
	cout << (hour + 24) % 24 << ":" << (min + 60) % 60 << ":" << (sec + 60) % 60 << endl;
}
void TTime::timeDiff(int &_hour, int &_min, int &_sec)
{
	if (_sec >= 60) {
		_min += _sec / 60;
		_sec %= 60;
	}
	if (_min >= 60) {
		_hour += _min / 60;
		_min %= 60;
	}
	if (_hour >= 24)_hour %= 24;
	cout << "Difference between entered time and set time is " << abs(hour - _hour) << ":" << abs(min - _min) << ":" << abs(sec - _sec) << endl;
	system("pause");
}
TTime::TTime(int _hour, int _min, int _sec)
{
	hour = _hour;
	min = _min;
	sec = _sec;
}
void TTime::setTime() {
	Input(hour, min, sec);
}
void TTime::changeTime(int &_hour, int &_min, int &_sec, int &d) {
	_hour %= 24;
	_min %= 60;
	_sec %= 60;
	if (d) {
		hour += _hour;
		min += _min;
		sec += _sec;
	}
	else {
		hour -= _hour;
		min -= _min;
		sec -= _sec;
	}

	if (sec >= 60) {
		min += sec / 60;
		sec %= 60;
	}
	if (min >= 60) {
		hour += min / 60;
		min %= 60;
	}
	if (hour >= 24)hour %= 24;
	hour += 24;
	hour %= 24;
	min += 60;
	min %= 60;
	sec += 60;
	sec %= 60;
}
