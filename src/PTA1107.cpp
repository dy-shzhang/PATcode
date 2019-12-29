#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find1107(int x, int* father) {
	while (x != father[x])
		x = father[x];
	return x;
}

void Union1107(int a, int b, int* father) {

	a = find1107(a, father);
	b = find1107(b, father);
	father[a] = b;
}
bool cmp1107(int a, int b) {
	return a > b;
}

int main1107() {
	int n, cnt;
	char mh;
	int k, t1, t2;
	int father[1001];
	int visit[1001] = { 0 };
	int record[1001] = { 0 };
	vector<int>sub[1001];
	for (int i = 0; i < 1001; i++) {
		father[i] = i;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k>>mh;
		cin >> t1;
		sub[i].push_back(t1);
		visit[t1] = 1;
		while (--k) {
			cin >> t2;
			visit[t2] = 1;
			Union1107(t1, t2, father);
			sub[i].push_back(t2);
		}
	}
	cnt = 0;
	for (int i = 0; i < n ; i++) {
		int f = find1107(sub[i][0],father);
		record[f]++;
	}
	sort(record, record + 1001, cmp1107);
	cnt = 0;
	while (record[cnt] > 0)cnt++;
	cout << cnt << endl;
	cout << record[0];
	for (int i = 1; i < cnt; i++) {
		cout << " " << record[i];
	}
	cout << endl;
	system("pause");
	return 0;
}