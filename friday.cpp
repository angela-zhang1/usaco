/*
ID: angela.11
TASK: friday
LANG: C++
*/

#include <fstream>
#include <iostream>

#define START_YEAR 1900

//This problem is a mess and I will have to revise it soon.

using namespace std;

enum daysofweek {
	Saturday	= 0,
	Sunday		= 1,
	Monday		= 2,
	Tuesday		= 3,
	Wednesday	= 4,
	Thursday	= 5,
	Friday		= 6,
};

enum monthsofyear {
	January		= 0x1,
	February	= 0x2,
	March		= 0x3,
	April		= 0x4,
	May			= 0x5,
	June		= 0x6,
	July		= 0x7,
	August		= 0x8,
	September	= 0x9,
	October		= 0xA,
	November	= 0xB,
	December	= 0xC,
};

template<typename T>
constexpr auto is_leap_year(T x) { return (x % 4 == 0) ? ((x % 100 == 0) ? ((x % 400 == 0) ? true : false) : true) : false; }

int main() {
	int currentThirteenth = 0;
	int currentMonth = 0;
	int amountYears;
	int thirteenCount[] = { 0, 0, 0, 0, 0, 0, 0 };
	ifstream fridayIn("friday.in");
	fridayIn >> amountYears; fridayIn.close();
	for (int i = START_YEAR; i <= amountYears + START_YEAR - 1; i++) {
		if (is_leap_year(i) == false) {
			thirteenCount[currentThirteenth % 7] += 2;
			thirteenCount[(currentThirteenth + 1) % 7] += 1;
			thirteenCount[(currentThirteenth + 2) % 7] += 1;
			thirteenCount[(currentThirteenth + 3) % 7] += 3;
			thirteenCount[(currentThirteenth + 4) % 7] += 1;
			thirteenCount[(currentThirteenth + 5) % 7] += 2;
			thirteenCount[(currentThirteenth + 6) % 7] += 2;
			currentThirteenth += 1;
		}
		else {
			thirteenCount[currentThirteenth % 7] += 3;
			thirteenCount[(currentThirteenth + 1) % 7] += 1;
			thirteenCount[(currentThirteenth + 2) % 7] += 1;
			thirteenCount[(currentThirteenth + 3) % 7] += 2;
			thirteenCount[(currentThirteenth + 4) % 7] += 2;
			thirteenCount[(currentThirteenth + 5) % 7] += 1;
			thirteenCount[(currentThirteenth + 6) % 7] += 2;
			currentThirteenth += 2;
		}
	}
	ofstream fridayOut("friday.out");
	fridayOut << thirteenCount[0] << " " << thirteenCount[1] << " " << thirteenCount[2] << " " << thirteenCount[3] << " " << thirteenCount[4] << " " << thirteenCount[5] << " " << thirteenCount[6] << "\n";
	
};
