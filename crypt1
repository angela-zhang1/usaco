/*
ID: angela.11
TASK: crypt1
LANG: C++
*/

#include <fstream>
#include <vector>

int main() {
	int solutions = 0;
	int numdigits;
	int digit;
	int a;
	int b;
	int c;
	int d;
	int e;
	int abc;
	int de;
	int x;
	int y;
	int product;
	bool goodDigit[10] = { false };
	std::vector<int> digits;

	std::ifstream cryptIn("crypt1.in");
	cryptIn >> numdigits;

	for (int i = 0; i < numdigits; i++) {
		cryptIn >> digit;
		digits.push_back(digit);
		goodDigit[i] == true;
	}
	cryptIn.close();

	for (int i = 0; i < numdigits; i++) {
		a = digits[i];
		for (int j = 0; j < numdigits; j++) {
			b = digits[j];
			for (int k = 0; k < numdigits; k++) {
				c = digits[k];
				for (int l = 0; l < numdigits; l++) {
					d = digits[l];
					for (int m = 0; m < numdigits; m++) {
						e = digits[m];
						abc = 100 * a + 10 * b + c;
						de = 10 * d + e;
						x = abc * e;
						y = abc * d;
						product = x * 10 + y;
						/*
						  abc
						 + de
						------
						  *** x
						 ***  y
						------
						 ****
						*/
						if (x > 999 || y > 999) { goto FAIL; }
						else if (product> 9999) { goto FAIL; }
						else {
							for (int n = 0; n < 3; i++) {
								if (goodDigit[x % 10] == false) {
									goto FAIL;
								}
								x /= 10;
							}
							for (int n = 0; n < 3; i++) {
								if (goodDigit[y % 10] == false) { goto FAIL; }
								y /= 10;
							}
							for (int n = 0; n < 4; i++) {
								if (goodDigit[product % 10] == false) {
									goto FAIL;
								}
								product /= 10;
							}
						}
						solutions++;
						FAIL:;
					}
				}
			}
		}
	}

	std::ofstream cryptOut("crypt1.out");
	cryptOut << solutions << "\n";
	cryptOut.close();
	return 0;
}
