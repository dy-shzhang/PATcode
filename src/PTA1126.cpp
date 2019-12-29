#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
//之前将题目意思完全理解错了
//实际上很简单，但是题目理解错了导致复杂度陡增
//有一个测试案例过不了，应该是某些特殊情况没有考虑到
//忘记考虑连通性了,用dfs+计数的方法确认连通性
using namespace std;
/*
bool dfs1126(int start, int level, int edg, vector<int>grap[], map<int, int>know) {
	if (level == edg) {
		return true;
	}
	else {
		for (auto i : grap[start]) {
			if (know[start * 1000 + i] != 1) {
				know[start * 1000 + i] = know[i * 1000 + start] = 1;
				if (dfs1126(i, level + 1, edg, grap, know))
					return true;
				know[start * 1000 + i] = know[i * 1000 + start] = 0;
			}
		}
		return false;
	}
}

int main1126() {
	int v, e;
	int cont = 0;
	vector<int>grap[501];
	map<int, int>know;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		grap[x].push_back(y);
		grap[y].push_back(x);
	}
	bool flag = false;
	for (int i = 1; i <= v; i++) {
		flag = dfs1126(i, 0, e, grap, know);
		if (flag)
			break;
	}

	cout << grap[1].size();
	if (grap[1].size() & 1)
		cont++;
	for (int i = 2; i <= v; i++) {
		cout << " " << grap[i].size();
		if (grap[i].size() & 1)
			cont++;
	}
	cout << endl;

	if (flag) {
		cout << (cont == 0 ? "Eulerian" : (cont == 2 ? "Semi-Eulerian" : "Non-Eulerian")) << endl;
	}
	else
		cout << "Non-Eulerian" << endl;
	system("pause");
	return 0;
}*/

void dfs1126(int idx, vector<int>record[], vector<int>&known,int&n) {
	known[idx] = 1;
	n++;
	for (auto i : record[idx]) {
		if (known[i] == 0)
			dfs1126(i, record, known,n);
	}
}

int main1126() {
	vector<int>record[501];
	vector<int>known(501,0);
	int flag = false;
	int odd = 0;
	int num = 0;
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		record[v1].push_back(v2);
		record[v2].push_back(v1);

	}
	dfs1126(1, record, known,num);
	if (num != v)
		flag = true;
	cout << record[1].size();
	if (record[1].size() & 1)odd++;
	for (int i = 2; i <= v; i++) {
		cout << " " << record[i].size();
		if (record[i].size() & 1)odd++;
		if (record[i].size() == 0)flag = true;
	}
	cout << endl;
	if (flag==true) {
		cout << "Non-Eulerian" << endl;
		system("pause");
		return 0;
	}
	if (odd == 2) {
		cout << "Semi-Eulerian" << endl;;
	}
	else if (odd == 0) {
		cout << "Eulerian" << endl;
	}
	else
		cout << "Non-Eulerian" << endl;
	system("pause");
	return 0;
}