#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>

using namespace std;
/*
//ʱ�临�Ӷ�̫�ߣ���ʱ
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
//��һ�����԰�����ʱ
//���õ�˫��αhash��loc��¼i��Ӧ��λ�ã�record��¼��i�źͳ��ֵĴ�����ͨ��record�����õ�ð���໥����
//���ǲ��뷨����

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

// struct cmp {//����
// 
// 	bool operator() (const pair<int, int>&a, const pair<int, int>&b) {
// 		if (a.second > b.second)
// 			return true;
// 		else if (a.second == b.second)
// 			return a.first < b.first;
// 		return false;
// 	}
// };


//�·���1�����ȶ��к�����<�ķ�����ȥ����
//�����ȶ��е�����£� ����<ֻ���Զ���ṹ������
//ʱ�临�Ӷȸ�����
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

//set���Զ�����ģ�����ͨ������������ķ������ı�set����Ĺ���
//set �ṩfind ����������������ѯĳ���ض�Ԫ��
//����set�ڵ�Ԫ�ز��ܱ��ı䣬ֻ��ɾ�������²�����ֵ
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
	bok[tmp]++;//��¼ÿ��Ԫ�س��ֵĴ�������map��ѯ�����ĸ�Ϊ����
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