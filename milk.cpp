/*
ID: angela.11
TASK: milk
LANG: C++
*/

#include <array>
#include <vector>
#include <fstream>

int main() {
	int totalMilk;
	int currentMilk = 0;
	int numFarmers;
	int currentCost = 0;
	int x;
	int y;
	int minIndex;
	int minCost = 1000;
	std::vector<int> milkAmount;
	std::vector<int> milkCost;
	std::ifstream milkIn("milk.in");
	milkIn >> totalMilk >> numFarmers;

	for (int i = 0; i < numFarmers; i++) {
		milkIn >> x >> y;
		milkCost.push_back(x);
		milkAmount.push_back(y);
	}
	milkIn.close();

	while (currentMilk < totalMilk) {
		minCost = 1000;
		for (int i = 0; i < numFarmers; i++) {
			if ((milkCost[i] < minCost) && (milkAmount[i] !=0)) {
				minCost = milkCost[i];
				minIndex = i;
			}
		}
		if ((currentMilk + milkAmount[minIndex]) > totalMilk) {
			currentCost += (totalMilk - currentMilk)*milkCost[minIndex];
			currentMilk = totalMilk;
		}
		else {
			currentMilk += milkAmount[minIndex];
			currentCost += milkCost[minIndex] * milkAmount[minIndex];
			milkAmount[minIndex] = 0;
		}
	}

	std::ofstream milkOut("milk.out");
	milkOut << currentCost << "\n";
	milkOut.close();
	return 0;
}
