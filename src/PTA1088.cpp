#include<iostream>
#include<string>
using namespace std;

int mxcommon1088(long a, long b) {
	if (b == 0)
		return a;
	else
		return mxcommon1088(b, a%b);
}

void simpfy1088(long n, long m) {
	if (n < 0 && m < 0) {
		n = -n;
		m = -m;
	}	
	if (m == 0) {
		cout << "Inf";
		return;
	}

	long abn = abs(n);
	long b = 0;
	if (abn > m)
		b = mxcommon1088(abn, m);
	else
		b = mxcommon1088(m, abn);
	n /= b;
	m /= b;
	if (n%m == 0) {
		if (n < 0)
			cout << "(" << n / m << ")";
		else if (n > 0)
			cout << n / m;
		else if (n == 0)
			cout << "0";
	}
	else {
		if (n < 0) {
			if (abs(n) > m)
				cout << "(" << n / m << " " << abs(n - n / m * m) << "/" << m << ")";
			else
				cout << "(" << n - n / m * m << "/" << m << ")";
		}
		else if (n > 0) {
			if (n > m)
				cout << n / m << " " << n - n / m * m << "/" << m;
			else
				cout << n - n / m * m << "/" << m;
		}
		else if (n == 0) {
			cout << "0";
		}
	}
}

int main1088() {
	string raw1, raw2;
	cin >> raw1 >> raw2;
	long up1, up2, dn1, dn2;
	long f1, f2;

	f1 = raw1.find_first_of('/');
	f2 = raw2.find_first_of('/');

	up1 = atoi(raw1.substr(0, f1).c_str());
	dn1 = atoi(raw1.substr(f1 + 1, raw1.size() - f1).c_str());

	up2 = atoi(raw2.substr(0, f2).c_str());
	dn2 = atoi(raw2.substr(f2 + 1, raw2.size() - f2).c_str());


	simpfy1088(up1, dn1); cout << " + "; simpfy1088(up2, dn2); cout << " = "; simpfy1088((up1 * dn2 + up2 * dn1), (dn1*dn2)); cout << endl;
	simpfy1088(up1, dn1); cout << " - "; simpfy1088(up2, dn2); cout << " = "; simpfy1088((up1 * dn2 - up2 * dn1), (dn1*dn2)); cout << endl;
	simpfy1088(up1, dn1); cout << " * "; simpfy1088(up2, dn2); cout << " = "; simpfy1088((up1 * up2), (dn1*dn2)); cout << endl;
	if (up2 < 0) {
		simpfy1088(up1, dn1); cout << " / "; simpfy1088(up2, dn2); cout << " = "; simpfy1088(-1 * (up1 * dn2), abs(dn1*up2)); cout << endl;
	}
	else {
		simpfy1088(up1, dn1); cout << " / "; simpfy1088(up2, dn2); cout << " = "; simpfy1088((up1 * dn2),(dn1*up2)); cout << endl;
	}


	system("pause");
	return 0;
}