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
	int x=0; int y=0; int z=0;
	int firstDifference, int secondDifference; int thirdDifference;
	int solutions=250;
	std::ifstream comboIn("combo.in");
	comboIn >> dialNumbers;
	comboIn >> farmer[0] >> farmer[1] >> farmer[2];
	comboIn >> master[0] >> master[1] >> master[2];
	comboIn.close();
	
	firstDifference = std::abs(farmer[0] - master[0]);
	secondDifference = std::abs(farmer[1] - master[1]);
	thirdDifference = std::abs(farmer[2] - master[2]);

	if (firstDifference <= 4) {
		x = 5 - firstDifference;
	}
	if (secondDifference <= 4) {
		y = 5 - secondDifference;
	}
	if (std::abs(farmer[2] - master[2]) <= 4) {
		z = 5 - thirdDifference;
	}
	
	solutions -= x*y*z;
	
	if (dialNumbers < 5) {
	
	}

	std::ofstream comboOut("combo.out");
	comboOut << solutions << "\n";
	comboOut.close();
	return 0;
}
