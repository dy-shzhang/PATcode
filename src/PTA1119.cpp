#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct node1119 {
	int val;
	node1119* left;
	node1119* right;
	node1119(int _val) :val(_val) {
		left = right = nullptr;
	}
};

node1119*buildTree1119(node1119*head, vector<int>&pre,vector<int>&pst,int&idx,map<int,int>&charge,int&p) {
	if (p < pre.size()) {
		node1119* tmp = new node1119(pre[p]);
		charge[pre[p]] = 1;
		p++;
		int tp = pre.size() - 1;
		if (p == tp+1)
			return tmp;
		while (pst[tp] != pre[p-1])tp--;
		while (tp >= 0 && charge[pst[tp]] == 1)tp--;
		if (tp < 0)
			return tmp;
		else {
			if (pre[p] == pst[tp]) {
				idx = 1;
				tmp->left = buildTree1119(tmp->left, pre, pst, idx, charge, p);
			}
			else {
				tmp->left = buildTree1119(tmp->left, pre, pst, idx, charge, p);
				tmp->right = buildTree1119(tmp->right, pre, pst, idx, charge, p);
			}
		}
		return tmp;
	}
	else
		return nullptr;
}

void inorder1119(node1119*head, vector<int>&ans) {
	if (head == nullptr)
		return;
	else {
		inorder1119(head->left, ans);
		ans.push_back(head->val);
		inorder1119(head->right, ans);
	}
}

int main1119() {
	int n;
	int idx = 0,p=0;
	cin >> n;
	vector<int>pre(n, 0), pst(n, 0);
	map<int, int>charge;
	vector<int>ans;
	for (int j = 0; j < n; j++) {
		cin >> pre[j];
	}
	for (int j = 0; j < n; j++) {
		cin >> pst[j];
	}
	node1119*head = nullptr;
	head=buildTree1119(head, pre, pst, idx,charge,p);
	inorder1119(head,ans);
	cout << (idx ? "No":"Yes") << endl;
	if (ans.size() != 0) {
		cout << ans[0];
		for (int i = 1; i < ans.size(); i++) {
			cout << " " << ans[i];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}