#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;
//gra 10000*10000 ̫����
//���԰�����û�����⡣����û��һ��ͨ���ģ�û�ҳ����⡣��������
//�õĹ������������queueʵ�ֹ�����ȡ�
// ������ɫ�ı�Ų��ǰ�˳�����ģ�������map�ж���ɫ����
//��ν���ʱ�临�Ӷȣ�
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