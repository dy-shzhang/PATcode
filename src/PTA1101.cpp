#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp1101(int&a, int&b) {
	return a < b;
}

//快排的要求，对任意的pivot排完后实际是有序的。
int main1101() {
	int n;
	int condition = 0;
	vector<int>ans;
	vector<int>re;
	vector<int>record;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		record.push_back(tmp);
		re.push_back(tmp);
	}

	sort(re.begin(), re.end(), cmp1101);
	condition = record[0];
	for (int i = 0; i < record.size(); i++) {
		if (record[i] >= condition) {
			condition = record[i];
			if (record[i] == re[i]) {
				ans.push_back(re[i]);
			}
		}
		
	}
	cout << ans.size()<<endl;
	if (ans.size() != 0) {
		cout << ans[0];
		for (int i = 1; i < ans.size(); i++)
			cout << " " << ans[i];
	}
	cout << endl;
	system("pause");
	return 0;
}