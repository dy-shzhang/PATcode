#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>

using namespace std;
/*
//时间复杂度太高，超时
bool cmp(vector<int>&a, vector<int>&b) {
	if (a[1] > b[1])
		return true;
	else if (a[1] == b[1]) {
		return a[0] < b[1];
	}
	return false;
}

int main() {
	int n, k;

	cin >> n >> k;
	vector<vector<int>>record(n + 1);
	vector<vector<int>>tmp;
	for (int i = 0; i <= n; i++) {
		record[i].resize(2, 0);
	}
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		if (i != 1) {
			cout << t << ": ";
			tmp = record;
			sort(tmp.begin(), tmp.end(), cmp);
			for (int j = 0; j < k; j++) {
				if (j == 0)
					cout << tmp[j][0];
				else
					if (tmp[j][1] != 0)
						cout << " " << tmp[j][0];
					else
						break;
			}
			cout << endl;
		}
		record[t][0] = t;
		record[t][1]++;
	}
	system("pause");
	return 0;
}*/
//有一个测试案例超时
//采用的双向伪hash，loc记录i对应的位置，record记录第i号和出现的次数，通过record排序，用的冒泡相互交换
//考虑插入法试试

/*
void my_insert1129(int i, vector<vector<int>>&record, vector<int>&loc) {
	int l = loc[i];
	if (l == -1) {
		int si = record.size();
		vector<int>tmp(2, 1);
		tmp[0] = i;
		record.push_back(tmp);
		loc[i] = si;
		l = si;
	}
	else {
		record[l][1]++;
	}
// 	while (l > 0 && (record[l][1] > record[l - 1][1] || (record[l][1] == record[l - 1][1] && record[l][0] < record[l - 1][0]))) {
// 		loc[i] = l - 1;
// 		loc[record[l - 1][0]] = l;
// 		swap(record[l], record[l - 1]);
// 		l--;
// 	}
	int idx = l - 1;
	auto tmp = record[l];
	while (idx >=0 && (tmp[1] > record[idx][1] || (tmp[1] == record[idx][1] && tmp[0] < record[idx][0]))) {
		record[idx + 1] = record[idx];
		loc[record[idx + 1][0]] = idx + 1;
		idx--;
	}
	record[idx + 1] = tmp;
	loc[tmp[0]] = idx + 1;
}

int main1129() {
	int n, k;
	cin >> n >> k;
	vector<int>loc(n, -1);
	vector<vector<int>>record;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (i != 0) {
			cout << t << ": ";
			for (int j = 0; j < k && j < record.size(); j++) {
				if (j == 0)
					cout << record[j][0] + 1;
				else
					cout << " " << record[j][0] + 1;
			}
			cout << endl;
		}
		my_insert1129(t - 1, record, loc);
	}
	system("pause");
	return 0;
}*/

// struct cmp {//不行
// 
// 	bool operator() (const pair<int, int>&a, const pair<int, int>&b) {
// 		if (a.second > b.second)
// 			return true;
// 		else if (a.second == b.second)
// 			return a.first < b.first;
// 		return false;
// 	}
// };


//新方法1用优先队列和重载<的方法，去排序
//再优先队列的情况下， 重载<只对自定义结构体有用
//时间复杂度更高了
/*
struct node1129 {
	int name;
	int number;
	node1129(int _name, int _number) :name(_name), number(_number) {};
};

bool operator < (const node1129 &a, const node1129&b) {
	if (a.number < b.number)
		return true;
	else if (a.number == b.number)
		return a.name > b.name;
	return false;
}

int main1129() {
	int n, k, tmp;
	cin >> n >> k;
	map<int, int>record;
	n--;
	cin >> tmp;
	record[tmp]++;
	while (n--) {
		int num = k;
		cin >> tmp;
		cout << tmp << ":";
		priority_queue<node1129>rnk;
		for (auto i : record) {
			rnk.emplace(i.first, i.second);
		}

		while (!rnk.empty() && num) {
			auto first = rnk.top();
			rnk.pop();
			cout << " " << first.name;
			num--;
		}
		cout << endl;
		record[tmp]++;

	}
	system("pause");
	return 0;
}*/

//set是自动排序的，可以通过重载运算符的方法，改变set排序的规则
//set 提供find 函数，能以用来查询某个特定元素
//插入set内的元素不能被改变，只能删除后重新插入新值
struct node1129 {
	int name;
	int number;
public:
	node1129(int _name, int _number) :name(_name), number(_number) {};
	bool operator < (const node1129&a)const {
		if (a.number <number)
			return true;
		else if (a.number == number)
			return a.name > name;
		return false;
	}
};
int main1129() {
	int n, k,tmp;
	cin >> n >> k;
	set<node1129>record;
	map<int, int>bok;
	cin >> tmp;
	record.emplace(tmp, 1);
	bok[tmp]++;//记录每个元素出现的次数，用map查询，更改更为方便
	n--;
	while (n) {
		cin >> tmp;
		cout << tmp << ":";
		int num = k;
		for (auto i = record.begin(); i != record.end() && num; i++) {
			cout << " " << (*i).name;
			num--;
		}
		cout << endl;
		auto del = record.find(node1129{ tmp,bok[tmp]});
		bok[tmp]++;
		if(del!=record.end())record.erase(del);
		record.emplace(tmp, bok[tmp]);
		n--;
	}
	system("pause");
	return 0;
}