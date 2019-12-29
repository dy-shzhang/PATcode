#include<iostream>
#include<map>
#include<vector>
using namespace std;
//看清楚题目要求
//注意各个变量的意义


int main1122() {
	int grp[201][201] = { 0 };
	int n, m, k;
	cin >> n >> m;
	while (m--) {
		int t1, t2;
		cin >> t1 >> t2;
		grp[t1][t2] = grp[t2][t1] = 1;
	}
	cin >> k;
	while (k--) {
		int num;
		bool flag = false;
		cin >> num;
		map<int, int>ver;
		vector<int>line;
		for (int i = 0; i < num; i++) {
			int tmp;
			cin >> tmp;
			ver[tmp] = 1;
			line.push_back(tmp);
		}
		if (ver.size() != n) {
			cout << "NO" << endl;
			continue;
		}
		int id1 = line[0];
		int id2 = line[0];
		for (int i = 1; i < line.size(); i++) {
			id1 = id2;
			id2 = line[i];
			if (grp[id1][id2] == 0) {
				cout << "NO" << endl;
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		if (line[0] == line[line.size() - 1] && n==num-1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	system("pause");
	return 0;
}