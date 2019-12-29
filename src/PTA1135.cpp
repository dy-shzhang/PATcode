#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//红黑树的特性，不含颜色的时候是个BST
//一棵树，至少需要两个条件才能唯一确定
//建树，用递归的办法


class Node1135 {
public:
	int val;
	Node1135*left;
	Node1135* right;
	Node1135(int _val) {
		val = _val;
		left = NULL;
		right = NULL;	
	}
};

Node1135*  cst1135(int _val, Node1135* nh) {
	if (nh == NULL) {
		Node1135* tmp = new Node1135(_val);
		return tmp;
	}
	else {
		if (abs(_val) < abs(nh->val)) {
			nh->left = cst1135(_val, nh->left);
		}
		else {
			nh->right = cst1135(_val, nh->right);
		}
		return nh;
	}
}

void dfs1135(Node1135* n, int&deepth, int level, bool& flag) {
	if (flag == false) {
		if (n==NULL) {
			level++;
			if (deepth == 0x7fffffff) {
				deepth = level;
			}
			else if (deepth != level) {
				flag = true;
			}
		}
		else {
			if (n->val > 0)
				level++;
			if (n->val < 0 && n->left != NULL && n->left->val < 0) {
				flag = true;
			}
			else if (n->val < 0 && n->right != NULL && n->right->val < 0) {
				flag = true;
			}
			dfs1135(n->left, deepth, level , flag);
			dfs1135(n->right, deepth, level , flag);
		}

	}

}
int main1135() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		Node1135* nhead=NULL;
		for (int j = 0; j < tmp; j++) {
			int t;
			cin >> t;
			nhead = cst1135(t, nhead);
		}
		int deepth = 0x7fffffff;
		bool flag = false;
		if (nhead->val < 0)
			flag = true;
		dfs1135(nhead, deepth, 0, flag);
		cout << (flag == true ? "No" : "Yes") << endl;
	}

	system("pause");
	return 0;
}