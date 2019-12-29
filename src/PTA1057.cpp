#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

struct Node1057 {
	int si;

	vector<int>record;
	Node1057() {
		si = -1;//
	}
	void Push(int x) {
		if (record.size() > si + 1)
			record[si+1]=x;
		else
			record.push_back(x);
		si++;
	}
	void Pop() {
		if (si >= 0) {
			cout << record[si] << endl;
			si--;
		}
		else {
			cout << "Invalid" << endl;
		}
	}
	void PeekMedian() {
		if (si >= 0) {
			multiset<int>tmp(record.begin(), record.begin() + si + 1);
			multiset<int>::iterator it = tmp.begin();
			for (int i = 0; i < si / 2; i++)++it;

			cout << *(it) << endl;
		}
		else
			cout << "Invalid" << endl;
	}
};

int main1057() {

	Node1057 stk;
	int n;
	string tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp.size() == 3)
			stk.Pop();
		else if (tmp.size() == 4) {
			int tp;
			cin >> tp;
			stk.Push(tp);
		}
		else {
			stk.PeekMedian();
		}
	}
	system("pause");
	return 0;

}