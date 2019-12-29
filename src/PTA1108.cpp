#include<iostream>
#include<vector>
#include<string>
#include<math.h>


using namespace std;


bool isLegal1108(string s) {
	int si = s.size();
	int gender = 1;
	int point = 0;
	int afterPoint = 0;
	int idx = 0;
	if (s[0] == '-' || s[0] == '+') {
		gender = -1;
		idx = 1;
	}
	for (; idx < si; idx++) {
		if (s[idx] == '.') {
			point++;
		}
		else if (s[idx] >= '0' && s[idx] <= '9') {
			if (point)
				afterPoint++;
		}
		else
			return false;
	}
	if (point >= 2 || afterPoint > 2)
		return false;
	return true;
}

double getNum1108(string s) {
	int gender = 1;
	int idx = 0;
	double ans = 0;
	int flag = 0;
	if (s[0] == '-') {
		gender = -1;
		idx = 1;
	}
	for (; idx < s.size(); idx++) {
		if (s[idx] == '.') {
			flag = idx;
			continue;
		}
		else if (flag) {
			ans += (s[idx] - '0') / (pow(10, idx - flag));
		}
		else
			ans = ans * 10 + (s[idx] - '0');
	}
	return ans * gender;
}

int main1108() {
	int n;
	string tmp;
	int cnt = 0;
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (isLegal1108(tmp) == true) {
			double sub = getNum1108(tmp);
			if (abs(sub) > 1000)
				cout << "ERROR: " << tmp << " is not a legal number" << endl;
			else {
				sum += sub;
				cnt++;
			}
		}
		else {
			cout << "ERROR: " << tmp << " is not a legal number" << endl;
		}
	}
	if (cnt > 1)
		printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
	else if (cnt == 1)
		printf("The average of %d number is %.2f\n", cnt, sum / cnt);
	else
		printf("The average of %d numbers is Undefined\n", cnt);
	system("pause");
	return 0;
}