#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
//看清楚题目的要求
//有的题目把0放在首位
//有的题目不能放在首位

using namespace std;
bool isPrime1145(long long s) {
	if (s == 3 || s == 2)
		return true;
	for (long long i = 2; i*i < s; i++) {
		if (s % i == 0)
			return false;
	}
	return true;
}

int main1152() {
	int L, K;
	bool flag = false;
	long long sum = 0;
	long long cl;
	char tmp;
	cin >> L >> K;
	if (L < K) {
		cout << 404 << endl;
		system("pause");
		return 0;
	}
	getchar();
	cl = pow(10, K - 1);
	scanf("%c", &tmp);
	for (int i = 0; i < K - 1; i++) {
		sum = sum * 10 + int(tmp - '0');
		scanf("%c", &tmp);
	}
	while (tmp != '\n') {
		sum = sum % cl;
		sum = sum * 10 + int(tmp - '0');
		scanf("%c", &tmp);

		flag = isPrime1145(sum);
		if (flag == true) {
			vector<int>itmp;
			for (int i = 0; i < K; i++) {
				itmp.push_back(sum % 10);
				sum /= 10;
			}
			for (auto i = itmp.rbegin(); i != itmp.rend(); i++) {
				cout << *i;
			}
			cout << endl;
			system("pause");
			return 0;
		}
	}
	cout << 404 << endl;
	system("pause");
	return 0;
}