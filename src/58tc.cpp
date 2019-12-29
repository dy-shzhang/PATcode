#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>

using namespace std;

int main58tc() {
	int i;
	char tmp;
	map<int,int>record;
	int num = 0;
	scanf("%d%c",&i,&tmp);
	record[i]++;
	while (tmp != '\n') {
		//cin >> i >> tmp;
		scanf("%d%c", &i, &tmp);
		record[i]++;
		if (record[i] == i + 1) {
			record[i] = 0;
			num += i + 1;
		}
	}
	for (auto j : record) {
		if (j.second != 0)
			num += (j.first + 1);
	}
	cout << num << endl;
	system("pause");
	return 0;
}