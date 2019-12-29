#include<iostream>
#include<queue>
#include<string>

using namespace std;

struct Node1102 {
	int left;
	int right;
	int parent;
	Node1102() {
		left = -1;
		right = -1;
		parent = -1;
	}
}nodeTree1102[11];

void dfs1102(int u, vector<int>&inorder) {
	if (u == -1)
		return;
	dfs1102(nodeTree1102[u].right, inorder);
	inorder.push_back(u);
	dfs1102(nodeTree1102[u].left, inorder);
}

int main1102() {
	int n,u=0;
	int si = 0;
	queue<int>level;
	vector<int>levorder, inorder;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (a[0] != '-') {
			nodeTree1102[i].left = a[0] - '0';
			nodeTree1102[a[0] - '0'].parent = i;
		}
		if (b[0] != '-') {
			nodeTree1102[i].right = b[0] - '0';
			nodeTree1102[b[0] - '0'].parent = i;	
		}
	}
	for (int i = 0; i < n; i++) {
		if (nodeTree1102[i].parent == -1) {
			u = i;
			break;
		}
	}
	level.push(u);
	while (!level.empty()) {
		si = level.size();
		for (int i = 0; i < si; i++) {
			int it = level.front();
			level.pop();
			levorder.push_back(it);
			if(nodeTree1102[it].right!=-1)
				level.push(nodeTree1102[it].right);
			if (nodeTree1102[it].left != -1)
				level.push(nodeTree1102[it].left);
		}
	}
	dfs1102(u, inorder);
	if (n > 0) {
		cout << levorder[0];
		for (int i = 1; i < n; i++) {
			cout << " " << levorder[i];
		}
	}
	cout << endl;

	if (n > 0) {
		cout << inorder[0];
		for (int i = 1; i < n; i++) {
			cout << " " << inorder[i];
		}
	}
	cout << endl;

	system("pause");
	return 0;
}