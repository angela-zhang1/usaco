/*
ID: angela.11
TASK: dualpal
LANG: C++
*/

#include <fstream>
#include <string>

int main() {
	int loop, start;
	int count = 0;
	int palBaseCount = 0;
	std::string palCheck;

	std::ifstream dualpalIn("dualpal.in");
	dualpalIn >> loop >> start;
	dualpalIn.close();

	start++; //to start from the first integer greater than the one provided
	std::ofstream dualpalOut("dualpal.out");

	while (count < loop) {
		palBaseCount = 0;
		for (int i = 2; i <= 10; i++) {
			palCheck = "";
			std::string changed = "";
			std::string digit;// for me this digit always ends up being \x2. Idk
			int baseChange = start;
			while (baseChange != 0) {
				digit = std::to_string(baseChange % i);
				baseChange /= i;
				changed = changed + digit;
			}
			for (int j = changed.length(); j > 0; j--) {
				palCheck += changed[j - 1];
			}
			if (changed == palCheck) {
				palBaseCount++;
				if (palBaseCount == 2) {
					count++;
					dualpalOut << start << "\n";
					break;
				}
			}
		}
		start++;
	}
	dualpalOut.close();
	return 0;
}
