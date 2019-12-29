#include<iostream>
#include<limits>
using namespace std;
void dfswy1(int a, int b, int p, int q,int& cnt,int ti) {
	if (a >= b) {
		cnt = cnt > ti ? ti : cnt;
	}
	else {
		if (ti > cnt)
			return;
		dfswy1(a + p, b, p, q, cnt, ti + 1);
		if(a+p<b)
			dfswy1(a, b, p*q, q, cnt, ti + 1);
	}
}
int mainwy1() {
	int a, b, p, q;
	int cnt = INT_MAX;
	cin >> a >> b >> p >> q;
	dfswy1(a, b, p, q, cnt, 0);
	cout << cnt << endl;
	system("pause");
	return 0;
}