#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct Node1099 {
	int left;
	int right;
	int parent;
	int val;
	Node1099() {
		val = -1;
		left = -1;
		right = -1;
		parent = -1;
	}
}nodeTree1099[101];

bool cmp1099(int&a, int&b) {
	return a < b;
}

void dfs1099(int indx, vector<int>&record, int&it) {
	if (indx == -1)
		return;
	dfs1099(nodeTree1099[indx].left, record, it);
	nodeTree1099[indx].val = record[it++];
	dfs1099(nodeTree1099[indx].right, record, it);
}

int main1099() {
	int n;
	int u = 0;
	int it = 0;
	bool flag = false;
	vector<int>record;
	queue<int>ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		nodeTree1099[i].left = l;
		nodeTree1099[i].right = r;
		if (l != -1) {
			nodeTree1099[l].parent = i;
		}
		if (r != -1)
			nodeTree1099[r].parent = i;
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		record.push_back(tmp);
	}
	sort(record.begin(), record.end(), cmp1099);
	for (int i = 0; i < n; i++)
		if (nodeTree1099[i].parent == -1) {
			u = i;
			break;
		}
	dfs1099(u, record, it);
	ans.push(u);
	while (!ans.empty()) {
		int si = ans.size();
		for (int i = 0; i < si; i++) {
			if (flag == true)
				cout << " ";
			int tp = ans.front();
			ans.pop();
			cout << nodeTree1099[tp].val;
			flag = true;
			if (nodeTree1099[tp].left != -1)
				ans.push(nodeTree1099[tp].left);
			if (nodeTree1099[tp].right != -1)
				ans.push(nodeTree1099[tp].right);
		}
	}
	cout << endl;
	system("pause");
	return 0;
}