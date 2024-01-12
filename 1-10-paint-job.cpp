#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void promptUser(int&, int&, int&);
float calcGallon(float&);
float finalPrice(int, int, float, float, int);

int rooms,
	sqft = 0,
	coverage = 110,
	hourlyLabor = 8;

float gallonCost;

int main() {
	cout << "How many rooms do you need painted? ";
	cin >> rooms;

	int height,
		length,
		width;
	float charge = 25.00,
		supplies = 10.00;

	promptUser(height, length, width);
	calcGallon(gallonCost);

	float total = finalPrice(sqft, coverage, charge, supplies, rooms);
	cout << "Final price: $" << showpoint << fixed << setprecision(2) << total << endl;
}

void promptUser(int& h, int& l, int& w) {
	cout << endl;
	int i = 0;
	for(int i = 0; i < rooms; i++) {
		cout << "The dimension for room number " << i+1 << endl;
		cout << "Enter the height of the room: ";
		cin >> h;
		cout << "Enter the length of the room: ";
		cin >> l;
		cout << "Enter the width of the room: ";
		cin >> w;

		sqft += (l*h)*2 + (w*h)*2; // Surface Area equation from Lex Fagan
		cout << endl;
	}
}

float calcGallon(float& gallonCost) {
	cout << "What is the price of paint per gallon? ";
	cin >> gallonCost;
	cout << endl << endl;

	return gallonCost;
}

float finalPrice(int sqft, int coverage, float charge, float supplies, int rooms) {
	float sqftF = static_cast<float> (sqft),

	    gallonsNeeded = (sqftF / coverage),
		paintPrice = ceil(sqftF / coverage) * gallonCost,
		hours = (sqftF / coverage) * hourlyLabor,
		laborPrice = charge * hours,
		supplyPrice = supplies * rooms,
		total = laborPrice + paintPrice + supplyPrice;

	cout << "Gallons of paint needed for the job: " << ceil(gallonsNeeded) << " gallons." << endl;
	cout << "The number of hours needed: " << showpoint << fixed << setprecision(1) << hours << endl;
	cout << "Price of paint per gallon: $" << showpoint << fixed << setprecision(2) << gallonCost << endl;
	cout << "Labor: $" << showpoint << fixed << setprecision(2) << laborPrice << endl;
	cout << "Paint: $" << showpoint << fixed << setprecision(2) << paintPrice << endl;
	cout << "Supplies: $" << showpoint << fixed << setprecision(2) << supplyPrice << endl;
	return total;
}
