#include<iostream>
#include<vector>
using namespace std;

int mainWY2() {
	int n, k, T;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		vector<int>record(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> record[i];
		}
		vector<int>dp(n, 0);
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			int j = i + 1;
			while (j < n && j - i <= k) {
				if (record[j] <= record[i])
					dp[j] = dp[i] | dp[j];
				j++;
			}
		}
		// 		for (int i = 1; i < n; i++) {
		// 			int j = i;
		// 			while (j >= 0 && i - j <= k) {
		// 				if (record[i] <= record[j]) {
		// 					dp[i] = dp[i] | dp[j];
		// 				}
		// 				j--;
		// 			}
		// 		}
		if (dp[n - 1] == 1)
			cout << "YES" << endl;
		else {
			int idx = n - 1;
			while (dp[idx] == 0)idx--;
			if (idx + k >= n - 1)
				cout << "YES" << endl;
			else {
				dp[n - 1] = 1;
				for (int i = n - 1; i >= idx; i--) {
					int j = i - 1;
					while (j > idx && i - j <= k) {
						if (record[j] >= record[i])
							dp[j] = dp[i] | dp[j];
						j--;
					}
				}
				// 				for (int i = n - 1; i > idx; i--) {
				// 					int j = i;
				// 					while (j <= n - 1 && j - i <= k) {
				// 						if (record[i] >= record[j]) {
				// 							dp[i] = dp[i] | dp[j];
				// 						}
				// 						j++;
				// 					}
				// 				}
				int j = idx + 1;
				while (dp[j] == 0)
					j++;
				if (j <= idx + k)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		}
	}
	system("pause");
	return 0;
}