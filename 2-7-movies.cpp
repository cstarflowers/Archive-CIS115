#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Movie {
	char title[45];
	unsigned long int worldwideGross;
	unsigned long int domesticGross;
	float domesticPct;
	int year;
};

int main() {
	const int TOTAL_MOVIES = 20;

	Movie MovieDB[TOTAL_MOVIES] = {
		{"Avatar", 2923706026, 785221649, 0, 2009},
		{"Avengers: Endgame", 2799439100, 858373000, 0, 2019},
		{"Avatar: The Way of Water", 2320250281, 684075767, 0, 2022},
		{"Titanic", 2264750694, 674292608, 0, 1997},
		{"Star Wars: Episode VII - The Force Awakens", 2071310218, 936662225, 0, 2015},
		{"Avengers: Infinity War", 2052415039, 678815482, 0, 2018},
		{"Spider - Man: No Way Home", 1921847111, 814115070, 0, 2021},
		{"Jurassic World", 1671537444, 653406625, 0, 2015},
		{"The Lion King", 1663079059, 543638043, 0, 2019},
		{"Avengers: Age of Ultron", 1542317294, 459005868, 0, 2015},
		{"Furious 7", 1527251659, 353007020, 0, 2015},
		{"The Avengers", 1520538536, 623357910, 0, 2012},
		{"Top Gun: Maverick", 1495696292, 718732821, 0, 2022},
		{"Frozen II", 1453683476, 477373578, 0, 2019},
		{"Barbie", 1445638421, 636238421, 0, 2023},
		{"Frozen", 1397045694, 400953009, 0, 2013},
		{"The Super Mario Bros. Movie", 1361952674, 574934330, 0, 2023},
		{"Harry Potter and the Deathly Hallows: Part 2", 1356961410, 381447587, 0, 2011},
		{"Black Panther", 1349926083, 700426566, 0, 2018},
		{"Star Wars: Episode VIII - The Last Jedi", 1334407706, 620181382, 0, 2017}};
	Movie MovieDB2[TOTAL_MOVIES] = {};
	
	fstream inFile, outFile;
	outFile.open("C:\\Movies.dat", ios::out | ios::binary);
	outFile.write(reinterpret_cast<char*>(MovieDB), sizeof(Movie) * TOTAL_MOVIES);
	outFile.close();

	inFile.open("C:\\Movies.dat", ios::in | ios::binary);
	inFile.read(reinterpret_cast<char*>(MovieDB2), sizeof(Movie) * TOTAL_MOVIES);
	inFile.close();
	for (int i = 0; i < TOTAL_MOVIES; i++) {
		float domesticF = static_cast<float>(MovieDB2[i].domesticGross),
			worldwideF = static_cast<float>(MovieDB2[i].worldwideGross);

		MovieDB[i].domesticPct = (domesticF / worldwideF) * 100;
	}
	outFile.open("C:\\Movies.dat", ios::out | ios::binary);
	outFile.write(reinterpret_cast<char*>(MovieDB), sizeof(Movie) * TOTAL_MOVIES);
	outFile.close();

	inFile.open("C:\\Movies.dat", ios::in | ios::binary);
	inFile.read(reinterpret_cast<char*>(MovieDB2), sizeof(Movie) * TOTAL_MOVIES);

	cout << "Box Office top 20" << endl;
	cout << "*****************" << endl;
	for (int j = 0; j < TOTAL_MOVIES; j++) {
		cout << "Movie #" << j + 1 << endl;
		cout << "Title: " << MovieDB2[j].title << endl;
		cout << "Year: " << MovieDB2[j].year << endl;
		cout << "Worldwide Box Office: $" << MovieDB2[j].worldwideGross << endl;
		cout << "Domestic Box Office: $" << MovieDB2[j].domesticGross << endl;
		cout << "Domestic Pct of Worldwide: " << fixed << showpoint << setprecision(2) << MovieDB2[j].domesticPct << "%" << endl;
		cout << endl;
	}
	inFile.close();
}
