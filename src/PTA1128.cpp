#include<iostream>
#include<vector>

using namespace std;

int main1128() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		bool flag = true;
		cin >> k;
		vector<int>record(k + 1, 0);
		for (int j = 1; j <= k; j++) {
			cin >> record[j];
		}
		for (int j = 1; j <= k; j++) {
			for (int l = j + 1; l <= k; l++) {
				if (record[j] == record[l] || (abs(l - j) == abs(record[j] - record[l]))) {
					flag = false;
					break;
				}
			}
			if (flag == false)
				break;
		}
		cout << (flag == true ? "YES" : "NO") << endl;
	}
	system("pause");
	return 0;
}