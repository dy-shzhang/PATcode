#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool cmp1098(int&a,int&b) {
	return a < b;
}
int main1098() {
	int n,u,k;
	cin >> n;
	vector<int>raw;
	vector<int>partly;
	for (int i = 0; i < n; i++) {
		int tp;
		cin >> tp;
		raw.push_back(tp);
	}
	for (int i = 0; i < n; i++) {
		int tp;
		cin >> tp;
		partly.push_back(tp);
	}
	u =1;
	while (u < n && partly[u - 1] <= partly[u])u++;
	k = u;
	while (k < n &&partly[k] == raw[k])k++;
	if (k == n) {
		cout << "Insertion Sort" << endl;
		int j = u-1;
		int tmp = partly[u];
		while (j >= 0 && partly[j] > tmp) {
			partly[j+1] = partly[j];
			j--;
		}
		partly[j+1] = tmp;
	}
	else{
		cout << "Heap Sort" << endl;
		sort(raw.begin(), raw.end(), cmp1098);
		u = n - 1;
		while (raw[u] == partly[u])u--;
		int j = 0;
		for (; j < u; j++)
			if (partly[j] == raw[u])
				break;
		int tmp;
		tmp = partly[u];
		partly[u] = partly[j];
		partly[j] = tmp;
		int i = 0;
		while (2*i+1 <= u) {
			int a = 2 * i + 1;
			if (2 * i + 2 < u && partly[a] < partly[a + 1])
				a += 1;
			if (partly[a] > partly[i]) {
				int tmp = partly[i];
				partly[i] = partly[a];
				partly[a] = tmp;
				i = a;
			}
			else
				break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != 0)
			cout << " ";
		cout << partly[i];
	}
	cout << endl;
	system("pause");
	return 0;
}