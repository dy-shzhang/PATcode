#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int mainst1() {
	int n, m;
	int t1, t2;
	map<int, int>obs;
	cin >> m >> n;
	int dp[33][33];
	fill(dp[0], dp[0] + 33 * 33, 1);
	while (cin) {
		cin >> t1 >> t2;
		obs[100 * t1 + t2] = 1;
		dp[t1][t2] = 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (obs[i * 100 + j] == 1)
				dp[i][j] = 0;
			else
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}
	cout << dp[m][n] << endl;
	system("pause");
	return 0;
}