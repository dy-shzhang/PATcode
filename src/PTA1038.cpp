#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//考虑特殊的全零
bool cmp1038(string&a, string&b) { //自己写出来的，好好琢磨琢磨
	string ta = a;
	string tb = b;
	while (1) {
		int sa = ta.size();
		int sb = tb.size();
		if (sa == sb) {
			return ta < tb;
		}
		else if (sa < sb) {
			string ttb = tb.substr(0, ta.size());
			if (ta != ttb) {
				return ta < tb;
			}
			else {
				ta = ta + a;
			}
		}
		else {
			string tta = ta.substr(0, tb.size());
			if (tta != tb) {
				return ta < tb;
			}
			else {
				tb = tb + b;
			}
		}
	}
}

int main1038() {
	int n, flag;
	flag = 0;
	cin >> n;
	vector<string>record;
	string ans;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		record.push_back(tmp);
	}
	sort(record.begin(), record.end(), cmp1038);

	for (int i = 0; i < record.size(); i++) {
		ans = ans + record[i];
	}
	if (ans.size() == 1)
		cout << ans;
	else
		for (int i = 0; i < ans.size(); i++) {
			if (flag == 0 && ans[i] == '0')
				continue;
			else {
				cout << ans[i];
				flag = 1;
			}
		}
	if (flag == 0)
		cout << 0;
	cout << endl;
	system("pause");
	return 0;
}