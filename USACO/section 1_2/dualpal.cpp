/*
 ID: nika1231
 PROG: dualpal
 LANG: C++11
 */
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

bool isPalindrome(string num) {
	for (int front = 0, end = num.length()-1; end - front >= 1; front++ ,end--){
		if(num[front] != num[end])
			return false;
	}
	return true;
}

string convertToBase(int number,int base) {
	stack<int> newBaseDigits;
	while(number > 0) {
		int digit = number % base;
		char digitAsChar;
		digitAsChar = digit + '0';
		newBaseDigits.push(digitAsChar);
		number /= base;
	}
	string newBaseNum;
	while(!newBaseDigits.empty()){ //pop everything to the string
		newBaseNum += newBaseDigits.top();
		newBaseDigits.pop();
	}
	return newBaseNum;
}

int main(int argc, char const *argv[])
{
	ifstream cin("dualpal.in");
	ofstream cout("dualpal.out");
	int N, lowThreshHold; // N is the amount of numbers higher than the threshhold who are palindromic in two or more bases
	cin >> N >> lowThreshHold;

	int palindromableNumsCount = 0;
	int num = lowThreshHold + 1;
	while (palindromableNumsCount < N) {
		int palinedromeCount = 0;
		for (int base = 2; base <= 10; ++base) {
			if (isPalindrome(convertToBase(num,base)))
				palinedromeCount++;
			if (palinedromeCount == 2) {
				cout << num << endl;
				palindromableNumsCount++;
				break;
			}
		}
		num++;
	}

	return 0;
}