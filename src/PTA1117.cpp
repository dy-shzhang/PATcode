#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//题目中 说的 more than是（>）不是（>=）!!!!!!!!!!!!

bool cmp1117(const int&a, const int&b) {
	return a > b;
}

int main1117() {
	int n;
	int day = -1;
	cin >> n;
	vector<int>record(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> record[i];
	}
	sort(record.begin(), record.end(), cmp1117);
	//while (day<0 && record[day]>day + 1)day++;
	for (int i = 0; i < n; i++) {
		if (record[i] <= i + 1) {
			day = i;
			break;
		}
	}
	if (day == -1)
		cout << n << endl;
	else
		cout << day << endl;

	system("pause");
	return 0;
}