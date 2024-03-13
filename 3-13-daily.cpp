#include <iostream>
using namespace std;

class Player {
private:
	int hits, abs, homers, rbis;
	float average;
public:
	Player() {
		hits = 0;
		abs = 0;
		homers = 0;
		rbis = 0;
		average = 0.00;
	}

	Player(int hi, int a, int ho, int r) {
		hits = hi;
		abs = a;
		homers = ho;
		rbis = r;
	}

	Player operator% (Player const& player) {
		Player temp;
		temp.hits = hits + player.hits;
		temp.abs = abs + player.abs;
		temp.homers = homers + player.homers;
		temp.rbis = rbis + player.rbis;

		temp.average = (double)temp.hits / (double)temp.abs;
		return temp;
	}

	void Print() {
		cout << "Hits: " << hits << endl;
		cout << "Abs: " << abs << endl;
		cout << "Homers: " << homers << endl;
		cout << "Rbis: " << rbis << endl;
		if (average >= 0) {
			cout << "Average: " << average << endl;
		}
		cout << endl;
	}
};

int main() {
	Player A(200, 590, 20, 90);
	Player B(160, 625, 45, 120);
	Player C;

	C = A % B;

	cout << "Player one stats: " << endl;
	A.Print();
	cout << "Player two stats: " << endl;
	B.Print();
	cout << "Their combined states: " << endl;
	C.Print();
}
