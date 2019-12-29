#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp1113(int&a, int&b) {
	return a < b;
}

int main1113() {
	int n;
	vector<int>record;
	int s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		record.push_back(tmp);
	}
	sort(record.begin(),record.end(),cmp1113);
	if ((n & 1) == 0) {
		for (int i = 0; i < n / 2; i++) {
			s += (record[i + n / 2] - record[i]);
		}
		cout << "0 " << s << endl;
	}
	else {
		for (int i = 0; i < n / 2; i++) {
			s += (record[i+ n / 2] - record[i]);
		}
		s += record[n -1];
		cout << "1 " << s << endl;
	}
	system("pause");
	return 0;
}