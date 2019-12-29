#include<iostream>
#include<vector>
#include<string>
using namespace std;
//long ±È int ´ó

int main1093() {

	string record;
	int countp = 0;
	long  allt = 0;
	int tmpsum = 0;
	cin >> record;
	for (int i = 0; i < record.size(); i++) {
		if (record[i] == 'P')
			countp++;
		else if (record[i] == 'A') {
			tmpsum += countp;
		}
		else {
			allt += tmpsum;
		}
	}
	cout << (allt % 1000000007) << endl;
	system("pause");
	return 0;
}