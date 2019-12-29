#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//考虑特例，综和<m的情况下，不用计算

void dfs1068(int idx, int tmpsum, vector<int>&coins, vector<int>tmp, vector<vector<int>>&ans,int&m) {
	if (idx >= coins.size() || tmpsum>m || ans.size() > 0) {
		return;
	}
	tmpsum += coins[idx];
	if (tmpsum == m) {
		tmp.push_back(coins[idx]);
		ans.push_back(tmp);
	}
	else if (tmpsum  < m) {
		tmp.push_back(coins[idx]);
		for (int i = idx + 1; i < coins.size(); i++) {
			if (tmpsum + coins[i] > m || ans.size() > 0)
				break;
			dfs1068(i, tmpsum, coins, tmp, ans, m);
		}
	}
}
int main1068() {
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	vector<int>coins,tmp;
	vector<vector<int>>ans;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d",&tmp);
		cnt += tmp;
		coins.push_back(tmp);
	}
	if (cnt < m) {
		cout << "No Solution" << endl;
		return 0;
	}

	sort(coins.begin(), coins.end());
	if (cnt == m) {
		for (int i = 0; i < coins.size(); i++) {
			cout << coins[i];
			if (i != coins.size() - 1)
				cout << " ";
		}
		return 0;
	}
	for (int i = 0; i < coins.size(); i++) {
		if (coins[i] > m || ans.size()>0)
			break;
		dfs1068(i, 0, coins, tmp, ans, m);
	}
	if (ans.size() == 0)
		cout << "No Solution" << endl;
	else {
		for (int i = 0; i < ans[0].size(); i++) {
			cout << ans[0][i];
			if (i != ans[0].size() - 1)
				cout << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}