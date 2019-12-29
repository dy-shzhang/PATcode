#include<iostream>
#include<vector>

using namespace std;

int main58tc2() {
	int n;
	int t1, t2;
	int tmp = 0;
	int idx = 0;
	int mx = 0;
	cin >> n;
	vector<int>record(n, 0);
	vector<int>len(n, 1);
	for (int i = 0; i < n; i++) {
		cin >> record[i];
	}
	for (int i = 1; i < n; i++) {
		if (record[i - 1] < record[i])
			len[i] = len[i - 1] + 1;
	}
	tmp = 1;
	while (tmp < n && len[tmp]!= 1)tmp++;
	if (tmp == n) {
		cout << len[tmp - 1] << endl;
		system("pause");
		return 0;
	}
	if (tmp == 1)t1 = 1;
	else t1 = len[tmp - 1];
	t2 = t1;
	while (tmp < n) {
		t1 = t2;
		idx = tmp;
		tmp += 1;
		while (tmp < n && len[tmp] != 1)tmp++;
		t2 = len[tmp - 1];
		if (idx >= 2 && record[idx - 2] + 1 < record[idx]) {
			mx = mx > (t1 + t2) ? mx : (t1 + t2);
		}
		else if (idx == 1 && record[1] > -100000) {
			mx = mx > (t1 + t2) ? mx : (t1 + t2);
		}
	}
	cout << mx << endl;
	system("pause");
	return 0;
}