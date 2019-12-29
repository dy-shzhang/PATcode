#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//���ⲻ��ϸ��Ҫ�󿴴���֮ǰ����DFS
//��map�ռ临�Ӷȱ�����С
//ʱ�临�ӶȽϸ�
//���԰�����������ͨ�������ⲻ��

//�·�����ֻ��¼ͬ�Ա����Ѻ�ȫ����ϵ��
//��ͬ��������������ϵ������

// ��Ҫ���������� 1�� -0000 �� 0000 ��int��ʱ���� 0 ���޷�������Ů��
//�������� string �������룬�ж������Ա���תΪint����

//2�� �������AB������ֱ����ʶ��ʱ��Ҳ�ǲ���ֱ����ϵ��
//3�� ��idʱ0023 ʱ��int�ͼ�¼��ʱ23��������� ��ʱ��Ҫ�� %04d

/*
bool cmp1139(pair<int, int>&a, pair<int, int>&b) {
	if (a.first < b.first)
		return true;
	else if (a.first == b.first) {
		if (a.second < b.second)
			return true;
	}
	return false;
}

int main1139() {
	map<string, vector<string>>record;
	map<pair<string, string>, int>con;
	int n, m, nm;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1.size() == s2.size()) {
			record[s1].push_back(s2);
			record[s2].push_back(s1);
		}

		con[pair<string, string>(s1, s2)] = 1;
		con[pair<string, string>(s2, s1)] = 1;
	}
	cin >> nm;
	for (int i = 0; i < nm; i++) {
		string s, e;
		cin >> s >> e;
		vector<pair<int, int>>tmp;
		for (auto its = record[s].begin(); its != record[s].end(); its++) {
			if ((*its)== e)
				continue;
			for (auto ite = record[e].begin(); ite != record[e].end(); ite++) {
				if ((*ite)== s || *ite == *its)
					continue;
				if (con[pair<string, string>(*its, *ite)] == 1)
					tmp.push_back(pair<int, int>(abs(stoi(*its)), abs(stoi(*ite))));
			}
		}
		sort(tmp.begin(), tmp.end(), cmp1139);
		cout << tmp.size() << endl;
		for (int j = 0; j < tmp.size(); j++) {
			cout << tmp[j].first << " " << tmp[j].second << endl;
		}
	}
	system("pause");
	return 0;
}
*/
bool cmp1139(pair<int, int>&a, pair<int, int>&b) {
	
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
		return a.second < b.second;
	return false;
}

int main1139() {
	int n, k, check;
	cin >> n >> k;
	map<int, int>relationShip;
	map<int, vector<int>>record;
	for (int i = 0; i < k; i++) {
		int p1, p2;
		string ps1, ps2;
		cin >> ps1 >> ps2;
		p1 = stoi(ps1);
		p2 = stoi(ps2);
		if (ps1.size() == ps2.size()) {//ֻ��¼ͬ�Ա�����,��Ҫ��Ϊ������-0000 0000 ������
			record[p1].push_back(p2);
			record[p2].push_back(p1);
		}
		relationShip[abs(p1) * 10000 + abs(p2)] = relationShip[abs(p2) * 10000 + abs(p1)] = 1;
	}
	cin >> check;
	while (check--) {
		int p1, p2;
		vector<pair<int, int>>ans;
		cin >> p1 >> p2;
		for (int j : record[p1])
			for (int i : record[p2]) {
				if (relationShip[abs(i) * 10000 + abs(j)] && p2!=j && p1!=i)ans.push_back(pair<int, int>(abs(j), abs(i)));
			}
		sort(ans.begin(), ans.end(), cmp1139);
		cout << ans.size() << endl;
		for (auto i : ans) {
			printf("%04d %04d\n", i.first, i.second);//����int����nameʱ��name=0000��ʱ���������0������Ҫ��%04d
		}
		ans.clear();
	}
	system("pause");
	return 0;
}