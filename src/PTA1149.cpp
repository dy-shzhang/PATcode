#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
//循环嵌套，时间复杂度过高
//需要想办法削减时间复杂度。
//我的想法是，判断装上的货物i，j之间有没有冲突，这样一来要不断地搜索i的禁忌表，与j相互比较。时间复杂度n^3

//答案的想法是，判断与i有冲突的货物在不在j中。因为运上去的货物可以用类哈希表表示a[100000],
//通过查冲突物品在不在a[100000]中更为方便。空间更小，查找更快
using namespace std;

/*
int main1149() {
	map<int,vector<int>>danlist;
	int N, M;
	int ngoods;
	vector<int>gds;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tp1, tp2;
		cin >> tp1 >> tp2;
		danlist[tp1].push_back(tp2);
		danlist[tp2].push_back(tp1);
	}
	for (int i = 0; i < M; i++) {
		bool flag = false;
		cin >> ngoods;
		for (int i = 0; i < ngoods; i++) {
			int tp;
			cin >> tp;
			gds.push_back(tp);
		}
		for (int i = 0; i < ngoods; i++) {
			for (int j = i + 1; j < ngoods; j++) {
				if (danlist[gds[i]].size() == 0)
					continue;
				else {
					for (int k = 0; k < danlist[gds[i]].size(); k++) {
						if (gds[j] == danlist[gds[i]][k]) {
							flag = true;
							break;
						}
					}
				}
				if (flag == true)
					break;
			}
			if (flag == true)
				break;
		}
		if (flag == true) {
			cout << "No" << endl;
			flag = false;
		}
		else
			cout << "Yes" << endl;
		gds.clear();
	}

	system("pause");
	return 0;
}
*/

int main1149Answer() {
	int n, k;
	cin >> n >> k;
	map<int, vector<int>>record;
	while (n--) {
		int id1, id2;
		cin >> id1 >> id2;
		record[id1].push_back(id2);
		record[id2].push_back(id1);
	}
	while (k--) {
		int time;
		bool flag = false;
		cin >> time;
		int woods[100000] = {0};//数组初始化，类似有fill（，，0）
		vector<int>wds;
		for (int i = 0; i < time; i++) {
			int tmp;
			cin >> tmp;
			wds.push_back(tmp);
			woods[tmp] = 1;
		}
		for (int i = 0; i < time; i++) {
			for (int j = 0; j < record[wds[i]].size(); j++) {
				if (woods[record[wds[i]][j]] == 1) {
					cout << "No" << endl;
					flag = true;
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		if (flag)
			continue;
		cout << "Yes" << endl;
	}
	system("pause");
	return 0;
}