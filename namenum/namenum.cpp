/*
ID: angela.11
TASK: namenum
LANG: C++
*/

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <array>



int main() {
	std::ifstream nameIn("namenum.in");
	std::ifstream dictionary("namenumdict.txt");
	std::array<std::string, 4617> possibleNames;
	std::vector<std::string> cowNames;
	std::string serial;

	std::map<char, std::array<char, 3>> letterReference{
		{'2', {'A','B','C'}},
		{'3', {'D','E','F'}},
		{'4', {'G','H','I'}},
		{'5', {'J','K','L'}},
		{'6', {'M','N','O'}},
		{'7', {'P','R','S'}},
		{'8', {'T','U','V'}},
		{'9', {'W','X','Y'}},
	};

	nameIn >> serial;
	nameIn.close();

	std::string name;
	int matchCow = 0;

	for (int i = 0; i < 4617; i++) {
		dictionary >> name;
		possibleNames[i] = name;
	}

	dictionary.close();

	std::string cowName;
	bool trueName = true;

	std::ofstream nameOut("namenum.out");

	for (int i = 0; i < 4617; i++) {
		trueName = true;
		cowName = possibleNames[i];
		if (cowName.length() != serial.length()) {
			continue;
		}
		for (unsigned int j = 0; j < serial.length(); j++) {
			char nameLetter = cowName[j];
			char cowNumDigit = serial[j];
			if ((nameLetter != letterReference[cowNumDigit][0]) && (nameLetter != letterReference[cowNumDigit][1]) && (nameLetter != letterReference[cowNumDigit][2])) {
					trueName = false;
					break;
			}
		}
		if (trueName) {
			matchCow++;
			nameOut << cowName << "\n";
		}
	}

	if (matchCow == 0) {
		nameOut << "NONE" << "\n";
	}

	nameOut.close();
	return 0;
}
