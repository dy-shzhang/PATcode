#include<iostream>
#include<map>
#include<set>
using namespace std;
//看清示例表达的意思
int getSum1120(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main1120() {
	int n, k;
	map<int, int>record;
	set<int>rnk;
	cin >> n;
	while (n--) {
		cin >> k;
		record[getSum1120(k)]++;
	}
	for (auto i : record) {
		if (i.second > 0)
			rnk.insert(i.first);
	}
	cout << rnk.size() << endl;
	if (rnk.size()) {
		cout << (*rnk.begin());
		rnk.erase(rnk.begin());
		while (!rnk.empty()) {
			cout << " " << *rnk.begin();
			rnk.erase(rnk.begin());
		}
		cout << endl;
	}
	system("pause");
	return 0;
}