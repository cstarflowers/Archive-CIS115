#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int PLAYER_COUNT = 12; // 3 in example program
int highest = 0,
	total = 0,
	highestNumber;

struct PlayerInfo {
	string name;
	int number,
		points;
};

int main() {
	PlayerInfo players[PLAYER_COUNT];
	for (int i = 0; i < PLAYER_COUNT; i++) {
		cout << "Please enter the last name of player " << (i + 1) << ": ";
		cin >> players[i].name;
		cout << "Please enter " << players[i].name << "'s number: ";
		cin >> players[i].number;
		cout << "Please enter the number of goals scored by " << players[i].name << ": ";
		cin >> players[i].points;

		total += players[i].points;
		if (players[i].points > highest) {
			highest = players[i].points;
			highestNumber = i;
		}
	}

	cout << endl;
	for (int j = 0; j < PLAYER_COUNT; j++) {
		cout << setw(12) << players[j].name;
	}
	cout << endl;
	for (int j = 0; j < PLAYER_COUNT; j++) {
		cout << setw(12) << players[j].number;
	}
	cout << endl;
	for (int j = 0; j < PLAYER_COUNT; j++) {
		cout << setw(12) << players[j].points;
	}

	cout << endl << endl;
	cout << "The high scorer was " << players[highestNumber].name << " with " << highest << "." << endl;
	cout << "The team scored " << total << " goals." << endl;
}
