#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

//对于string 字符串来说，printf 和 scanf 比 cout 和 cin 快多了
//对PTA PAT 来说，多用scanf 和 printf。大部分时间用在了输入输出流上面。
//字符串题，题目本身不困难，关键是细节很难，其中有个问题 为啥 int 变成 string 后答案就对了。。莫名其妙
//确定 答案的逻辑没有问题
//sort cmp函数不能是同一class的函数，理由不知。


using namespace std;


struct Record {
public:
	string rowdata;
	char level;
	string test_site;
	string rowtime;
	string year;
	string month;
	string day;
	string testee_numbner;
	int score;

public:
	Record(string s, int _score) :rowdata(s), score(_score) {

	};
	~Record() {};
	void init() {
		level = getLevel(rowdata);
		test_site = get_test_site(rowdata);
		rowtime = get_row_time(rowdata);
		year = get_year(rowtime);
		month = get_month(rowtime);
		day = get_day(rowtime);
		testee_numbner = get_testee_number(rowdata);

	};

private:
// 	int to_int(string s) {
// 		int ans = 0;
// 		for (int i = 0; i < s.size(); i++) {
// 			char tmp = s[i];
// 			ans = ans * 10 + int(tmp - '0');
// 		}
// 		return ans;
// 	};
	string to_int(string s) {
		return s;
	};
	char getLevel(string s) {
		return s[0];
	};
	string get_test_site(string s) {
		//string subs = s.substr(1, 3);
		return s.substr(1, 3);
		//return to_int(subs);
	};
	string get_row_time(string s) {
		return s.substr(4, 6);
	};
	string get_year(string s) {
		return s.substr(0, 2);
		//return to_int(s.substr(0, 2));
	};
	string get_month(string s) {
		return s.substr(2, 2);
		//return to_int(s.substr(2, 2));
	};
	string get_day(string s) {
		return s.substr(4, 2);
		//return to_int(s.substr(4, 2));
	};
	string get_testee_number(string s) {
		return s.substr(10, 3);
		//return to_int(s.substr(10, 3));
	};
};

bool clscmp(Record*& a, Record*& b) {
	if (a->score > b->score)
		return true;
	else if (a->score == b->score)
		return a->rowdata < b->rowdata;
	return false;
}
bool reccmp(pair<string, int>& a, pair<string, int>& b) {
	if (a.second > b.second)
		return true;
	else if (a.second == b.second) {
		return a.first < b.first;
	}
	return false;
}

class Solution1151 {
public:
	void print_cls_sort(vector<Record*>record, char cls) {
		sort(record.begin(), record.end(), clscmp);
		bool flag = false;
		for (int i = 0; i < record.size(); i++) {
			if (record[i]->level == cls) {
				//cout << record[i]->rowdata << " " << record[i]->score << endl;
				printf("%s %d\n", record[i]->rowdata.c_str(), record[i]->score);
				flag = true;
			}
		}
		if (flag == false)
			cout << "NA" << endl;
	};
	void print_site_score(vector<Record*>record, string site) {
		int num = 0;
		int sum = 0;
		for (int i = 0; i < record.size(); i++) {
			if (record[i]->test_site == site) {
				num++;
				sum += record[i]->score;
			}
		}
		if (num == 0)
			cout << "NA" << endl;
		else
			printf("%d %d\n", num, sum);
			//cout << num << " " << sum << endl;
	};
	void print_time_count(vector<Record*>record, string time) {
		//用 map 和vector<pair<int,int>> 进行map排序方便多了。
		map<string, int>tmprec;
		for (int i = 0; i < record.size(); i++) {
			if (record[i]->rowtime == time)
				tmprec[record[i]->test_site]++;
		}
		if (tmprec.size() == 0) {
			cout << "NA" << endl;
			return;
		}
		vector<pair<string, int>>tmp_vec(tmprec.begin(), tmprec.end());
		sort(tmp_vec.begin(), tmp_vec.end(), reccmp);
		for (int i = 0; i < tmp_vec.size(); i++) {
			printf("%s %d\n", tmp_vec[i].first.c_str(), tmp_vec[i].second);
			//cout << tmp_vec[i].first << " " << tmp_vec[i].second << endl;
		}
	};
};
int main1153() {
	int number, quired;

	cin >> number >> quired;

	vector<Record*>record;
	Solution1151 s;
	for (int i = 0; i < number; i++) {
		string tmp;
		char ctmp[18];
		int score;
		scanf("%s %d",ctmp,&score);
		tmp = ctmp;
		Record* rectmp = new Record(tmp, score);
		rectmp->init();
		record.push_back(rectmp);
	}
	for (int i = 0; i < quired; i++) {
		int proType;
		string proId;
		char cls;
		cin >> proType;
		if (proType == 1) {
			cin >> cls;
		}
		else
			cin >> proId;

		cout << "Case " << i + 1 << ": " << proType << " ";
		if (proType == 1)
			cout << cls << endl;
		else
			cout << proId << endl;
		switch (proType) {
		case 1:s.print_cls_sort(record, cls); break;
		case 2:s.print_site_score(record, proId); break;
		case 3:s.print_time_count(record, proId); break;
		}
	}
	system("pause");
	return 0;
}