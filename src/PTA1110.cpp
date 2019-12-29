#include<iostream>
#include<string>
#include<queue>
using namespace  std;
struct Node1110 {
public:
	int left;
	int right;
	int parent;
	Node1110() {
		left = -1;
		right = -1;
		parent = -1;
	}
}nodeTree1110[100];

int u1110, n1110;

void dfs1110(int uindx, int indx,int& maxindx, vector<int>&haveNode) {
	if (uindx == -1)
		return;
	else {
		haveNode[uindx] = indx;
		if (indx > haveNode[maxindx])
			maxindx = uindx;
		if (haveNode[maxindx] > n1110)
			return;
		dfs1110(nodeTree1110[uindx].left, 2 * indx, maxindx, haveNode);
		dfs1110(nodeTree1110[uindx].right, 2 * indx + 1, maxindx, haveNode);
	}
}


int main1110() {
	int state = 0;
	int si = 0;
	int current;
	int indx = 1;
	int maxindx = 1;
	string a, b;
	queue<int>record;
	vector<int>haveNode(40);
	cin >> n1110;
	for (int i = 0; i < n1110; i++) {
		cin >> a >> b;

		if (a[0] != '-') {
			nodeTree1110[i].left = a[0] - '0';

			nodeTree1110[a[0] - '0'].parent = i;
		}
		if (b[0] != '-') {
			nodeTree1110[i].right = b[0] - '0';
			nodeTree1110[b[0] - '0'].parent = i;
		}
	}
	u1110 = -1;
	for (int i = 0; i < 100; i++) {
		if (nodeTree1110[i].parent == -1) {
			u1110 = i;
			break;
		}
	}
	maxindx = u1110;
	dfs1110(u1110,indx,maxindx, haveNode);

	if (haveNode[maxindx] == n1110)
		cout << "YES " <<maxindx<<endl;
	else
		cout << "NO " << u1110 << endl;
	system("pause");
	return 0;
}