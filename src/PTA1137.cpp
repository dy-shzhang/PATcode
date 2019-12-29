#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
//map �����ԣ�ֻҪʹ�þͻ�����
//�������map
//��map����hash�ã����vector map->hash vector������
//���ݽṹԽ��Խ��
//map<string,vecotr<int>> ������ʽ����������תΪvector<pair<string,vector<int>>>��ʱ̫��
//������map<string��int>��hash�ã�vector<Node>�����ݣ�����vector����ֱ��������Ҳ���ת������ʡʱ��
/*
bool cmp(pair<string, vector<int>>&a, pair<string, vector<int>>&b) {
	if (a.second[3] > b.second[3])
		return true;
	else if (a.second[3] == b.second[3]) {
		return a.first < b.first;
	}
	return false;
}
int main() {
	int p, m, n;
	cin >> p >> m >> n;
	map<string, vector<int>>record;
	for (int i = 0; i < p; i++) {
		string name;
		char cname[20];
		int tmp;
		scanf("%s %d",cname,&tmp);
		name = cname;
		if (tmp >= 200 && tmp<=900) {
			record[name].resize(4, -1);
			record[name][0] = tmp;
		}
	}
	for (int i = 0; i < m; i++) {
		string name;
		char cname[20];
		int tmp;
		scanf("%s %d", cname, &tmp);
		name = cname;
		if (record[name].size()==4&&tmp>=0 &&tmp<=100)
			record[name][1] = tmp;
	}
	for (int i = 0; i < n; i++) {
		string name;
		char cname[20];
		int tmp;
		scanf("%s %d", cname, &tmp);
		name = cname;
		if (record[name].size() == 4 && tmp >= 0 && tmp <= 100)
			record[name][2] = tmp;
	}
	vector<pair<string, vector<int>>>rec(record.begin(), record.end());
	for (auto i = rec.begin(); i != rec.end(); ) {
		if ((*i).second[2] < (*i).second[1]) {
			double tmp = (0.4*double((*i).second[1]) + 0.6*double((*i).second[2]));
			(*i).second[3] = (tmp-int(tmp)==0) ? int(tmp) : int(tmp) + 1;
		}
		else
			(*i).second[3] = (*i).second[2];
		++i;
	}
	sort(rec.begin(), rec.end(), cmp);
	for (int i = 0; i < rec.size(); i++) {
		if (rec[i].second[3] < 60)
			continue;
		printf("%s",rec[i].first.c_str());
		for (int j = 0; j < 4; j++) {
			if (rec[i].second[j] == 0)
				cout << " -1";
			else
				printf(" %d",rec[i].second[j]);
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
*/
class Node1137 {
public:
	string name;
	int points, mid, fnl, al;
	Node1137(string _name, int _p, int _m, int _f) {
		name = _name;
		points = _p;
		mid = _m;
		fnl = _f;
		al = 0;
	}
};

bool cmp1137(Node1137*&a, Node1137*&b) {
	if (a->al > b->al)
		return true;
	else if (a->al == b->al) {
		return a->name < b->name;
	}
	return false;
}
int main1137() {
	int p, n, m;
	int idx = 1;
	cin >> p >> n >> m;
	vector<Node1137*>record;
	map<string, int>nahas;
	for (int i = 0; i < p; i++) {
		string name;
		int tmp;
		cin >> name >> tmp;
		if (tmp >= 200 && tmp <= 900) {
			Node1137 *t = new Node1137(name, tmp, -1, -1);
			record.push_back(t);
			nahas[name] = idx++;
		}
	}
	for (int i = 0; i < n; i++) {
		string name;
		int tmp;
		cin >> name >> tmp;
		if (tmp >= 0 && tmp <= 100) {
			if (nahas[name] != 0) {
				record[nahas[name] - 1]->mid = tmp;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		string name;
		int tmp;
		cin >> name >> tmp;
		if (tmp >= 0 && tmp <= 100) {
			if (nahas[name] != 0) {
				record[nahas[name] - 1]->fnl = tmp;
				if (record[nahas[name] - 1]->mid > record[nahas[name] - 1]->fnl)
					record[nahas[name] - 1]->al = int(0.4*record[nahas[name] - 1]->mid + 0.6*record[nahas[name] - 1]->fnl + 0.5);
				else
					record[nahas[name] - 1]->al = record[nahas[name] - 1]->fnl;
			}
		}
	}
	sort(record.begin(), record.end(), cmp1137);
	for (int i = 0; i < record.size(); i++) {
		if (record[i]->al < 60)
			break;
		cout << record[i]->name << " " << record[i]->points << " " << record[i]->mid << " " << record[i]->fnl << " " << record[i]->al << endl;
	}
	system("pause");
	return 0;
}