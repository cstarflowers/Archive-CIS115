#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int ROWS = 4,
    COLS = 5;

int getTotal(const int[][COLS]);
int getRowTotal(const int[][COLS], int);
int getColumnTotal(const int[][COLS], int);
int getHighestInRow(const int[][COLS], int);
int getLowestInRow(const int[][COLS], int);
float getAverage(const int[][COLS]);
const int matrix[ROWS][COLS] = {23, 34, 12, 45, 2,
				31, 21, 23, 3, 8,
                                14, 29, 11, 42, 6,
                                34, 34, 9, 39, 15};

int main() {
    cout << "The 4 x 5 matrix" << endl;
    cout << "****************" << endl;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << setw(3) << matrix[i][j];
        }
        cout << endl;
    }

    cout << endl << endl << endl;
    cout << "The total of the matrix is " << getTotal(matrix) << endl;
    cout << "The average of the matrix is " << getAverage(matrix) << endl;
    cout << "The total of the first row is " << getRowTotal(matrix, 0) << endl;
    cout << "The total of the second column is " << getColumnTotal(matrix, 1) << endl;
    cout << "The highest value in the second row is " << getHighestInRow(matrix, 1) << endl;
    cout << "The lowest value in the third row is " << getLowestInRow(matrix, 2) << endl;
}

int getTotal(const int matrix[][COLS]) {
    int total = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            total += matrix[i][j];
        }
    }

    return total;
}

float getAverage(const int matrix[][COLS]) {
    float average = 0.00;
    float totalSlots = ROWS * COLS;
    average = (getTotal(matrix) / totalSlots);

    return average;
}

int getRowTotal(const int matrix[][COLS], int subscript) {
    int total = 0;

    for (int j = 0; j < COLS; j++) {
        total += matrix[subscript][j];
    }

    return total;
}

int getColumnTotal(const int matrix[][COLS], int subscript) {
    int total = 0;

    for (int i = 0; i < COLS; i++) {
        total += matrix[i][subscript];
    }

    return total;
}

int getHighestInRow(const int matrix[][COLS], int subscript) {
    int highest = matrix[subscript][0];

    for (int j = 0; j < COLS; j++) {
        if (highest < matrix[subscript][j]) {
            highest = matrix[subscript][j];
        }
    }

    return highest;
}

int getLowestInRow(const int matrix[][COLS], int subscript) {
    int lowest = matrix[subscript][0];

    for (int j = 0; j < COLS; j++) {
        if (lowest > matrix[subscript][j]) {
            lowest = matrix[subscript][j];
        }
    }

    return lowest;
}
