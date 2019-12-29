#include<iostream>
#include<vector>
#include<algorithm>
#define inf 0x7fffffff
using namespace  std;

bool cmp1105(int&a, int&b) {
	return a > b;
}

void line1105(int indx, int dir, vector<vector<int>>&record, vector<int>&raw, int&it) {
	if (indx<0 ||indx >= record[0].size())
		return;
	if (dir == 1) {
		for (int i = 0; i < record.size(); i++) {
			if (record[i][indx] != inf)
				continue;
			record[i][indx] = raw[it++];
		}
	}
	else {
		for (int i = record.size() - 1; i >= 0; i--) {
			if (record[i][indx] != inf)
				continue;
			record[i][indx] = raw[it++];
		}
	}
}

void row1105(int indx, int dir, vector<vector<int>>&record, vector<int>&raw, int&it) {
	if (indx < 0 || indx >= record.size())
		return;
	if (dir == 1) {//¥”…œÕ˘œ¬
		for (int i = 0; i < record[0].size(); i++) {
			if (record[indx][i] != inf)
				continue;
			record[indx][i] = raw[it++];
		}
	}
	else {
		for (int i = record[0].size() - 1; i >= 0; i--) {
			if (record[indx][i] != inf)
				continue;
			record[indx][i] = raw[it++];
		}
	}
}

int main1105() {
	int k;
	int n, m;
	int it = 0;
	n = m = 0;
	cin >> k;
	for (int i = sqrt(k); i > 0; i--) {
		if (k%i==0) {
			n = i;
			m = k/i;
			break;
		}
	}
	vector<vector<int>>record(n, vector<int>(m, inf));
	vector<int>raw;
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		raw.push_back(tmp);
	}
	sort(raw.begin(), raw.end(), cmp1105);
	for (int i = 0; i <= m / 2; i++) {
		line1105(i, 1, record, raw, it);
		row1105(n - 1 - i, 1, record, raw, it);
		line1105(m - 1 - i, 0, record, raw, it);
		row1105(i, 0, record, raw, it);
	}
	for (int i = 0; i < record[0].size(); i++) {
		for (int j = 0; j < record.size(); j++) {
			if (j != 0)
				cout << " ";
			cout << record[j][i];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}