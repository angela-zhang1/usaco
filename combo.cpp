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
	int x; int y; int z;
	int solutions=250;
	std::ifstream comboIn("combo.in");
	comboIn >> dialNumbers;
	comboIn >> farmer[0] >> farmer[1] >> farmer[2];
	comboIn >> master[0] >> master[1] >> master[2];
	comboIn.close();

	if (std::abs(farmer[0] - master[0]) < 4) {
	
	}
	if (std::abs(farmer[1] - master[1]) < 4) {
	
	}
	if (std::abs(farmer[2] - master[2]) < 4) {
	
	}

	std::ofstream comboOut("combo.out");
	comboOut << solutions << "\n";
	comboOut.close();
	return 0;
}
