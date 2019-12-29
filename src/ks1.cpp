#include<iostream>
#include<string>
#include<vector>

using namespace std;
void dfsks(string s, int i, vector<char>record[10], string ans, bool& flag) {
	if (i >= s.size()) {
		if (flag == true) {
			cout << ",";
		}
		else
			flag = true;
		cout << ans;
	}
	else {
		string tmp = ans;
		for (int idx = 0; idx < record[s[i] - '0'].size(); idx++) {
			string tmp = ans;
			tmp.push_back(record[s[i] - '0'][idx]);
			dfsks(s, i + 1, record, tmp,flag);
		}
	}
}
int mainks() {
	vector<char>record[10];
	bool flag = false;
	string s;
	cin >> s;
	for (int i = 0; i < 18; i++) {
		record[i / 3 + 2].push_back('a' + i);
	}
	record[7].push_back('s');
	record[8].push_back('t'); 
	record[8].push_back('u');
	record[8].push_back('v');
	record[9].push_back('w');
	record[9].push_back('x');
	record[9].push_back('y');
	record[9].push_back('z');
	cout << "[";
	dfsks(s, 0, record, "", flag);
	cout << "]"<<endl;
	system("pause");
	return 0;
}