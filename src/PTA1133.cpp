
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;
//没必要按照题目中描述的过程一步一步实现
//只要最终结果满足就行

class Node1133 {
public:
	int val;
	string adrs;
	string next;
	Node1133(int _val, string _adrs, string _n) {

		val = _val;
		next = _n;
		adrs = _adrs;
	}
};
/*
int main() {
	string str;
	int n, k;
	map<string, Node*>record;
	vector<Node*>rec;
	cin >> str >> n >> k;
	for (int i = 0; i < n; i++) {
		int _val;
		string adrs, nxt;
		cin >> adrs >> _val >> nxt;
		Node* tmp = new Node(_val, adrs, nxt);
		record[adrs] = tmp;
	}
	while (str != "-1") {
		rec.push_back(record[str]);
		str = record[str]->next;
	}
	for (int i = 1; i < rec.size(); i++) {
		int j = i;
		if (rec[j]->val < 0) {
			while (j > 0 && rec[j - 1]->val >= 0) {
				swap(rec[j - 1], rec[j]);
				j--;
			}
		}
		else if (rec[j]->val <= k) {
			while (j > 0 && rec[j - 1]->val >= k) {
				swap(rec[j - 1], rec[j]);
				j--;
			}
			if (j == i)
				i++;
		}
	}
	for (int i = 0; i < rec.size(); i++) {
		cout << rec[i]->adrs << " " << rec[i]->val << " ";
		cout << (i == rec.size() - 1 ? "-1" : rec[i + 1]->adrs) << endl;
	}
	system("pause");
	return 0;
}
*/
int main1133() {
	string str;
	int n, k;
	map<string, Node1133*>record;
	vector<vector<Node1133*>>rec;
	rec.resize(3);
	cin >> str >> n >> k;
	for (int i = 0; i < n; i++) {
		int _val;
		string adrs, nxt;
		cin >> adrs >> _val >> nxt;
		Node1133* tmp = new Node1133(_val, adrs, nxt);
		record[adrs] = tmp;
	}
	while (str != "-1") {
		if (record[str]->val < 0) {
			rec[0].push_back(record[str]);
		}
		else if (record[str]->val <= k) {
			rec[1].push_back(record[str]);
		}
		else
			rec[2].push_back(record[str]);
		str = record[str]->next;
	}
	for (int i = 1; i < 3; i++) {
		rec[0].insert(rec[0].end(), rec[i].begin(), rec[i].end());
	}
	for (int i = 0; i < rec[0].size(); i++) {
		cout << rec[0][i]->adrs << " " << rec[0][i]->val << " ";
		if (i != rec[0].size()-1) {
			cout << rec[0][i + 1]->adrs << endl;
		}
	}
	cout << "-1" << endl;
	system("pause");
	return 0;
}