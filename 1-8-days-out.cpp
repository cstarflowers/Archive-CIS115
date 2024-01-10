#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int numEmployees();
int daysMissed(int);
double averageDays(int, int);

int employees,
	absent,
	total;

int main() {
	total = daysMissed(numEmployees());
	cout << endl << "There are " << employees << " employees at the company." << endl;
	cout << "They missed a total of " << total << " days last year." << endl;
	cout << "The average days missed by each employee is " << showpoint << fixed << setprecision(1) << averageDays(total, employees) << "." << endl;
}

int numEmployees() {
	cout << "Please enter the number of Employees: ";
	cin >> employees;
	return employees;
}

int daysMissed(int employees) {
	for (int i = 1; i <= employees; i++) {
		cout << "Please enter the days absent for Employee " << i << ": ";
		cin >> absent;
		total += absent;
	}
	return total;
}

double averageDays(int days, int employees) {
	double daysD = static_cast<double> (days),
		employeesD = static_cast<double> (employees),
		average = daysD/employeesD;
	return average;
}
