#include<iostream>
#include<map>
using namespace std;

//判断prime的条件
//题目要求

bool isPrime1116(int n) {
	if (n == 2 || n == 3)return true;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

int main1116() {
	int n, m;
	cin >> n;
	int student[10000] = { 0 };
	map<int, int>ck;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		student[tmp] = i + 1;
	}
	cin >> m;
	while (m--) {
		int check;
		cin >> check;
		printf("%04d", check);
		if (ck[check] == 1 && student[check] != 0) {
			//printf("%04d", check);
			cout  << ": Checked" << endl;
			continue;
		}
		ck[check] = 1;
		int rnk = student[check];
		if (rnk == 1)
			cout  << ": Mystery Award" << endl;
		else if (rnk == 0)
			cout  << ": Are you kidding?" << endl;
		else {
			if (isPrime1116(rnk))
				cout  << ": Minion" << endl;
			else
				cout  << ": Chocolate" << endl;
		}
	}
	return 0;
}