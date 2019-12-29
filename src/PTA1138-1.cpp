#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main1138_1() {
	int n,l,r,mid;
	int idx = -1;
	cin >> n;
	vector<int>pre(n);
	vector<int>inodr(n);
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> inodr[i];
	}
	l = 0;
	r = n;
	while (l!=r-1) {
		mid = l;
		idx++;
		while (mid < r && inodr[mid] != pre[idx])mid++;
		if (mid > l) {
			r = mid;
		}
		else if(mid ==l) {
			l = mid + 1;
		}
	}
	cout << inodr[l] << endl;
	system("pause");
	return 0;
}