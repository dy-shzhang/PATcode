#include<iostream>
#include<vector>
#include<algorithm>
//通过 前序 和 中序重建 二叉树
//查询 某个值是否在树内，并输出其从根到它的路径。
//
using namespace std;

class Node1151 {
public:
	int value;
	Node1151* rnext;
	Node1151* lnext;
public:
	Node1151(int _value) :value(_value) {
		lnext = NULL;
		rnext = NULL;
	}
};

class Solution1151 {
public:
	Node1151* head;
	int _si;
	int height;

public:
	Solution1151(int _size) {
		_si = _size;
		head = NULL;
		height = 0;
	};
	~Solution1151() {

	};

	void formTree(vector<int>pre, vector<int>inodr) {
		int idx = 0;
		head=_formTree(0, inodr.size(),idx, pre, inodr);
	};

	vector<int> getpath(int check) {
		vector<int>rpath;
		bool flag = _getpath(check, rpath, head);
		if (flag == true) {
			reverse(rpath.begin(),rpath.end());
		}
		return rpath;
	};

private:

	Node1151* _formTree(int l, int r, int& indx, vector<int>&pre, vector<int>&inodr) {
		if (l>=r ||indx > inodr.size()) {
			return NULL;
		}
		else {
			int mid = l;
			while (/*mid <r &&*/ pre[indx] != inodr[mid])mid++;
// 			if (mid >= r)
// 				return NULL;
			//这里的indx很重要，因为indx一直向后移动，不会前移
			//所以要用 & 引用，保证indx随着程序一直增长
			//一定分析清楚
			Node1151* tmp = new Node1151(pre[indx]);
			indx += 1;
			tmp->lnext = _formTree(l, mid, indx, pre, inodr);
			tmp->rnext = _formTree(mid + 1, r, indx, pre, inodr);
			return tmp;
		}
	};
	bool _getpath(int check,vector<int>&path,Node1151* head) {
		if (head == NULL) {
			return false;
		}
		else if (head->value == check) {
			path.push_back(head->value);
			return true;
			}
		else {
			if (_getpath(check, path, head->lnext) == true) {
				path.push_back(head->value);
				return true;
			}
			else if (_getpath(check, path, head->rnext) == true) {
				path.push_back(head->value);
				return true;
			}
			else
				return false;
		}
	};
};

int main1151() {
	vector<int>pre;
	vector<int>inodr;
	int M, N;
	int val1, val2;
	cin >> M >> N;
	Solution1151 sol(N);
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		inodr.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		pre.push_back(tmp);
	}
	sol.formTree(pre, inodr);
	for (int i = 0; i < M; i++) {
		cin >> val1 >> val2;
		auto path1 = sol.getpath(val1);
		auto path2 = sol.getpath(val2);
		if (path1.size() == 0 && path2.size()==0) {
			cout << "ERROR: " << val1 << " and " << val2 << " are not found." << endl;
		}
		else if (path1.size() == 0) {
			cout << "ERROR: " << val1 << " is not found." << endl;
		}
		else if (path2.size() == 0) {
			cout << "ERROR: " << val2 << " is not found." << endl;
		}
		else {
			int idx = 0;
			while (idx < path1.size() && idx < path2.size() && path1[idx] == path2[idx])idx++;
			if (idx == path1.size()) {
				cout << val1 << " is an ancestor of " << val2 << "." << endl;
			}
			else if (idx == path2.size()) {
				cout << val2 << " is an ancestor of " << val1 << "." << endl;
			}
			else {
				cout << "LCA of " << val1 << " and " << val2 << " is "<<path1[idx-1]<<"." << endl;
			}
		}
	}
	system("pause");
	return 0;
}