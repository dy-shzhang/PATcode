#include<iostream>
#include<queue>
#include<vector>
//#include<algorithm>
//#include<math.h>
//因为是树，所以理论上，最多节点数可以到2^n+1个，n最大取1000，所以用数组的方法没办法有那么多空间
//只能建树。
//#define INFI 0x7fffffff

using namespace std;
/*
int main()
{
	int n,k;
	int maxIdx = 1;
	k = 0;
	int record[10001];
	fill(record, record + 10001, INFI);
	vector<int>ans;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		int idx = 1;
		while (idx<=10001 && record[idx] != INFI) {
			if (tmp > record[idx]) {
				idx = 2 * idx + 1;
			}
			else
				idx *= 2;
		}
		maxIdx = maxIdx < idx ? idx : maxIdx;
		record[idx] = tmp;
	}
	while (k>=0) {
		int cnt = 0;
		int i = pow(2, k);
		for (; i <= maxIdx && i < pow(2, k + 1); i++) {
			if(record[i] != INFI)cnt++;
		}
		ans.push_back(cnt);
		if (i > maxIdx)
			break;
		k++;
	}
	if (ans.size() >= 2)
		cout << *ans.rbegin() << " + " << *(ans.rbegin()+1) << " = " << *ans.rbegin() + *(ans.rbegin() + 1) << endl;
	else if (ans.size() == 1)
		cout << ans[0] << " + 0 = " << ans[0] << endl;
	else
		cout << "0 + 0 = 0" << endl;
	system("pause");
	return 0;
}*/

struct node1115 {
	int val;
	int h;
	node1115*left, *right;
	node1115(int _val) :val(_val) {
		h = 1;
		left = right = nullptr;
	}
};

node1115* buildTree1115(int val, node1115* head) {
	if (head == nullptr) {
		node1115* tmp = new node1115(val);
		return tmp;
	}
	else {
		if (val <= head->val)
			head->left = buildTree1115(val, head->left);
		else
			head->right = buildTree1115(val, head->right);
		if (head->left == nullptr) {
			head->h = head->right->h + 1;
		}
		else if (head->right == nullptr) {
			head->h = head->left->h+1;
		}
		else {
			head->h = ((head->left->h > head->right->h) ? head->left->h : head->right->h) + 1;
		}
		return head;
	}
}


int main1115() {
	int n;
	int n1 = 0, n2 = 0;
	node1115* head = nullptr;
	queue<node1115*>check;
	vector<int>ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		head =buildTree1115(tmp, head);
	}
	if (head == nullptr) {
		cout << "0 + 0 = 0" << endl;
		return 0;
	}
	check.push(head);
	while (!check.empty()) {
		int si = check.size();
		ans.push_back(si);
		for (int i = 0; i < si; i++) {
			if (check.front()->left != nullptr)
				check.push(check.front()->left);
			if(check.front()->right != nullptr)
				check.push(check.front()->right);
			check.pop();
		}
	}
	if (ans.size() >= 2)
		cout << *ans.rbegin() << " + " << *(ans.rbegin() + 1) << " = " << *ans.rbegin() + *(ans.rbegin() + 1) << endl;
	else
		cout << ans[0] << " + 0 = " << ans[0] << endl;
	system("pause");
	return 0;
}