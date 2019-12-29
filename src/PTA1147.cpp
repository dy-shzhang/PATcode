#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//���ų����ж�heap������
//�����a[i/2]>a[i],��aһ������minheap������a[i/2]��a[i],��aһ������maxheap;
//���ж�ʱ��Ҫѡ�� ��ȷ���� ��������Ϊ�жϱ�׼
//�����ж�ÿ��·���Ƿ���max or  min�� ����Ҫ��ȫ��״̬�۲������ȷ�����м�����ǲ�ȷ���ģ���������Ϊ�ж����ݡ�
//����ѧ���ϵĽǶ���˵���������ж�ʮ�����ѵģ����������������ܶ�ʱ�����Կ��� �����⡣����������ٺܶࡣ 



// void getpath(vector<vector<int>>&allpath, vector<int>path, vector<int>&postodr, int level, vector<int>&levodr) {
// 	path.push_back(levodr[level]);
// 	if(2*level <levodr.size())
// 		getpath(allpath, path, postodr, 2 * level, levodr);
// 	else {
// 		postodr.push_back(levodr[level]);
// 		allpath.push_back(path);
// 		return;
// 	}
// 	if(2 * level+1 < levodr.size())
// 		getpath(allpath, path, postodr, 2 * level+1, levodr);
// 	postodr.push_back(levodr[level]);
// }
// int isheap(vector<int>& levodr,vector<int>& postodr) {
// 	vector<vector<int>>allpath;
// 	vector<int>path;
// 	int flag = 0;
// 	getpath(allpath, path, postodr, 1,levodr);
// 	for (int i = 0; i < allpath.size(); i++) {
// 		int tar = 0;
// 		int sim = 0;
// 		if (allpath[i][0] > allpath[i][allpath[i].size() - 1])
// 			sim = 1;
// 		else
// 			sim = -1;
// 		for (int j = 1; j < allpath[i].size(); j++) {
// 			if (allpath[i][j - 1] > allpath[i][j])
// 				tar++;
// 			else if (allpath[i][j - 1] < allpath[i][j])
// 				tar--;
// 			else
// 				tar += sim;
// 		}
// 		if (tar != 0)
// 			flag += tar / abs(tar);
// 		else
// 			flag++;
// 	}
// 	if (flag == allpath.size())
// 		return 1; // max heap
// 	else if (flag == -1*allpath.size())
// 		return 0; //min heap
// 	else
// 		return -1;//no heap
// }

// int getpath(vector<int>&postodr, int level, vector<int>&levodr) {
// 	int flag1, flag2,flag3;
// 	if (2 * level + 1 < levodr.size()) {
// 		flag1 = getpath(postodr, 2 * level, levodr);
// 		flag2 = getpath(postodr, 2 * level + 1, levodr);
// 		postodr.push_back(levodr[level]);
// 		if (flag1 != flag2)
// 			return 0;
// 		else {
// 			if (levodr[level] >= levodr[2 * level] && levodr[level] >= levodr[2 * level + 1])
// 				flag3 = 1;
// 			else if (levodr[level] <= levodr[2 * level] && levodr[level] <= levodr[2 * level + 1])
// 				flag3 = -1;
// 			else
// 				return 0;
// 
// 			if (flag1 == flag3)
// 				return flag3;
// 		}
// 	}
// 	else if (2 * level < levodr.size()) {
// 		flag1 = getpath(postodr, 2 * level, levodr);
// 		postodr.push_back(levodr[level]);
// 		if (flag1 == 0)
// 			return 0;
// 		else {
// 			if (levodr[level] > levodr[2 * level])
// 				flag3 = 1;
// 			else if (levodr[level] < levodr[2 * level])
// 				flag3 = -1;
// 			else
// 				return flag1;
// 
// 			if (flag1 == flag3)
// 				return flag3;
// 			else
// 				return 0;
// 		}
// 	}
// 	else {
// 		postodr.push_back(levodr[level]);
// 		if (levodr[level] <= levodr[0])
// 			return 1;
// 		else
// 			return -1;
// 	}
// 
// 	//postodr.push_back(levodr[level]);
// }

void getpath1147(vector<int>& postodr, int lev, vector<int>&levodr) {
	if (2 * lev + 1 < levodr.size()) {
		getpath1147(postodr, 2 * lev, levodr);
		getpath1147(postodr, 2 * lev + 1, levodr);
	}
	else if (2 * lev +1 == levodr.size()) {
		getpath1147(postodr, 2 * lev, levodr);
	}
	postodr.push_back(levodr[lev]);
}
void isheap1147(vector<int>& levodr, vector<int>& postodr) {
	getpath1147(postodr, 1, levodr);
	int isMin = 1;
	int isMax = 1;
	for (int i = 2; i < levodr.size(); i++) {
		if (levodr[i / 2] > levodr[i])
			isMin = 0;
		if (levodr[i / 2] < levodr[i])
			isMax = 0;
	}
	if (isMin == 1)
		cout << "Min Heap" << endl;
	else {
		cout << (isMax == 1 ? "Max Heap" : "Not Heap")<<endl;
	}
	cout << postodr[0];
	for (int i = 1; i < postodr.size(); i++)
		cout << " " << postodr[i];
	cout << endl;
}

int main1147() {
	int N, M;
	cin >> N >> M;
	vector<int>levodr(M+1);
	vector<int>postodr;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> levodr[j];
		postodr.clear();
		isheap1147(levodr, postodr);
	}
	system("pause");
	return 0;
}