/*
ID: angela.11
TASK: wormhole
LANG: C++
*/

#include <fstream>
#include <vector>
#include <array>

int main() {
	int wormholeCount;
	int pairings = 0;
	std::ifstream wormholeIn("wormhole.in");
	wormholeIn >> wormholeCount;
	for (int i = 0; i < wormholeCount; i++) {}
	wormholeIn.close();


	std::ofstream wormholeOut("wormhole.out");
	wormholeOut << pairings << "\n";
	wormholeOut.close();
	return 0;
}
