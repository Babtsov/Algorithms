/*
 ID: nika1231
 PROG: milk
 LANG: C++11
 */
 #include <iostream>
 #include <algorithm>
 #include <fstream>
 #include <cassert>
 using namespace std;

struct milkSupplier {
	int unitPrice;
	int milkQuantity;
};
bool priceCompare(milkSupplier lhs, milkSupplier rhs) {
	return lhs.unitPrice < rhs.unitPrice;
}

 int main(int argc, char const *argv[])
 {
 	ifstream cin("milk.in");
 	ofstream cout("milk.out");
 	int milkRequired, farmersNum;
 	cin >> milkRequired >> farmersNum;

 	milkSupplier farmers[farmersNum];
 	for (int i = 0; i < farmersNum; i++)
 		cin >> farmers[i].unitPrice >> farmers[i].milkQuantity;
 	sort(farmers, farmers + farmersNum, priceCompare);

 	int milkBought = 0, paidTotal = 0;
 	int i = 0;
 	while (milkBought < milkRequired) {
 		assert(i < farmersNum);
 		if(farmers[i].milkQuantity > 0) {
 			milkBought++;
 			paidTotal += farmers[i].unitPrice;
 			farmers[i].milkQuantity--;
 		}
 		else
 			i++;
 	}
 	cout << paidTotal << endl;

 	return 0;
 }