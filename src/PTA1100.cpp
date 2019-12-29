#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;


int main1100() {
	int k;
	cin >> k;
	getchar();
	vector<string>raw0{ "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	vector<string>raw1{ "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	map<string, int>rawint0,rawint1;
	for (int i = 0; i < 13; i++) {
		rawint0[raw0[i]] = i;
		rawint1[raw1[i]] = i;
	}
	for (int i = 0; i < k; i++) {
		string tmp;
		getline(cin,tmp);
		if (tmp[0] >= '0'&&tmp[0] <= '9') {
			int altp = 0;
			int num = atoi(tmp.c_str());
			string ans="";
			if (num / 13 != 0) {
				ans = ans + raw1[num / 13];
				ans = ans;
			}
			altp = num % 13;
			if(altp ==num )
				ans = ans +raw0[altp];
			else if (altp != num) {
				if(altp!=0)
					ans = ans +" "+ raw0[altp];
			}
			cout << ans << endl;
		}
		else {
			if (tmp.size() == 3)
				cout << (rawint0[tmp]<rawint1[tmp]*13? rawint1[tmp]*13: rawint0[tmp]) << endl;
			else {
				cout << rawint1[tmp.substr(0, 3)] * 13 + rawint0[tmp.substr(4, tmp.size()-4)] << endl;
			}
		}
	}
	system("pause");
	return 0;

}