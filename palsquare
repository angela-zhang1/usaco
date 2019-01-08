/*
ID: angela.11
TASK: palsquare
LANG: C++
*/

#include <fstream>
#include <string>
#include <cmath>

std::string changeBase(int newBase, int number) 
{
	char numeral[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
	std::string newNumber = "";
	std::string newNumberBackwards = "";
	while (number >= 1) {
		int digit = number % newBase;
		char newDigit = numeral[digit];
		newNumberBackwards.push_back(newDigit);
		number = number / newBase;
	}
	for (int i = newNumberBackwards.length(); i > 0; i--)
		newNumber.push_back(newNumberBackwards[i - 1]);
	return newNumber;
}

int main() {
	int base;
	std::string palCheck;

	std::ifstream palsquareIn("palsquare.in");
	palsquareIn >> base;
	palsquareIn.close();

	std::ofstream palsquareOut("palsquare.out");

	for (int i = 1; i <= 300; i++) {
		std::string squared = changeBase(base, std::pow(i, 2));
		for (int j = squared.length(); j > 0; j--)
			palCheck += squared[j - 1];
		if (palCheck == squared) {
			palsquareOut << changeBase(base, i) << " " << squared << "\n";
		}
		palCheck = "";
	}

	palsquareOut.close();
	return 0x0;
}
