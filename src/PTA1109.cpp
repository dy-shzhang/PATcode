#include<iostream>
#include<vector>
#define INFI 0x7fffffff

using namespace std;

void djkpath(int s, int grp[501][501], int time[501][501], int*dis, int*known, int*path) {
	int u = -1;
	int sml = INFI;
	for (int i = 0; i < 501; i++) {
		if (known[i] == 0 && dis[i] < sml) {
			u = i;
			sml = dis[i];
		}
	}
	if (u == -1)
		return;
	known[u] = 0;
	for (int i = 0; i < 501; i++) {
		if (dis[i] > dis[u] + grp[u][i]) {
			dis[i] = dis[u] + grp[u][i];
			path[i] = u;
		}
		else if (dis[i] == dis[u] + grp[u][i]) {
			int idx = i, t1 = 0, t2 = 0;
			while (path[idx] != -1) {
				t1 += time[idx][path[idx]];
			}
			idx = u;
			while (path[idx] != -1) {
				t2 += time[idx][path[idx]];
			}
			t2 += time[i][u];
			if (t2 < t1)
				path[i] = u;
		}
	}
}

void djktime(int s, int time[501][501], int grp[501][501], int*dis, int*known, int*path) {
	int u = -1;
	int sml = INFI;
	for (int i = 0; i < 501; i++) {
		if (known[i] == 0 && dis[i] < sml) {
			u = i;
			sml = dis[i];
		}
	}
	if (u == -1)
		return;
	known[u] = 0;
	for (int i = 0; i < 501; i++) {
		if (dis[i] > dis[u] + grp[u][i]) {
			dis[i] = dis[u] + grp[u][i];
			path[i] = u;
		}
		else if (dis[i] == dis[u] + grp[u][i]) {
			int c1 = 0, c2 = 0;
			int idx = i;
			while (idx != -1) {
				idx = path[idx];
				c1++;
			}
			idx = u;
			while (idx != -1) {
				idx = path[idx];
				c2++;
			}
			c2++;
			if (c2 < c1)
				path[i] = u;
		}
	}
}
int grp[501][501] = { INFI };
int tim[501][501] = { INFI };
int known1111[501] = { 0 };
int dis1[501] = { INFI };
int dis2[501] = { INFI };
int times[501] = { INFI };
int path[501] = { -1 };
int main1109() {

	vector<int>ans[2];
	int e, v, one, v1, v2;
	int d, t;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2 >> one >> d >> t;
		if (one == 1) {
			grp[v1][v2] = d;
			tim[v1][v2] = t;
		}
		else {
			grp[v1][v2] = d;
			tim[v1][v2] = t;
			grp[v2][v1] = d;
			tim[v2][v1] = t;
		}
	}
	cin >> v1 >> v2;

	djkpath(v1, grp, tim, dis1, known1111, path);
	int idx = v2;
	while (idx != -1) { ans[0].push_back(idx); idx = path[idx]; }
	fill(known1111, known1111 + 501, INFI);
	fill(path, path + 501, -1);
	djktime(v1, tim, grp, dis2, known1111, path);
	idx = v2;
	while (idx != -1) { ans[1].push_back(idx); idx = path[idx]; }
	if (ans[0] == ans[1]) {
		cout << "Distance = " << dis1[v2] << "; Time = " << dis2[v2] << ": ";
		cout << *ans[0].rbegin();
		for (auto i = ans[0].rbegin() + 1; i != ans[0].rend(); i++) {
			cout << " -> " << *i;
		}
	}
	else {
		cout << "Distance = " << dis1[v2] << ": ";
		for (auto i = ans[0].rbegin() + 1; i != ans[0].rend(); i++)
			cout << " -> " << *i;
		cout << endl;
		cout << "Time = " << dis2[v2] << ": ";
		for (auto i = ans[1].rbegin() + 1; i != ans[1].rend(); i++)
			cout << " -> " << *i;
	}
	cout << endl;
	system("pause");
	return 0;
}