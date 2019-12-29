#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>


//vector<vector<int>>record(3, vector<int>(4, 0));

using namespace std;

int mainwy6() {
	int n = 0, m, v, t;
	char c;
	string s;
	vector<int>record;
	scanf("%d%c", &t, &c);
	record.push_back(t);
	while (c != '\n') {
		scanf("%d%c", &t, &c);
		record.push_back(t);
	}
	n = record.size();
	vector<int>dp(n, 0);
	dp[0] = record[0];
	m = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + record[i] > record[i] ? dp[i - 1] + record[i] : record[i];
		m = m > dp[i] ? m : dp[i];
	}
	scanf("%c", &c);
	while (c != '#'){
		s.push_back(c);
		scanf("%c", &c);
	}
	v = 0;
	while (v < m) {
		int i = v;
		while (i < s.size()) {
			cout << s[i];
			i += m;
		}
		v++;
	}
	system("pause");
	return 0;
}