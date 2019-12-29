#include<iostream>
#include<vector>
#include<queue>
//1 通过后序和中序建树，把前序和中序的步骤调转一下，通过后（前）序判断当前应该生成哪一个节点，通过中序判断下一个节点处于当前
//节点的左边还是右边

//2 逆序输出时候，想清楚。

//储存顺序不变，输出顺序变化

using namespace std;
class Node1127 {
public:
	int val;
	Node1127 *left;
	Node1127* right;
	Node1127(int _val) :val(_val) {
		left = nullptr;
		right = nullptr;
	}
};

Node1127* buildTree1127(int s, int e, vector<int>&pstodr, int& idx, vector<int>&inodr) {
	if (idx >= 0)
	{
		Node1127* tmp = new Node1127(pstodr[idx]);

		int mid = s;
		while (mid < e && inodr[mid] != pstodr[idx])mid++;
		idx--;
		if (mid + 1 < e)
			tmp->right = buildTree1127(mid + 1, e, pstodr, idx, inodr);
		if (s < mid)
			tmp->left = buildTree1127(s, mid, pstodr, idx, inodr);
		return tmp;
	}
	else
		return nullptr;
}

int main1127() {
	int n, idx;
	cin >> n;
	vector<Node1127*>li1;
	vector<Node1127*>li2;
	vector<int>pstdr(n);
	vector<int>inodr(n);
	for (int i = 0; i < n; i++) {
		cin >> inodr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> pstdr[i];
	}
	idx = n - 1;
	Node1127* head = buildTree1127(0, n, pstdr, idx, inodr);
	cout << head->val;
	li1.push_back(head->left);
	li1.push_back(head->right);
	li2 = li1;
	idx = 1;
	while (!li2.empty()) {
		li2 = li1;
		if (idx & 1)
			for (auto i : li2) {
				if (i == nullptr)continue;
				cout << " " << i->val;
			}

		else
			for (auto i = li2.rbegin(); i != li2.rend(); i++) {
				if (*i == nullptr)continue;
				cout << " " << (*i)->val;
			}
		li1.clear();
		for (auto i : li2) {
			if (i == nullptr)continue;
			li1.push_back(i->left);
			li1.push_back(i->right);
		}
		idx++;
	}
	cout << endl;
	system("pause");
	return 0;
}