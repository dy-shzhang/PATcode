#include<iostream>
#include<vector>

using namespace std;

auto funcprime(int i)->int(*)[10]{
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	return &a;
}
bool cmpprime(const int&a,const int&b) {
	return a < b;
}

int mainprime() {
	vector<int>grap[501];
	grap[1].push_back(1);
	int gp[501][501];
	cout << sizeof(grap) << endl;
	cout << sizeof(gp) << endl;
	system("pause");
	return 0;
}