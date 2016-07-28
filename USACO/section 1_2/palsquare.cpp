/*
 ID: nika1231
 PROG: palsquare
 LANG: C++11
 */
#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <fstream>
using namespace std;

bool isPalindrome(string num) {
	for (int front = 0, end = num.length()-1; end - front >= 1; front++ ,end--){
		if(num[front] != num[end])
			return false;
	}
	return true;
}

string convertToBase(int number,int base) {
	char highBaseDigits[] = {'A','B','C','D','E','F','G','H','I','J'};
	stack<int> newBaseDigits;
	while(number > 0) {
		int digit = number % base;
		char digitAsChar;
		if (digit > 9)
			digitAsChar = highBaseDigits[digit - 10];
		else
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
 	ifstream cin("palsquare.in");
 	ofstream cout("palsquare.out");
 	int base;
 	cin >> base;
 	for (int i = 1; i <= 300; ++i) {
 		int squared = pow(i,2);
 		bool isRequiredPrint = isPalindrome(convertToBase(squared,base));
 		if (isRequiredPrint)
 			cout << convertToBase(i,base) << " " << convertToBase(squared,base) << endl;
 	}
 	return 0;
 }