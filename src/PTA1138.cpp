#include<iostream>
#include<vector>

using namespace std;

//用递归，对内存消耗特大
//测试时，超出内存限制
class Node1138 {
public:
	int val;
	Node1138 * left;
	Node1138 * right;

	Node1138(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}
};

Node1138* formTree1138(int l, int r, int& idx, vector<int>pre, vector<int>inodr) {
	int val = pre[idx];
	int mid = l;
	while (mid < r && inodr[mid] != val)mid++;
	Node1138* tmp = new Node1138(val);
	if (l < mid) {
		tmp->left = formTree1138(l, mid, ++idx, pre, inodr);
	}
	if (mid + 1 < r) {
		tmp->right = formTree1138(mid + 1, r, ++idx, pre, inodr);
	}
	return tmp;
}


int main1138() {
	int n;
	int s = 0;
	cin >> n;
	vector<int>pre(n);
	vector<int>inodr(n);
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> inodr[i];
	}
	Node1138* head = formTree1138(0, n, s, pre, inodr);
	Node1138*tmp = head;
	while (1) {
		if (tmp->left == NULL && tmp->right == NULL) {
			cout << tmp->val << endl;
			break;
		}
		else if (tmp->left != NULL)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	system("pause");
	return 0;
}