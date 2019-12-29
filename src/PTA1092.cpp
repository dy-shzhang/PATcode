#include<iostream>
#include<string>
#include<map>
using namespace std;

int main1092() {
	map<char, int>owner, eva;
	bool flag = true;
	int count = 0;
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		owner[s1[i]]++;
	}
	for (int i = 0; i < s2.size(); i++) {
		eva[s2[i]]++;
	}

	for (auto i = owner.begin(); i != owner.end(); ++i) {
		int tmp = i->second - eva[i->first];
		if (tmp < 0) {
			if (flag == true)
				count = 0;
			flag = false;
		}
		if (flag == false && tmp < 0) {
			count -= tmp;
		}
		else if (flag == true && tmp > 0)
			count += tmp;
		eva[i->first] = 0;
	}
	int tp = 0;
	auto i = eva.begin();
	while (i != eva.end()) { tp += i->second; ++i; }
	if (tp > 0) {
		if (flag == true) {
			count = tp;
			flag = false;
		}
		else
			count += tp;
	}
	cout << (flag == true ? "Yes " : "No ") << count << endl;
	system("pause");
	return 0;
}