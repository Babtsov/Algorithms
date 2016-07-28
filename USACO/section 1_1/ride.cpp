/*
 ID: nika1231
 PROG: ride
 LANG: C++11
 */
 #include <iostream>
 #include <fstream>
 using namespace std;

 int main(){
 	ofstream cout("ride.out");
 	ifstream cin("ride.in");
 	string comet, group;  
 	cin >> comet >> group;
 	long long totalComet = 1, totalGroup = 1;
 	for (char i : comet)
 		totalComet *= (i - 'A' + 1) % 47;
 	for (char i : group)
 		totalGroup *= (i - 'A' + 1) % 47;
 	if (totalComet % 47 == totalGroup % 47)
 		cout << "GO" << endl;
 	else
 		cout << "STAY" << endl;
 	return 0;
 }