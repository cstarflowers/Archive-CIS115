#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	const int ROWS = 3,
		COLS = 4;
	int numbers[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << "Enter a number: ";
			cin >> numbers[i][j];
		}
	}

	cout << endl <<"Forward table" << endl;
	cout << "**************" << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << setw(3) << numbers[i][j];
		}
		cout << endl;
	}

	cout << endl << "Double table" << endl;
	cout << "*************" << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << setw(3) << numbers[i][j] * 2;
		}
		cout << endl;
	}

	cout << endl << "Reversed table" << endl;
	cout << "**************" << endl;
	for (int i = ROWS; i > 0; i--) {
		for (int j = COLS; j > 0; j--) {
			cout << setw(3) << numbers[i-1][j-1];
		}
		cout << endl;
	}
}
