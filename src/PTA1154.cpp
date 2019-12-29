#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;
//gra 10000*10000 太大了
//测试案例，没有问题。线上没有一个通过的，没找出问题。。。。。
//用的广度优先搜索，queue实现广度优先。
// 由于颜色的编号不是按顺序来的，所以用map判断颜色个数
//如何降低时间复杂度？
vector<int>gra1154[10000];
//bool knowgra1154[10000];

int main1154() {
	int color[10000];
	map<int, int>colornumber;
	map<int, int>knowgra1154;
	int vert, edge, time;
	bool flag = false;
	cin >> vert >> edge;
	for (int i = 0; i < edge; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		gra1154[x].push_back(y);
		gra1154[y].push_back(x);
	}
	cin >> time;
	for (int i = 0; i < time; i++) {
		colornumber.clear();
		knowgra1154.clear();
		queue<int>nextvert;
		for (int j = 0; j < vert; j++) {
			cin >> color[j];
			colornumber[color[j]] = 1;
		}
		nextvert.push(0);
		while (!nextvert.empty()) {
			int thisvert = nextvert.front();
			knowgra1154[thisvert] = 1;
			nextvert.pop();
			for (int k = 0; k < gra1154[thisvert].size(); k++) {
				if (knowgra1154[gra1154[thisvert][k]] == 0) {
					if (color[thisvert] == color[gra1154[thisvert][k]]) {
						flag = true;
						break;
					}
					nextvert.push(gra1154[thisvert][k]);
				}
			}
			if (flag == true) {
				break;
			}
		}
		if (flag == true) {
			flag = false;
			cout << "No" << endl;
		}

		else {
			cout << colornumber.size() << "-coloring" << endl;
		}
	}
	system("pause");
	return 0;
}