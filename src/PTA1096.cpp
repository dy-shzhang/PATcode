#include<iostream>
#include<vector>
using namespace std;
//一个案例超时
//yyyyy
int main1096() {
	int n;
	int mx = 0;
	vector<int>tmp, ans;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int tp = n;
		int j = i;
		tmp.clear();
		while (tp%j == 0) {
			tp /= j;
			tmp.push_back(j);
			j++;
		}
		if (mx < tmp.size())
			mx = tmp.size();
		if (ans.size() == 0 || ans.size() <= tmp.size()) {
			if (ans.size() == tmp.size()) {
				if (ans > tmp)
					ans = tmp;
			}
			else
				ans = tmp;
		}

	}

	cout << mx << endl;
	for (int i = 0; i < mx; i++) {
		cout << ans[i];
		if (i != mx - 1)
			cout << "*";
	}
	cout << endl;
	system("pause");
	return 0;
}