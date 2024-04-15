#include <iostream>
using namespace std;

int total = 0;
int addToTotal(int, int);
int main() {
	int num1, num2;
	cout << "Please enter the first number you'd like to multiply: ";
	cin >> num1;
	cout << "Please enter the second number you'd like to multiply: ";
	cin >> num2;

	cout << endl << "Total: " << addToTotal(num1, num2);
}

int addToTotal(int a, int b) {
	if (b > 0) {
		total += a;
		addToTotal(a, b - 1);
	}
	return total;
}
