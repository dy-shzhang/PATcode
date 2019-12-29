#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int main1112() {
	int k;
	map<char, int> check;
	string record;
	vector<char>ers;
	cin >> k;
	cin >> record;
	map<char,int>ans;
	for (int i = 0; i < record.size(); i++) {
		check[record[i]]++;
	}
	for (int i = 0;i<record.size();i++){
		if (check[record[i]]%k != 0 || ans[record[i]]==1)
			continue;
		string tmp;
		int j = 0;
		while (j++ < k)tmp.push_back(record[i]);
		int indx = 0;
		int loc = record.find_first_of(tmp);
		while (loc != string::npos) {
			indx++;
			loc = record.find_first_of(tmp, loc + k);
		}
		if (indx*k == check[record[i]]) {
			ans[record[i]] = 1;
			ers.push_back(record[i]);
		}
	}

	for (int i = 0; i < ers.size(); i++) {
		cout << ers[i];
	}
	cout << endl;
	for (int i = 0; i < record.size(); ) {
		if (ans[record[i]] == 1) {
			cout << record[i];
			i += k;
		}
		else {
			cout << record[i];
			i += 1;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}