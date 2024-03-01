#include <iostream>
#include <string>
using namespace std;

int main() {
	string temp;

	char* name = nullptr;
	char* street = nullptr;
	char* cityState = nullptr;
	int boxNum, zip;

	cout << "Please enter employee's name: ";
	getline(cin, temp);
	name = new char[temp.length() + 1];
	for (int i = 0; i < temp.length() + 1; i++) {
		name[i] = static_cast<char>(temp[i]);
	}

	cout << "Please enter employee's box number: ";
	cin >> boxNum;
	cin.ignore();

	cout << "Please enter employee's street: ";
	getline(cin, temp);
	street = new char[temp.length() + 1];
	for (int i = 0; i < temp.length() + 1; i++) {
		street[i] = static_cast<char>(temp[i]);
	}

	cout << "Please enter employee's city, state: ";
	getline(cin, temp);
	cityState = new char[temp.length() + 1];
	for (int i = 0; i < temp.length() + 1; i++) {
		cityState[i] = static_cast<char>(temp[i]);
	}

	cout << "Please enter employee's zip code: ";
	cin >> zip;

	
	cout << endl << endl << endl;
	cout << "Employee Address" << endl;
	cout << "****************" << endl;
	cout << name << endl;
	cout << boxNum << " " << street << endl;
	cout << cityState << endl;
	cout << zip << endl;

	delete[] name;
	delete[] street;
	delete[] cityState;
}
