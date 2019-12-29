#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>

using namespace std;
struct nodetry {
	int a;
	int b;
	nodetry(int _a, int _b) :a(_a), b(_b) {

	};
	bool operator <(const nodetry&an)const {
		if (an.b < b)
			return true;
		else if (an.b == b) {
			return an.a > a;
		}
		return false;
	}
};

// bool operator <(const nodetry&a, const nodetry&b) {
// 	return a.a < b.a;
// }

int maintry() {
	vector<vector<int>>record(3, vector<int>(4, 0));
	system("pause");
	return 0;
}