#include<iostream>
#include<queue>
using namespace std;
int gra1091[60][1286][128] = { 0 };
int known1091[60][1286][128] = { 0 };


struct Node1091 {
	int i;
	int j;
	int p;
	Node1091(int _i, int _j, int _p) {
		i = _i;
		j = _j;
		p = _p;
	}
};
int main1091() {
	int n, m, k;
	int t;
	int all = 0;
	queue<Node1091>ans;
	cin >> n >> m >> k >> t;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++)
			for (int p = 0; p < m; p++) {
				cin >> gra1091[i][j][p];
			}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++)
			for (int p = 0; p < m; p++) {
				if (known1091[i][j][p] == 0 && gra1091[i][j][p] == 1) {
					int tmp = 0;
					ans.push(Node1091{ i,j,p });
					while (!ans.empty()) {
						int si = ans.size();
						tmp += si;
						for (int z = 0; z < si; z++) {
							Node1091 ft = ans.front();
							known1091[ft.i][ft.j][ft.p] = 1;
							ans.pop();
							if (ft.i - 1 >= 0 && known1091[ft.i - 1][ft.j][ft.p] == 0 && gra1091[ft.i - 1][ft.j][ft.p] == 1) {
								ans.push(Node1091{ ft.i - 1 ,ft.j ,ft.p });
								known1091[ft.i - 1][ft.j][ft.p] = 1;
							}
							if (ft.i + 1 < k&&known1091[ft.i + 1][ft.j][ft.p] == 0 && gra1091[ft.i + 1][ft.j][ft.p] == 1) {
								ans.push(Node1091{ ft.i + 1 ,ft.j ,ft.p });
								known1091[ft.i + 1][ft.j][ft.p] = 1;
							}

							if (ft.j - 1 >= 0 && known1091[ft.i][ft.j - 1][ft.p] == 0 && gra1091[ft.i][ft.j - 1][ft.p] == 1) {
								ans.push(Node1091{ ft.i  ,ft.j - 1 ,ft.p });
								known1091[ft.i][ft.j - 1][ft.p] = 1;
							}
							if (ft.j + 1 < n&&known1091[ft.i][ft.j + 1][ft.p] == 0 && gra1091[ft.i][ft.j + 1][ft.p] == 1) {
								ans.push(Node1091{ ft.i ,ft.j + 1 ,ft.p });
								known1091[ft.i][ft.j + 1][ft.p] = 1;
							}

							if (ft.p - 1 >= 0 && known1091[ft.i][ft.j][ft.p - 1] == 0 && gra1091[ft.i][ft.j][ft.p - 1] == 1) {
								ans.push(Node1091{ ft.i  ,ft.j ,ft.p - 1 });
								known1091[ft.i][ft.j][ft.p - 1] = 1;
							}
							if (ft.p + 1 < m && known1091[ft.i][ft.j][ft.p + 1] == 0 && gra1091[ft.i][ft.j][ft.p + 1] == 1) {
								ans.push(Node1091{ ft.i  ,ft.j ,ft.p + 1 });
								known1091[ft.i][ft.j][ft.p + 1] = 1;
							}
						}
					}
					if (tmp >= t)
						all += tmp;
				}
			}
	}
	cout << all << endl;
	system("pause");
	return 0;
}