#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
//怎么搜索空间？？？？
using namespace std;
int change(string& s1, string s2, int i, bool flag) {
	if (s1[i] == s2[i]) {
		if (flag)
			return 0;
		else {
			switch (s1[i]) {
			case 'A':s1[i] = 'B'; break;
			case 'B':s1[i] = 'C'; break;
			case 'C':s1[i] = 'A'; break;
			}
			return 2;
		}

	}
	else {
		if (flag) {//奇数次
			s1[i] = s2[i];
			return 1;
		}
		else {
			switch (s1[i]) {
			case 'A':s1[i] = 'B'; break;
			case 'B':s1[i] = 'C'; break;
			case 'C':s1[i] = 'A'; break;
			}
			return 2;
		}

	}
}

void dfsyfd(string s1, string s2, vector<int>tochange, int level, int m, int& total,int times) {
	if (m == level) {
		if (s1 == s2)
			total+=times;
		return;
	}
	if (level < m) {
		int nextflag = 0;
		for (int i : tochange) {
			bool flag = (m - level) & 1;//1 ji ,0 ou
			nextflag *= change(s1, s2, i, flag);
			if (nextflag == 0)
				break;
		}
		if (nextflag == 0)
			return;
		else {
			dfsyfd(s1, s2, tochange, level + 1, m, total,times*nextflag);
		}
	}
}
int mainyfd1() {
	int n, m, k;
	int total = 0;
	int level = 0;
	string s1, s2;
	cin >> n >> m >> k;
	cin >> s1 >> s2;
	vector<int>tochange(k);
	for (int i = 0; i < k; i++)
		tochange[i] = i;
	for (; tochange[k - 1] < n; tochange[k - 1]++)
		dfsyfd(s1, s2, tochange, level, m, total,1);
	tochange[k - 1]--;
	for (int i = k - 2; i >= 0; i--) {
		for (; tochange[i] < tochange[i + 1]; tochange[i]++) {
			dfsyfd(s1, s2, tochange, level, m, total,1);
		}
		tochange[i]--;
	}
	cout << total << endl;
	system("pause");
	return 0;
}