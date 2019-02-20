/*
ID: angela.11	
TASK: milk2
LANG: C++
*/

//This took endlessly longer than it needed to.

#include <iostream>
#include <fstream>
#include <bitset>

int beginMilk;
int endMilk;
int cowNum;

int main() {

	std::ifstream milkIn("milk2.in");
	std::bitset<1000000> milkingTime;

	
	int startMilk = 1000000;
	int stopMilk = 0;

	milkIn >> cowNum;

	for (int i = 0; i < cowNum; i++) {
		milkIn >> beginMilk >> endMilk;
		for (int j = beginMilk; j < endMilk; j++) {
			milkingTime[j] = true;
		}
		if (beginMilk < startMilk)
			startMilk = beginMilk;
		if (endMilk > stopMilk)
			stopMilk = endMilk;
	}

	milkIn.close();

	int milk = 0;
	int noMilk = 0;
	int x = 0;
	bool current = milkingTime[startMilk];

	for (int i = startMilk; i < stopMilk; i++) {
		if (milkingTime[i] == current)
			x++;
		else {
			if (current) {
				if (milk < x)
					milk = x;
			}
			else {
				if (noMilk < x)
					noMilk = x;
			}
			x = 1;
			current = milkingTime[i];
		}
	}

	if (x == (stopMilk - startMilk)) {
		if (current)
			milk = x;
		else
			noMilk = x;
	}

	std::ofstream milkOut("milk2.out");
	milkOut << milk << " " << noMilk << "\n";
	milkOut.close();
	
	return 0;
}
