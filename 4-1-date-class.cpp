#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef DATE
#define DATE
class Date {
private:
	int month, day, year;
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
public:
	int getMonth() const {
		return month;
	}
	int getDay() const {
		return day;
	}
	int getYear() const {
		return year;
	}
	void Print1(int m, int d, int y) {
		cout << "Print1: " << m << "/" << d << "/" << y << endl;
	}
	void Print2(int m, int d, int y) {
		cout << "Print2: " << months[m - 1] << " " << d << ", " << y << endl;
	}
	void Print3(int m, int d, int y) {
		cout << "Print3: " << d << " " << months[m - 1] << " " << y << endl;
	}
};
#endif DATE

Date date;
int month = date.getMonth(),
	day = date.getDay(),
	year = date.getYear();
int tryMonth(), tryDay(), tryYear();
int main() {
	tryMonth();
	tryDay();
	tryYear();

	date.Print1(month, day, year);
	date.Print2(month, day, year);
	date.Print3(month, day, year);
}

int tryMonth() {
	try {
		cout << "Please enter the month: ";
		cin >> month;
		if (month > 12 || month < 1) {
			throw "Error 1: Month must be between 1 and 12";
		}
		else {
			return month;
		}
	}
	catch (const char* err) {
		cerr << err << endl;
		tryMonth();
	}
}

int tryDay() {
	try {
		cout << "Please enter the day: ";
		cin >> day;
		if (day > 31 || day < 1) {
			throw "Error 2: Day must be between 1 and 31";
		}
		else {
			return day;
		}
	}
	catch (const char* err) {
		cerr << err << endl;
		tryDay();
	}
}

int tryYear() {
	try {
		cout << "Please enter the year: ";
		cin >> year;
		if (year < 1000) {
			throw 3;
		}
		else {
			return year;
		}
	}
	catch (const int err) {
		cerr << "Error " << err << ": Year must be 4 digits" << endl;
		tryYear();
	}
}
