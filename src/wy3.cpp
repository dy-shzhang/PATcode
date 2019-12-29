#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int mainwy4() {
	int n, m, T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		int tmp;
		vector<int>record(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> record[i];
			cin >> tmp;
		}
		for (int i = 0; i < n; i++) {
			m += (record[i] - i);
			if (m < 0)
				break;
		}
		if (m < 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	system("pause");
	return 0;
}