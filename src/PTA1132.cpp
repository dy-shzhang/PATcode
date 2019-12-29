#include<iostream>
#include<string>

using namespace std;

int main1132() {
	int n;
	int si;
	string a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		bool flag = false;
		si = a.size();
		b = a.substr(0, si / 2);
		c = a.substr(si / 2, si / 2);
		if (stoi(b)!=0 &&stoi(a) % stoi(b) == 0) {
			int tmp = stoi(a) / stoi(b);
			if (stoi(c)!=0 && tmp %stoi(c) == 0)
				flag=true;
		}
		cout << (flag == true ? "Yes" : "No") << endl;
	}
	system("pause");
	return 0;
}