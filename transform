/*
ID: angela.11
TASK: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

int size;

std::ifstream transformIn("transform.in");

int main() {
	//dang.... this is going to be difficult
	int patternChange = 7;
	transformIn >> size;
	char initial[10][10];
	char transform[10][10];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			transformIn >> initial[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			transformIn >> transform[i][j];
		}
	}
	transformIn.close();

	int possible[8] = { 1, 2, 3, 4, 5, 5, 5, 6 };
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (initial[i][j]!=transform[j][size-(i+1)]) { //case 1: clockwise 90
				possible[0] = 0;
			}
			if (initial[i][j]!=transform[size-(i+1)][size-(j+1)]) { //case 2: clockwise 180
				possible[1] = 0;
			}
			if (initial[i][j]!=transform[size-(j+1)][i]) { //case 3: clockwise 270/counterclockwise 90
				possible[2] = 0;
			}
			if (initial[i][j]!=transform[i][size-(j+1)]) { //case 4: reflection (horizontal)
				possible[3] = 0;
			}
			if (initial[i][j]!=transform[size-(j+1)][size-(i+1)]) { //case 5: combo 90
				possible[4] = 0;
			}
			if (initial[i][j]!=transform[size-(i+1)][j]) { //case 5: combo 180
				possible[5] = 0;
			}
			if (initial[i][j]!=transform[j][i]) { //case 5: combo 270
				possible[6] = 0;
			}
			if (initial[i][j]!=transform[i][j]) { //case 6: no change
				possible[7] = 0;
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		if (possible[i] != 0) {
			patternChange = possible[i];
			break;
		}
	}

	std::ofstream transformOut("transform.out");
	transformOut << patternChange << "\n";
	transformOut.close();
}

