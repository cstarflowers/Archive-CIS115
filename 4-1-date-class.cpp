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
	void setMonth(int m) {
		month = m;
	}
	void setDay(int d) {
		day = d;
	}
	void setYear(int y) {
		year = y;
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
int month, day, year;

void tryMonth(), tryDay(), tryYear();
int main() {
	tryMonth();
	tryDay();
	tryYear();

	date.Print1(date.getMonth(), date.getDay(), date.getYear());
	date.Print2(date.getMonth(), date.getDay(), date.getYear());
	date.Print3(date.getMonth(), date.getDay(), date.getYear());
}

void tryMonth() {
	try {
		cout << "Please enter the month: ";
		cin >> month;
		if (month > 12 || month < 1) {
			throw "Error 1: Month must be between 1 and 12";
		}
		else {
			date.setMonth(month);
		}
	}
	catch (const char* err) {
		cerr << err << endl;
		tryMonth();
	}
}

void tryDay() {
	try {
		cout << "Please enter the day: ";
		cin >> day;
		if (day > 31 || day < 1) {
			throw "Error 2: Day must be between 1 and 31";
		}
		else {
			date.setDay(day);
		}
	}
	catch (const char* err) {
		cerr << err << endl;
		tryDay();
	}
}

void tryYear() {
	try {
		cout << "Please enter the year: ";
		cin >> year;
		if (year < 1000) {
			throw 3;
		}
		else {
			date.setYear(year);
		}
	}
	catch (const int err) {
		cerr << "Error " << err << ": Year must be 4 digits" << endl;
		tryYear();
	}
}
