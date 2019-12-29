#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
	int score;
	int order;
	int rank;
	Node(int _s, int _o) {
		score = _s;
		order = _o;
		rank = 0;
	}
};

bool cmp(Node*&a, Node*&b) {
	return a->order < b->order;
}

int main() {
	int n, k;
	vector<int>score,order;
	vector<Node*>record;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		score.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		order.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		Node* tmp = new Node(score[i], order[i]);
		record.push_back(tmp);
	}
	vector<Node*>recd1(record.begin(),record.end());
	sort(recd1.begin(), recd1.end(), cmp);
	while (recd1.size()>1) {
		int si = recd1.size();
		int rank = si / k+1;
		if (si > si / k * k)rank += 1;
		int cnt = 0;
		vector<Node*>rcd;
		while (cnt < si) {
			int mx = recd1[cnt]->score;
			int u = -1;
			for (int i = cnt; i < cnt + k && i < recd1.size(); i++) {
				if (mx <= recd1[i]->score) {
					u = i;
					mx = recd1[i]->score;
				}
			}
			rcd.push_back(recd1[u]);
			for (int i = cnt; i < cnt + k && i < recd1.size(); i++) {
				if (i == u)
					continue;
				recd1[i]->rank = rank;
			}
			cnt += k;
		}
		recd1 = rcd;
	}
	system("pause");
	return 0;
}