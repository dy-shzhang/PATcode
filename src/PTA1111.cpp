#include<iostream>
#include<vector>
#define inf1111 0x7fffffff
using namespace std;

int graTime1111[501][501];
int graLength1111[501][501];

int shortLength1111[501];
int shortPath1111[501];
int fastest1111[501];

int fastLength1111[501];
int fastPath1111[501];
int shortest1111[501];

bool known1111[501];

int main1111() {
	fill(graTime1111[0], graTime1111[0] + 501 * 501, inf1111);
	fill(graLength1111[0], graLength1111[0] + 501 * 501, inf1111);
	fill(shortLength1111, shortLength1111 + 501, inf1111);
	fill(fastLength1111, fastLength1111 + 501, inf1111);
	fill(fastest1111, fastest1111 + 501, 0);
	fill(shortest1111, shortest1111 + 501, inf1111);
	fill(known1111, known1111 + 501, false);
	vector<int>pathl,patht;
	int n, m;
	int s, t;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2, dual, length, time;
		cin >> v1 >> v2 >> dual >> length >> time;
		graTime1111[v1][v2] = time;
		graLength1111[v1][v2] = length;
		if (dual == 0) {
			graTime1111[v2][v1] = time;
			graLength1111[v2][v1] = length;
		}
	}
	cin >> s >> t;

	shortPath1111[s] = -1;
	shortLength1111[s] = 0;

	fastPath1111[s] = -1;
	fastLength1111[s] =0;

	fastest1111[s] =  0;
	shortest1111[s] = 0;

	while (1) {
		int u = -1;
		int dis = inf1111;
		for (int i = 0; i < n; i++) {
			if (known1111[i] == false && shortLength1111[i] < dis) {
				u = i;
				dis = shortLength1111[i];
			}
		}
		if (u == -1)
			break;
		known1111[u] = true;
		for (int i = 0; i < n; i++) {
			if (known1111[i] == false && graLength1111[u][i] != inf1111) {
				if (shortLength1111[i] > shortLength1111[u] + graLength1111[u][i]) {
					shortPath1111[i] = u;
					shortLength1111[i] = shortLength1111[u] + graLength1111[u][i];
					fastest1111[i] = fastest1111[u]+graTime1111[u][i];
				}
				else if (shortLength1111[i] == shortLength1111[u] + graLength1111[u][i]) {
					if (fastest1111[i] > fastest1111[u] + graTime1111[u][i]) {
						fastest1111[i] = fastest1111[u] + graTime1111[u][i];
						shortPath1111[i] = u;
					}
				}
			}
		}
	}
	fill(known1111, known1111 + 501, false);
	while (1) {
		int u = -1;
		int time = inf1111;
		for (int i = 0; i < n; i++) {
			if (known1111[i] == false && fastLength1111[i] < time) {
				u = i;
				time = fastLength1111[i];
			}
		}
		if (u == -1)
			break;
		known1111[u] = true;
		for (int i = 0; i < n; i++) {
			if (known1111[i] == false && graTime1111[u][i] != inf1111) {
				if (fastLength1111[i] > fastLength1111[u] + graTime1111[u][i]) {
					fastLength1111[i] = fastLength1111[u] + graTime1111[u][i];
					fastPath1111[i] = u;
					shortest1111[i] = shortest1111[u] + 1;
				}
				else if (fastLength1111[i] == fastLength1111[u] + graTime1111[u][i]) {
					if (shortest1111[i] > shortest1111[u] + 1) {
						fastPath1111[i] = u;
						shortest1111[i] = shortest1111[u] + 1;
					}
				}
			}
		}
	}
	int u = t;
	while (u != -1) {
		pathl.push_back(u);
		u = shortPath1111[u];
	}
      u = t;
	while (u != -1) {
		patht.push_back(u);
		u = fastPath1111[u];
	}
	if (pathl == patht) {
		cout << "Distance = " << shortLength1111[t] << "; Time = " << fastLength1111[t] << ": ";
		for (int i = pathl.size() - 1; i >= 0; i--) {
			cout << pathl[i];
			if (i != 0)
				cout << " -> ";
		}
		cout << endl;
	}
	else {
		cout << "Distance = " << shortLength1111[t]<< ": ";
		for (int i = pathl.size() - 1; i >= 0; i--) {
			cout << pathl[i];
			if (i != 0)
				cout << " -> ";
		}
		cout << endl;
		cout << "Time = " << fastLength1111[t] << ": ";
		for (int i = patht.size() - 1; i >= 0; i--) {
			cout << patht[i];
			if (i != 0)
				cout << " -> ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}