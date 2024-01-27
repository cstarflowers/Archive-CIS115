#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	ifstream olympics;
	olympics.open("C:\\Olympics.txt", ios::in);
	if (olympics) {
		while(olympics) {
			int year,
				athletes,
				gold,
				silver,
				bronze,
				total = 0;
			string city = "";

			olympics >> year;
			olympics >> city;
			olympics >> athletes;
			olympics >> gold;
			olympics >> silver;
			olympics >> bronze;
			total += gold + silver + bronze;

			float totalF = static_cast<float> (total),
				athletesF = static_cast<float> (athletes);
			if (city != "") { // patches an additional print at the end of the file
				cout << "The " << athletes << " U.S. athletes collected " << total << " total medals at the " << city << " Olympics in " << year << endl;
				cout << "That is " << fixed << showpoint << setprecision(2) << totalF / athletesF << " medals per athlete" << endl << endl;
			}
		}
		olympics.close();
	}
	else {
		cout << "Error: File does not exist!" << endl;
	}
}
