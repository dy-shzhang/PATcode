#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct Node1097 {
	int val;
	int next;
}nodeTree1097[1000000];

int main1097() {
	int s, n;
	int u;
	cin >> s >> n;
	map<int, int>show;
	vector<int>address;
	for (int i = 0; i < n; i++) {
		int add, val, next;
		cin >> add >> val >> next;
		nodeTree1097[add].val = val;
		nodeTree1097[add].next = next;
	}
	u = s;
	int un = nodeTree1097[s].next;
	show[abs(nodeTree1097[s].val)] = 1;
	while (un != -1) {
		if (show[abs(nodeTree1097[un].val)] == 1) {
			nodeTree1097[u].next = nodeTree1097[un].next;
			address.push_back(un);
			un = nodeTree1097[un].next;
		}
		else {
			show[abs(nodeTree1097[un].val)] = 1;
			u = un;
			un = nodeTree1097[un].next;
		}
	}
	u = s;
	while (u != -1) {
		if (nodeTree1097[u].next != -1)
			printf("%05d %d %05d\n", u, nodeTree1097[u].val, nodeTree1097[u].next);
		else
			printf("%05d %d %d\n", u, nodeTree1097[u].val, nodeTree1097[u].next);
		u = nodeTree1097[u].next;
	}
	for (int i = 0; i < address.size(); i++) {
		if (i != address.size() - 1)
			printf("%05d %d %05d\n", address[i], nodeTree1097[address[i]].val, address[i + 1]);
		else
			printf("%05d %d -1\n", address[i], nodeTree1097[address[i]].val);
	}
	system("pause");
	return 0;
}