#include<iostream>
#include<map>
#include<vector>
using namespace std;

//���鼯�������Դ��м������ԵĶ�����������෽����
//�ж�����������������һ�࣬�ȵ�

//��������������߼��������м��ϸ���ģ����� ��ĸ-��Ů PTA1114��������ϵ�����⣬������ ���鼯 �İ취

//�������и�������ʱ���²��ǳ���ʱ��ѭ����û�ҵ��������ڡ�

/*
int main1118() {
	int n,m;
	int treeid=0;
	cin >> n;
	map<int, int>bt;
	while (n--) {
		int tmp;
		int tree = 0;
		vector<int>birds;
		cin >> tmp;
		for (int i = 0; i < tmp; i++) {
			int id;
			cin >> id;
			if (tree == 0)
				tree = bt[id];
			birds.push_back(id);
		}
		if (tree != 0) {
			for (auto i : birds)
				bt[i] = tree;
		}
		else {
			treeid++;
			for (auto i : birds)
				bt[i] = treeid;
		}
	}
	cin >> m;
	cout << treeid << " " << bt.size() << endl;
	while (m--) {
		int t1, t2;
		cin >> t1 >> t2;
		if (bt[t1] == bt[t2] && bt[t1]!=0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	system("pause");
	return 0;
}*/
int find1118(int x, int* father) {
	while (x != father[x])
		x = father[x];
	return x;
}

void Union1118(int a, int b, int* father) {
	a = find1118(a, father);
	b = find1118(b, father);
	father[a] = b;
}

int main1118() {
	int visit[10001] = {0};//�����ʼ��
	int father[10001];
	int n, k, t1, t2;
	int cnt = 0, tcnt = 0;
	for (int i = 0; i <10001; i++) {
		father[i] = i;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		cin >> t1;
		visit[t1] = 1;
		for (int j = 1; j < k; j++) {
			cin >> t2;
			visit[t2] = 1;
			Union1118(t1, t2, father);
		}
	}
	for (int i = 0; i <10001; i++)
		if (visit[i]==1)cnt++;

	for (int i = 0; i <10001; i++) 
		if (i == father[i] && visit[i]==1)tcnt++;
	
	cout << tcnt << " " << cnt << endl;
	cin >> k;
	while (k--) {
		cin >> t1 >> t2;
		if (find1118(t1, father) == find1118(t2, father))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	system("pause");
	return 0;
}