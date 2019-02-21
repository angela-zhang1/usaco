/*
ID: angela.11
TASK: combo
LANG: C++
*/

#include <fstream>
#include <cmath>

int main() {
	int dialNumbers;
	int farmer[3]; int master[3];
	int x = 0; int y = 0; int z = 0;
	int firstDifference, int secondDifference; int thirdDifference;
	int solutions = 250;
	std::ifstream comboIn("combo.in");
	comboIn >> dialNumbers;
	comboIn >> farmer[0] >> farmer[1] >> farmer[2];
	comboIn >> master[0] >> master[1] >> master[2];
	comboIn.close();

	firstDifference = std::abs(farmer[0] - master[0]);
	secondDifference = std::abs(farmer[1] - master[1]);
	thirdDifference = std::abs(farmer[2] - master[2]);
	int back1; int back2; int back3;

	if (firstDifference <= 4) {
		x = 5 - firstDifference;
	}

	if (farmer[0] > master[0]) {
		back1 = dialNumbers - farmer[0] + master[0];
	}
	else if (master[0] > farmer[0]) {
		back1 = dialNumbers - master[0] + farmer[0];
	}

	if (secondDifference <= 4) {
		y = 5 - secondDifference;
	}

	if (farmer[1] > master[1]) {
		back1 = dialNumbers - farmer[1] + master[1];
	}
	else if (master[1] > farmer[1]) {
		back1 = dialNumbers - master[1] + farmer[1];
	}

	if (std::abs(farmer[2] - master[2]) <= 4) {
		z = 5 - thirdDifference;
	}

	if (farmer[2] > master[2]) {
		back1 = dialNumbers - farmer[2] + master[2];
	}
	else if (master[2] > farmer[2]) {
		back1 = dialNumbers - master[2] + farmer[2];
	}

	solutions -= x * y*z;

	if (solutions>std::pow(dialNumbers, 3)) {
		solutions = std::pow(dialNumbers, 3);
	}

	std::ofstream comboOut("combo.out");
	comboOut << solutions << "\n";
	comboOut.close();
	return 0;
}
