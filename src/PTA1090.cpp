#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
//Ò»¸ö³¬Ê±
int main1090() {
	int n;
	double p, r;
	int maxl = 0;
	int count = 0;

	cin >> n >> p >> r;
	vector<int>record(n, -1);
	vector<int>check(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> record[i];
	}
	for (int i = 0; i < n; i++) {
		int idx = i;
		int cnt = 0;
		while (idx != -1) {
			if (check[idx] != -1) {
				cnt += check[idx];
				break;
			}
			idx = record[idx];
			cnt++;
		}
		check[i] = cnt;
		if (cnt > maxl) {
			maxl = cnt;
			count = 1;
		}
		else if(cnt == maxl) {
			count++;
		}
	}
	printf("%.2f %d\n",p* pow(1.+r/100., maxl-1), count);
	system("pause");
	return 0;

}