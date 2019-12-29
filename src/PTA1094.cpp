#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node1094{
	int si;
	int parent;
	vector<int>childs;
	Node1094() {
		si = 0;
		parent = -1;
	}
}nodeTree1094[101];


int main1094() {
	int p, n;
	int maxg = 0;
	int level = 0;
	int maxlevel = 0;

	int u = 1;
	cin >> p >> n;
	queue<int>ans;
	for (int i = 0; i < n; i++) {
		int id, k;
		cin >> id >> k;
		nodeTree1094[id].si = k;
		for (int j = 0; j < k; j++) {
			int tmp;
			cin >> tmp;
			nodeTree1094[id].childs.push_back(tmp);
			nodeTree1094[tmp].parent = id;
		}
	}
	ans.push(1);
	while (!ans.empty()) {
		int si = ans.size();
		level++;
		if (si > maxg) {
			maxg = si;
			maxlevel = level;
		}
		for (int i = 0; i < si; i++) {
			int tp = ans.front();
			ans.pop();
			for (int j = 0; j < nodeTree1094[tp].si; j++) {
				ans.push(nodeTree1094[tp].childs[j]);
			}
		}
	}
	cout << maxg << " " << maxlevel << endl;
	system("pause");
	return 0;
}