#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
// This is an additional, non-academic program created to expand upon 1/17 Reverse Array

int main() {
	const int PLANES = 3,
		ROWS = 3,
		COLS = 4;

	int numbers[PLANES][ROWS][COLS];

	for (int j = 0; j < ROWS; j++) {
		for (int k = 0; k < COLS; k++) {
			cout << "Enter a number: ";
			cin >> numbers[0][j][k];
			numbers[1][j][k] = numbers[0][j][k] * 2;
			numbers[2][j][k] = numbers[0][j][k];
		}
	}

	for (int i = 0; i < PLANES; i++) {
		cout << endl;
		switch (i) {
		case 0:
			cout << "Forward table" << endl;
			cout << "**************" << endl;
			break;
		case 1:
			cout << "Double table" << endl;
			cout << "*************" << endl;
			break;
		case 2:
			cout << "Reversed table" << endl;
			cout << "**************" << endl;
			break;
		}
		if (i == 2) {
			for (int j = ROWS; j > 0; j--) {
				for (int k = COLS; k > 0; k--) {
					cout << setw(3) << numbers[i][j-1][k-1];
				}
				cout << endl;
			}
		}
		else {
			for (int j = 0; j < ROWS; j++) {
				for (int k = 0; k < COLS; k++) {
					cout << setw(3) << numbers[i][j][k];
				}
				cout << endl;
			}
		}
	}
}
