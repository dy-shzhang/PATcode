#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
//ѭ��Ƕ�ף�ʱ�临�Ӷȹ���
//��Ҫ��취����ʱ�临�Ӷȡ�
//�ҵ��뷨�ǣ��ж�װ�ϵĻ���i��j֮����û�г�ͻ������һ��Ҫ���ϵ�����i�Ľ��ɱ���j�໥�Ƚϡ�ʱ�临�Ӷ�n^3

//�𰸵��뷨�ǣ��ж���i�г�ͻ�Ļ����ڲ���j�С���Ϊ����ȥ�Ļ�����������ϣ���ʾa[100000],
//ͨ�����ͻ��Ʒ�ڲ���a[100000]�и�Ϊ���㡣�ռ��С�����Ҹ���
using namespace std;

/*
int main1149() {
	map<int,vector<int>>danlist;
	int N, M;
	int ngoods;
	vector<int>gds;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tp1, tp2;
		cin >> tp1 >> tp2;
		danlist[tp1].push_back(tp2);
		danlist[tp2].push_back(tp1);
	}
	for (int i = 0; i < M; i++) {
		bool flag = false;
		cin >> ngoods;
		for (int i = 0; i < ngoods; i++) {
			int tp;
			cin >> tp;
			gds.push_back(tp);
		}
		for (int i = 0; i < ngoods; i++) {
			for (int j = i + 1; j < ngoods; j++) {
				if (danlist[gds[i]].size() == 0)
					continue;
				else {
					for (int k = 0; k < danlist[gds[i]].size(); k++) {
						if (gds[j] == danlist[gds[i]][k]) {
							flag = true;
							break;
						}
					}
				}
				if (flag == true)
					break;
			}
			if (flag == true)
				break;
		}
		if (flag == true) {
			cout << "No" << endl;
			flag = false;
		}
		else
			cout << "Yes" << endl;
		gds.clear();
	}

	system("pause");
	return 0;
}
*/

int main1149Answer() {
	int n, k;
	cin >> n >> k;
	map<int, vector<int>>record;
	while (n--) {
		int id1, id2;
		cin >> id1 >> id2;
		record[id1].push_back(id2);
		record[id2].push_back(id1);
	}
	while (k--) {
		int time;
		bool flag = false;
		cin >> time;
		int woods[100000] = {0};//�����ʼ����������fill������0��
		vector<int>wds;
		for (int i = 0; i < time; i++) {
			int tmp;
			cin >> tmp;
			wds.push_back(tmp);
			woods[tmp] = 1;
		}
		for (int i = 0; i < time; i++) {
			for (int j = 0; j < record[wds[i]].size(); j++) {
				if (woods[record[wds[i]][j]] == 1) {
					cout << "No" << endl;
					flag = true;
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		if (flag)
			continue;
		cout << "Yes" << endl;
	}
	system("pause");
	return 0;
}