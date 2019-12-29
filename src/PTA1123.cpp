#include<iostream>
#include<vector>
#include<queue>
//测试案例 段错误。。没想出来是哪的问题
//参考答案里，使用了getHeight函数来获取当前的高度值，并非记录下来的。
//getHeight 从当前位置向下递归，采集max高度
using namespace std;

struct node1123 {
	int val;
	int h;
	node1123* left;
	node1123* right;
	node1123(int _val) :val(_val) {
		left = nullptr;
		right = nullptr;
		h = 1;
	}
};

node1123* ll1123(node1123*tmp) {
	node1123* a = tmp->left;
	tmp->left = a->right;
	a->right = tmp;
	return a;
}

node1123* rr1123(node1123* tmp) {
	node1123* a = tmp->right;
	tmp->right = a->left;
	a->left = tmp;
	return a;
}

node1123* lr1123(node1123* tmp) {
	node1123*a = tmp->left;
	tmp->left = rr1123(a);
	return ll1123(tmp);
}

node1123* rl1123(node1123* tmp) {
	node1123* a = tmp->left;
	tmp->left = ll1123(a);
	return rr1123(tmp);
}
node1123* avl_insert1123(int val, node1123* head) {
	if (head == nullptr) {
		node1123* tmp = new node1123(val);
		return tmp;
	}
	else {
		if (head->val > val)
			head->left = avl_insert1123(val, head->left);
		else
			head->right = avl_insert1123(val, head->right);

		int rh, lh;

		rh = head->right == nullptr ? 1 : head->right->h + 1;
		lh = head->left == nullptr ? 1 : head->left->h + 1;
		if (abs(rh - lh) == 2) {
			if (val >= head->val) {
				if (head->right!=nullptr && val >= head->right->val)
					head = rr1123(head);
				else
					head = rl1123(head);
			}
			else {
				if (head->left != nullptr && val >= head->left->val)
					head = lr1123(head);
				else
					head = ll1123(head);
			}
		}
		if (head->left == nullptr) {
			head->h = head->right->h + 1;
		}
		else if (head->right == nullptr)
			head->h = head->left->h + 1;
		else
			head->h = ((head->left->h > head->right->h) ? head->left->h : head->right->h) + 1;
		return head;
	}
}

int main1123() {
	int n;
	int num = 0;
	unsigned int idx = 0;
	queue<node1123*>que;
	cin >> n;
	node1123* head = nullptr;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		head = avl_insert1123(tmp, head);
	}
	if (head == nullptr) {
		cout << "NO" << endl;
		return 0;
	}
	que.push(head->left);
	que.push(head->right);
	cout << head->val;
	while (!que.empty()) {
		num = que.size();
		for (int i = 0; i < num; i++) {
			if (que.front() != nullptr) {
				idx = (idx << 1) + 0;
				cout << " " << que.front()->val;
			}
			else {
				idx = (idx << 1) + 1;
				que.pop();
				continue;
			}

			que.push(que.front()->left);
			que.push(que.front()->right);
			que.pop();
		}
	}
	cout << endl;
	while (idx > 0 && (idx & 1))idx=idx >> 1;
	if (idx)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	system("pause");
	return 0;
}