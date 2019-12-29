#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

struct Node1106 {
	int si;
	vector<int>member;
	Node1106() {
		si = 0;
	}
}NodeTree[100001];

void dfs1106(int indx, int level, int&lw,int&num) {
	if (NodeTree[indx].si == 0 || level>lw) {
		if (lw > level) {
			lw = level;
			num = 1;
		}
		else if (lw == level) {
			num++;
		}
		return;
	}
	for (int i = 0; i < NodeTree[indx].si; i++) {
		dfs1106(NodeTree[indx].member[i], level + 1, lw,num);
	}

}

int main1106() {
	int n;
	double p, r;
	cin >> n >> p >> r;
	int lw = n;
	int num = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			int no;
			cin >> no;
			NodeTree[i].si++;
			NodeTree[i].member.push_back(no);
		}
	}
	dfs1106(0, 0, lw,num);
	double all = p * pow((1. + r / 100.), double(lw));
	printf("%.4f %d\n", all, num);
	system("pause");
	return 0;
}