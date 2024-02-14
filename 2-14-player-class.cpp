#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Player {
	private:
		int atBats, 
			hits;
	public:
		void setAtBats(int),
			setHits(int);
		int getAtBats() const,
			getHits() const;
};

void Player::setAtBats(int x) {
	atBats = x;
}
void Player::setHits(int x) {
	hits = x;
}

int Player::getAtBats() const {
	return atBats;
}
int Player::getHits() const {
	return hits;
}


int main() {
	Player Batter;
	int hits, atBats;
	string name;

	cout << "What is your player's name? ";
	getline(cin, name);
	cout << "How many hits did " << name << " have? ";
	cin >> hits;
	cout << "How many at bats did they have? ";
	cin >> atBats;
	Batter.setHits(hits);
	Batter.setAtBats(atBats);

	cout << endl << endl;
	float hitsF = static_cast<float> (Batter.getHits()),
		atBatsF = static_cast<float> (Batter.getAtBats());
	float battingAverage = hitsF / atBatsF;
	cout << name << "\'s batting averge was " << fixed << setprecision(3) << showpoint << battingAverage << endl;
	cout << "They had " << Batter.getHits() << " in " << Batter.getAtBats() << " at bats." << endl;
}
