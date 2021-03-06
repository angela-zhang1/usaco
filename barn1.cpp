/*
ID: angela.11
TASK: barn1
LANG: C++
*/

#include <fstream>
#include <bitset>
#include <vector>

int main() {
	int maxBoards;
	int currentBoards;
	int stallNum;
	int occupied;
	int numCovered;
	int occupiedStall = 0;
	int beginOccupied = 200;
	int endOccupied = 0;
	std::bitset<200> stalls;
	std::bitset<200> coveredStalls;

	std::ifstream barnIn("barn1.in");
	barnIn >> maxBoards >> stallNum >> occupied;

	for (int i = 0; i < occupied; i++) {
		barnIn >> occupiedStall;
		stalls[occupiedStall - 1] = 1;
		if (occupiedStall - 1 < beginOccupied)
			beginOccupied = occupiedStall - 1;
		if (occupiedStall - 1 > endOccupied)
			endOccupied = occupiedStall - 1;
	}
	numCovered = endOccupied - beginOccupied + 1;


	for (int i = beginOccupied; i < endOccupied; i++) {
		coveredStalls[i] = 1;
	}
	currentBoards = 1;
	int currentNoCow = 0;
	int maxNoCow = 0;
	int index = 0;

	while (currentBoards < maxBoards && numCovered > occupied) {
		for (int i = beginOccupied; i <= endOccupied; i++) {
			if (coveredStalls[i] == 0) {
				continue;
			}
			else {
				if (stalls[i] == 0)
					currentNoCow++;
				else {
					if (currentNoCow > maxNoCow) {
						maxNoCow = currentNoCow;
						index = i - 1;
					}
					currentNoCow = 0;
				}
			}
		}

		if (currentNoCow > maxNoCow) {
			maxNoCow = currentNoCow;
			index = endOccupied;
		}

		for (int i = 0; i < maxNoCow; i++) {
			coveredStalls[index - i] = 0;
		}

		numCovered -= maxNoCow;
		currentBoards++;
		currentNoCow = 0;
		maxNoCow = 0;
		index = 0;
	}

	std::ofstream barnOut("barn1.out");
	barnOut << numCovered << "\n";
	barnOut.close();

	return 0;
}
