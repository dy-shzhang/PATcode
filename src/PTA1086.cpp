#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

struct Node1086 {
	Node1086* l;
	Node1086* r;
	int val;
	Node1086(int _val) {
		l = r = NULL;
		val = _val;
	}
};

Node1086* dfs1086(int& idx, int l, int r, vector<int>&pre, vector<int>&inodr) {
	if (idx >= pre.size() || l >= r)
		return NULL;
	Node1086* tmp = new Node1086(pre[idx]);
	int md = l;
	while (md < r && inodr[md] != pre[idx])md++;
	if (l < md)
		tmp->l = dfs1086(++idx, l, md, pre, inodr);
	if (md + 1 < r)
		tmp->r = dfs1086(++idx, md + 1, r, pre, inodr);

	return tmp;
}

void postorder1086(Node1086* head, vector<int>&ans) {
	if (head == NULL)
		return;
	postorder1086(head->l, ans);
	postorder1086(head->r, ans);
	ans.push_back(head->val);
}

int main1086() {
	int n;
	int idx = 0;
	stack<int>record;
	vector<int>pre, inodr;
	vector<int>ans;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		string tmp;
		cin >> tmp;
		if (tmp.size() == 4) {
			int ntp;
			cin >> ntp;
			pre.push_back(ntp);
			record.push(ntp);
		}
		else {
			inodr.push_back(record.top());
			record.pop();
		}
	}
	Node1086* head = dfs1086(idx, 0, n, pre, inodr);
	postorder1086(head, ans);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size() - 1)
			cout << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}