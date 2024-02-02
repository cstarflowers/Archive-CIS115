#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 5;

int main() {
	int numbers1[SIZE],
		numbers2[SIZE],
		numbers1D[SIZE],
		numbers2D[SIZE];
	
	for (int i = 0; i < SIZE; i++) {
		cout << "Please enter slot " << i << " of array 1: ";
		cin >> numbers1[i];
	}
	cout << endl;
	for (int j = 0; j < SIZE; j++) {
		cout << "Please enter slot " << j << " of array 2: ";
		cin >> numbers2[j];
	}

	fstream inFile, outFile;
	inFile.open("C:\\ArrayData.dat", ios::out | ios::binary);
	inFile.write(reinterpret_cast<char*>(numbers1), sizeof(numbers1) * SIZE);
	inFile.write(reinterpret_cast<char*>(numbers2), sizeof(numbers2) * SIZE);
	inFile.close();

	outFile.open("C:\\ArrayData.dat", ios::in | ios::binary);
	outFile.read(reinterpret_cast<char*>(numbers1D), sizeof(numbers1) * SIZE);
	outFile.read(reinterpret_cast<char*>(numbers2D), sizeof(numbers2) * SIZE);
	outFile.close();
	cout << endl << "Arrays: " << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << numbers1D[i] << " ";
	}
	cout << endl;
	for (int j = 0; j < SIZE; j++) {
		cout << numbers2D[j] << " ";
	}
}
