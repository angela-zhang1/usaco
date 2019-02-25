/*
ID: angela.11
TASK: wormhole
LANG: C++
*/

#include <fstream>
#include <array>

int main() {
	int wormholeCount;
	int pairings = 0;
	int x; int y; 
	std::ifstream wormholeIn("wormhole.in");
	std::array<std::array<int, 2>, 12> wormholes;
	wormholeIn >> wormholeCount;
	for (int i = 0; i < wormholeCount; i++) {
		wormholeIn >> x >> y;
		wormholes[i][0] = x;
		wormholes[i][1] = y;
	}
	wormholeIn.close();

	for (int i = 0; i < wormholeCount; i++) {}


	std::ofstream wormholeOut("wormhole.out");
	wormholeOut << pairings << "\n";
	wormholeOut.close();
	return 0;
}
