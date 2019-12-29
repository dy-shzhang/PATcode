#include<iostream>
#include<map>
#include<vector>
#include<string>
//简单题，但是要注意各个输入的意义，注意和题目中的对应好

using namespace std;

int main1124() {
	int m, n, s;
	int idx = 0;
	cin >> m >> n >> s;
	map<string, int>winned;
	vector<string>record(m+1,"");
	for (int i = 1; i<=m; i++) {
		cin >> record[i];
	}
	idx = s;
	while (idx <= m) {
		if (winned[record[idx]] == 0) {
			cout << record[idx] << endl;
			winned[record[idx]] = 1;
		}
		else {
			while (idx<=m &&winned[record[idx]])idx++;
			if (idx > m)
				break;
			cout << record[idx] << endl;
			winned[record[idx]] = 1;
		}
		idx += n;
	}
	if (m < s)
		cout << "Keep going..." << endl;
	system("pause");
	return 0;
}