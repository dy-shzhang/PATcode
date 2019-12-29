#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

//有一个超时，不知道是真的超时还是死循环了
using namespace std;
int k1103, p1103;
void dfs1103(int n, int idx,int j, vector<int> tmp, vector<vector<int>>&record) {
	if (n < 0|| idx>=k1103)
		return;
	for (int i = j; pow(i, p1103)<=n; i++) {
		tmp[idx] = i;
		if (idx == k1103 - 1) {
			if (n - (int)pow(i, p1103) == 0)
				record.push_back(tmp);
		}
		else {
			dfs1103(n - (int)pow(i, p1103), idx + 1,i, tmp, record);//避免11112，12111，11211，11121这种重复搜索
															//所以加入一个条件，后一位要大于前一位
		}
	}
}
bool cmpmax1103(int&a, int&b) {
	return a > b;
}

bool cmp1103(vector<int>&a, vector<int>&b) {
	int s1 = 0;
	int s2 = 0;
	sort(a.begin(), a.end(), cmpmax1103);
	sort(b.begin(), b.end(), cmpmax1103);
	for (int i = 0; i < a.size(); i++) {
		s1 += a[i];
		s2 += b[i];
	}
	if (s1 > s2)
		return true;
	else if (s1 == s2) {
		return a > b;
	}
	return false;
}

int main1103() {
	int n;
	cin >> n >> k1103 >> p1103;
	vector<vector<int>>record;
	vector<int>tmp(k1103, 0);
	dfs1103(n, 0, 1, tmp, record);
	if (record.size() == 0)
		cout << "Impossible" << endl;
	else {
		sort(record.begin(), record.end(), cmp1103);
		sort(record[0].begin(), record[0].end(), cmpmax1103);//避免只有一个元素 的时候没有排序
		cout << n << " = ";
		for (int i = 0; i < record[0].size(); i++) {
			cout << record[0][i] << "^" << p1103;
			if (i != record[0].size() - 1) {
				cout << " + ";
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}