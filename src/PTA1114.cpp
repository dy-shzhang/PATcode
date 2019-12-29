#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//并不是所有元素都有节点对应
//用dfs会丢失那些有节点
/*
struct node {
	int estate;
	int area;
	vector<int>rela;
	node() {
		estate = 0;
		area = 0;
	}

};

struct nodeAns {
	int id;
	int m;
	double avgset;
	double avgarea;
	nodeAns(int _id, int _m, double _ast, double _aar) {
		id = _id;
		m = _m;
		avgset = _ast;
		avgarea = _aar;
	}
};

void dfs(node member[], int *known, int idx, set<int>&all, int &sumSet, int&sumArea) {
	known[idx] = 1;
	all.insert(idx);
	for (int i = 0; i < member[idx].rela.size(); i++) {
		if (known[member[idx].rela[i]] == 0) {
			sumSet += member[idx].estate;
			sumArea += member[idx].area;
			dfs(member, known, member[idx].rela[i], all, sumSet, sumArea);
		}

	}
}
bool cmp(const nodeAns& a, const nodeAns& b) {
	if (a.avgarea > b.avgarea)
		return true;
	else if (a.avgarea == b.avgarea)
		return a.id < b.id;
	return false;
}

int main() {
	node member[10001];
	int known[10001];
	fill(known, known + 10001, 0);
	vector<int>namelist;
	vector<nodeAns>ans;
	int n,cnt;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int name, fa, mom, nch, child, est, are;
		cin >> name >> fa >> mom;
		namelist.push_back(name);
		if (fa != -1)
			member[name].rela.push_back(fa);
		if (mom != -1)
			member[name].rela.push_back(mom);
		cin >> nch;
		for (int i = 0; i < nch; i++) {
			cin >> child;
			member[name].rela.push_back(child);
		}
		cin >> est >> are;
		member[name].estate = est;
		member[name].area = are;
	}
	cnt = 0;
	while (1) {
		int u = -1;
		for (int i = 0; i < namelist.size(); i++) {
			if (known[namelist[i]] == 0) {
				u = i;
				break;
			}
		}
		if (u == -1)
			break;
		//known[namelist[u]] = 1;
		int sumSet = 0, sumArea = 0;
		set<int>all;
		dfs(member, known, namelist[u], all, sumSet, sumArea);
		cnt++;
		nodeAns tmp = nodeAns(int(*all.begin()), int(all.size()), double(sumSet / all.size()), double(sumArea / all.size()));
		ans.push_back(tmp);
	}
	sort(ans.begin(), ans.end(), cmp);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].m, ans[i].avgset, ans[i].avgarea);
	}
	system("pause");
	return 0;
}*/

//并集合
//

struct node1114 {
	int id, fid, mid;
	int est, area;
	vector<int>child;
	node1114() {
		id = 0;
		fid = 0;
		mid = est = area = 0;
	}
}member1114[10001];

struct nodeAns1114 {
	int id;
	int allarea;
	int allset;
	int mbr;
	bool flag;
	nodeAns1114() {
		id = allset = allarea = mbr = 0;
		flag = false;
	}
}ans1114[10001];

int father1114[10001];
int visit1114[10001];

int find1114(int x) {
	while (x != father1114[x])
		x = father1114[x];
	return x;
}

void Union1114(int a, int b) {
	a = find1114(a);
	b = find1114(b);
	if (a > b)
		father1114[a] = b;
	else
		father1114[b] = a;
}

bool cmp1114(nodeAns1114 a, nodeAns1114 b) {
	if (a.allarea / (double)a.mbr > b.allarea / (double)b.mbr)
		return true;
	else if (a.allarea / (double)a.mbr == b.allarea / (double)b.mbr)
		return a.id < b.id;
	return false;
}

int main1114() {
	int n, cnt = 0;
	vector<nodeAns1114>vans;
	cin >> n;
	for (int i = 0; i < 10001; i++) {
		father1114[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int _id, _fid, _mid, nchild;
		//int nchild;
		cin >> _id >> _fid >> _mid >> nchild;
		member1114[_id].id = _id;
		member1114[_id].fid = _fid;
		member1114[_id].mid = _mid;
		//cin >> member[i].id >> member[i].fid >> member[i].mid >> nchild;
		visit1114[_id] = 1;
		if (_fid != -1) {
			Union1114(_id, _fid);
			visit1114[_fid] = 1;
		}
		if (_mid != -1) {
			Union1114(_id, _mid);
			visit1114[_mid] = 1;
		}
		for (int j = 0; j < nchild; j++) {
			int tmp;
			cin >> tmp;
			Union1114(_id, tmp);
			visit1114[tmp] = 1;
		}
		cin >> member1114[_id].est >> member1114[_id].area;

	}
	for (int i = 0; i < 10001; i++) {
		if (visit1114[i] == 1) {
			int f = find1114(i);
			ans1114[f].id = f;
			ans1114[f].flag = true;
			ans1114[f].mbr++;
			ans1114[f].allarea += member1114[i].area;
			ans1114[f].allset += member1114[i].est;
		}
	}
	for (int i = 0; i < 10001; i++) {
		if (ans1114[i].flag == 1) {
			cnt++;
			vans.push_back(ans1114[i]);
		}

	}
	cout << cnt << endl;
	sort(vans.begin(), vans.end(), cmp1114);
	for (int i = 0; i < vans.size(); i++) {
		printf("%04d %d %.3f %.3f\n", vans[i].id, vans[i].mbr, vans[i].allset / (double)vans[i].mbr, vans[i].allarea / (double)vans[i].mbr);
	}
	system("pause");
	return 0;
}