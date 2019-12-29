#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

//考虑输入会有重复，不能用vector+排序的办法
//要判断缺失，不能用set，因为无法直接访问元素
//map可以直接访问，只要次数大于0就是出现，找第一个次数==0 的位置
//边界条件，当是连续数字时，按照题意，第n+1位即是第一个缺失的

int main1144() {
	map<int,int>num;
	int n, np;
	cin >> n;
	np = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > 0) {
			num[tmp]++;;
			np++;
		}

	}
	int i = 1;
	for (; i <= np; i++) {
		if (num[i] ==0) {
			break;
		}
	}
	cout << i << endl;
	system("pause");
	return 0;
}