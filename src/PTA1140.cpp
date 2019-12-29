#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main1140() {
	string s;
	int num;
	cin >> s >> num;
	for (int i = 1; i < num; i++) {
		string sn;
		char it = s[0];
		int num = 0;
		for (int j = 0; j < s.size(); j++) {
			if (it == s[j]) {
				num++;
			}
			else {
				sn.push_back(it);
				sn.push_back(char(num + '0'));
				it = s[j];
				num = 1;
			}
		}
		sn.push_back(it);
		sn.push_back(char(num + '0'));
		s = sn;
		sn.clear();
	}
	for (int i = 0; i < s.size(); i++)
		cout << s[i];
	cout << endl;
	system("pause");
	return 0;
}