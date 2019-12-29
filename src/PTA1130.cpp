#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

//中序遍历获得表达式

class Node1130 {
public:
	string val;
	int left;
	int right;
	int idx;
	Node1130(string _s, int l, int r) {
		val = _s;
		left = l;
		right = r;
		idx = 0;
	}
};

void inorder1130(int idx, string& ans, vector<Node1130*>&record) {
	if (idx == -1) {
		return;
	}
	else {
		if (record[idx]->left != -1 || record[idx]->right != -1) {
			ans.push_back('(');
		}
		inorder1130(record[idx]->left, ans, record);
		ans = ans + record[idx]->val;
		inorder1130(record[idx]->right, ans, record);
		if (record[idx]->left != -1 || record[idx]->right != -1) {
			ans.push_back(')');
		}

	}
}

int main1130() {
	vector<Node1130*>record;
	string ans;
	map<int, int>fbgn;
	int n, bgn;
	cin >> n;
	record.resize(n + 1);
	for (int i = 0; i < n; i++) {
		string s;
		int l, r;
		cin >> s >> l >> r;
		if (l > 0)
			fbgn[l] = 1;
		if (r > 0)
			fbgn[r] = 1;
		Node1130* tmp = new Node1130(s, l, r);
		record[i + 1] = tmp;
	}
	for (int i = 1; i <= n; i++) {
		if (fbgn[i] == 0) {
			bgn = i;
			break;
		}
	}
	inorder1130(bgn, ans, record);
	if (ans.size() == 1) {
		cout << ans << endl;
		system("pause");
		return 0;
	}

	for (int i = 1; i < ans.size() - 1; i++) {//没有考虑到record只有一个元素的情况
		cout << ans[i];
	}
	cout << endl;
	system("pause");
	return 0;
}