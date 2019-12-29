#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int mainyfd2() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		vector<int>record(m);
		for (int j = 0; j < m; j++) {
			cin >> record[j];
		}
		sort(record.begin(), record.end());
		int num = 0;
		for (int k = 0; k < m - 2; k++) {
			num += record[k] * (m - k-1)*(m - k - 2) / 2;
		}
		cout << num<<endl;
	}
	return 0;
}