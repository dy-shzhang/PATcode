#define _CRT_SECURE_NO_WARNINGS			
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
//�ڴ泬��,�ƺ���Ϊmap���ܼ���ڴ�ռ�ô�
//�߼��Ǵ���ߣ��ж�һ����������ٱߡ�
//��߱���������Ѷ�һ�������Ǵ��ź���������
/*
int main() {
	int n, m, k;
	cin >> n >> m;
	map<int, int>record;
	map<int, int>has;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		record[(t1 * 10000 + t2)] = 1;
		has[t1]++;
		has[t2]++;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int t;
		int idx = 0;
		cin >> t;
		vector<int>subrec(t);
		for (int j = 0; j < t; j++) {
			cin >> subrec[j];
			idx += has[subrec[j]];
		}
		for (int j = 0; j < subrec.size(); j++) {
			for (int t = 0; t < subrec.size(); t++) {
				if (record[(subrec[t] * 10000 + subrec[j])] == 1)
					idx--;
			}
		}
		if (idx == m)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
	system("pause");
	return 0;
}
*/
int main1134() {
	int n, m, k,l;
	cin >> n >> m;
	vector<vector<int>> record;
	record.resize(n);
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		record[t1].push_back(i);//��ÿ���߽��б��i������Ǳߵı�Ŷ����Ǳ߱���
		record[t2].push_back(i);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		map<int, int>cont;
		cin >> l;
		for (int j = 0; j < l; j++) {
			int tmp;
			cin >> tmp;
			for (int p = 0; p < record[tmp].size(); p++) {
				cont[record[tmp][p]] = 1;
			}
		}
		cout << (cont.size() == m ? "Yes" : "No") << endl;
	}
	system("pause");
	return 0;
}