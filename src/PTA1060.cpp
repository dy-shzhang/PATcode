#include<iostream>
#include<string>
using namespace std;

int main1060() {
	int n, flag = 0;
	string a, b;
	string ta, tb;
	cin >> n >> a >> b;

	int sa, sb;
	sa = 0;
	sb = 0;
	while (sa < a.size() && sa < b.size() && a[sa] == b[sa]) {
		if ((a[sa] == 0||a[sa]=='.') && flag==0)//起始位置的0
			sb++;
		else
			flag = 1;
		sa++;
	}
	if (sa-sb>= n) {
		cout << "YES " << "0.";
		int idx = sb;
		for (int i = sb; i < sb+n;) {
			if (a[idx] == '.') {
				idx++;
			}
			else {
				cout << a[idx];
				idx++;
				i++;
			}
		}
		cout << "*10^" << n - sb << endl;
	}
	else {
		cout << "NO" << " ";

	}


	system("pause");
	return 0;
}