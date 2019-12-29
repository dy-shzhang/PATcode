#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

//dfs法内存溢出
//数学方法
using namespace std;

// void dfs(int idx,int level,int n, double &longest, double tmp, vector<int>& record, map<int, int>know) {
// 	if (level == n-1) {
// 		tmp += record[idx];
// 		tmp /= 2.0;
// 		longest = longest > tmp ? longest : tmp;
// 		return;
// 	}
// 	else {
// 		tmp += record[idx];
// 		tmp /= 2.0;
// 		know[idx] = 1;
// 		for (int i = 0; i < n; i++) {
// 			if (know[i] != 1) {
// 				dfs(i,level+1, n, longest, tmp, record, know);
// 			}
// 		}
// 	}
// }

int main1125() {
	int n;
	double longest = 0;
	vector<int>record;
	map<int, int>know;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >>tmp;
		record.push_back(tmp);
	}
	sort(record.begin(), record.end());
	for (auto i : record) {
		if (longest == 0)
			longest = i;
		longest = (longest + i) / 2.0;
	}
	cout << int(longest) << endl;
	system("pause");
	return 0;
}