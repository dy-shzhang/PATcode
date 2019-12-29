#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node {
	int val;
	vector<int>child;
	node() {
		val = 0;
	}
}tree[50001];

void dfswy5(int idx, int tmp, int &sum, int&cnt) {
	tmp += tree[idx].val;
	if (tmp == sum)
		cnt++;
	for (int i = 0; i < tree[idx].child.size(); i++) {
		dfswy5(tree[idx].child[i], tmp, sum, cnt);
	}
}

int mainwy5() {
	int n, sum;
	int cnt = 0;
	cin >> n >> sum;
	for (int i = 0; i < n; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		tree[t1].val = t2;
		tree[t3].child.push_back(t1);
	}
	queue<int>que;
	que.push(0);
	while (!que.empty()) {
		int i = que.front();
		que.pop();
		for (int j = 0; j < tree[i].child.size(); j++) {
			que.push(tree[i].child.at(j));
		}
		dfswy5(i, 0, sum, cnt);
	}
	cout << cnt << endl;
	system("pause");
	return 0;
}