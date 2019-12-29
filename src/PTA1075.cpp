#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node1075 {
	vector<int>score;
	int id;
	int si;
	int allsore;
	Node1075() {
		id = 0x7fffffff;
		score.resize(4, -1);
		si = 0;
		allsore = -1;
	}
	void pushback(int _id, int idx, int t,int flag) {
		id = _id;
		if (t == -1) {
			score[idx - 1] = 0;
			return;
		}
		else if (allsore == -1) {
			allsore = 0;
		}
		if (t > score[idx - 1]) {
			if (flag == 1)
				si++;
			if (score[idx - 1] == -1) {
				allsore += t;
				score[idx - 1] = t;
			}
			else {
				allsore = allsore - score[idx - 1] + t;
				score[idx - 1] = t;
			}
		}
	}
}nodeTree1075[10001];

bool cmp1075(Node1075&a, Node1075&b) {
	if (a.allsore > b.allsore)
		return true;
	else if (a.allsore == b.allsore)
		if (a.si > b.si)
			return true;
		else if (a.si == b.si) {
			return a.id < b.id;
		}
	return false;
}

int main1075() {
	int p, k, n;
	cin >> p >> k >> n;
	vector<int>sco(k + 1, 0);

	for (int i = 1; i <= k; i++) {
		cin >> sco[i];
	}
	for (int i = 0; i < n; i++) {
		int id, indx, tp;
		int flag = 0;
		cin >> id >> indx >> tp;
		if (tp == sco[indx])
			flag = 1;
		nodeTree1075[id].pushback(id, indx, tp,flag);
	}
	sort(nodeTree1075, nodeTree1075 + p+1, cmp1075);
	int cont = 0;
	int tmpscore = 0;
	for (int i = 0; i < p; i++) {
		if (nodeTree1075[i].id == 0x7fffffff  || nodeTree1075[i].allsore<0)
			break;
		if (tmpscore != nodeTree1075[i].allsore) {
			tmpscore = nodeTree1075[i].allsore;
			cont = i + 1;
		}
		cout << cont << " ";
		printf("%05d ", nodeTree1075[i].id);
		cout << nodeTree1075[i].allsore;
		for (int j = 0; j < k; j++) {
			if (nodeTree1075[i].score[j] != -1)
				cout << " " << nodeTree1075[i].score[j];
			else
				cout << " " << "-";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}