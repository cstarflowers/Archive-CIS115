#include <iostream>
#include <vector>

using namespace std;

int main() {
	char choice;
	int value;
	vector<int> v;

	cout << "a) Insert Element into the Vector" << endl;
	cout << "b) Delete Last Element of the Vector" << endl;
	cout << "c) Print Size of the Vector" << endl;
	cout << "d) Display Vector Elements" << endl;
	cout << "e) Clear the Vector" << endl;
	cout << "f) Insert Element at the Beginning of Vector" << endl;
	cout << "g) Delete Element at the Beginning of Vector" << endl;
	cout << "i) Exit" << endl;

	do {
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 'a':
			cout << "Enter value to be inserted: ";
			cin >> value;
			v.push_back(value);
			break;
		case 'b':
			if (v.size() > 0) {
				cout << "The last element has been deleted." << endl;
				v.pop_back();
			}
			else {
				cout << "ERROR: There are no elements to delete." << endl;
			}
			break;
		case 'c':
			cout << "Size of vector: " << v.size() << endl;
			break;
		case 'd':
			if (v.size() > 0) {
				cout << "Displaying vector elements: ";
				for (int i = 0; i < v.size(); i++) {
					cout << v[i] << " ";
				}
				cout << endl;
			}
			else {
				cout << "ERROR: There are no elements to display." << endl;
			}
			break;
		case 'e':
			cout << "Vector cleared!" << endl;
			v.clear();
			break;
		case 'f':
			cout << "Enter value to be inserted: ";
			cin >> value;
			v.insert(v.begin(), value);
			break;
		case 'g':
			if (v.size() > 0) {
				v.erase(v.begin());
			}
			else {
				cout << "ERROR: There are no elements to delete." << endl;
			}
			break;
		case 'i':
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "ERROR: This input is not supported -- make sure your selection is in lowercase!" << endl;
		}
	} while (choice != 'i');
}
