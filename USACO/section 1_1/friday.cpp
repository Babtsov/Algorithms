/*
 ID: nika1231
 PROG: friday
 LANG: C++11
 */

#include <iostream>
#include <fstream>
using namespace std;

int daysInMonth(int year, int month) 
{
	if (month == 9 || month == 4 || month == 6 || month == 11)
		return 30;
	if (month == 2) {
		if (year % 400 == 0)
			return 29;
		if (year % 4 == 0 && year % 100 != 0)
			return 29;
		return 28;
	}
	return 31;
}

int main(int argc, char const *argv[])
{
	ifstream cin("friday.in");
	ofstream cout("friday.out");

	int dayCounter[7] = {0}; // array of counters where Sunday - dayCounter[0], Monday - dayCounter[1] ...
	int numOfYears;
	cin >> numOfYears;

	int dayOffset = 1; // 1.1.1900 was Monday
	for (int year = 0; year < numOfYears; ++year) {
		for (int month = 1; month <= 12; ++month) {
			int day13th = (dayOffset + 12) % 7; // 12 days away from the 1st of the month is the 13th day
			dayCounter[day13th]++;
			dayOffset = (dayOffset + daysInMonth(1900+year, month)) % 7;
		}
	}
	int i;
	for (i = 0; i < 6; ++i)
		cout << dayCounter[(i+6)%7] << " ";
	cout << dayCounter[(i+6)%7] << endl;

	return 0;
}