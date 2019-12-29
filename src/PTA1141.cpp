#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

//有一个测试案例不过
// 暂时想不出原因
//map可以当hash表用，方便查找但是不能排序
//map 转 vector 后可以排序，但是不方便查找
//
using namespace std;

/*
string getlow1142(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}
	return s;
}
bool cmp1142(pair<string, vector<int>>&a, pair<string, vector<int>>&b) {
	if (a.second[1] > b.second[1])
		return true;
	else if (a.second[1] == b.second[1]) {
		if (a.second[0] < b.second[0])
			return true;
		else if (a.second[0] == b.second[0]) {
			if (a.first < b.first)
				return true;
		}
	}
	return false;
}

int main1141() {
	map<string, vector<int>>allscore;
	int nm;
	cin >> nm;
	for (int i = 0; i < nm; i++) {
		string id, school;
		int score;
		cin >> id >> score >> school;
		school = getlow1142(school);
		if (allscore[school].empty()) {
			allscore[school].push_back(0);
			allscore[school].push_back(0);
		}
		allscore[school][0]++;
		switch (id[0]) {
		case 'A':allscore[school][1]+=score; break;
		case 'B':allscore[school][1] += score/1.5; break;
		case 'T':allscore[school][1] += score*1.5; break;
		}
	}
	vector<pair<string, vector<int>>>aldata(allscore.begin(), allscore.end());//map 转 vector 为了排序
	sort(aldata.begin(), aldata.end(), cmp1142);
	cout << aldata.size() << endl;
	int rank = 1;
	for (int i = 1; i <= aldata.size(); i++) {
		cout << rank<<" ";
		cout << aldata[i - 1].first << " " << aldata[i - 1].second[1] << " " << aldata[i - 1].second[0] << endl;
		if (i != aldata.size()) {
			if (aldata[i - 1].second[1] != aldata[i].second[1])
				rank = i + 1;
		}
	}
	system("pause");
	return 0;
}*/

struct node1141 {
	string name;
	double point;
	int num;
	node1141() {
		name = "";
		point = 0.0;
		num = 0;
	};
	bool operator<(const node1141&a) {
		if (a.point < point)
			return true;
		else if (a.point == point) {
			if (a.num > num)
				return true;
			else
				return a.name > name;
		}
		return false;
	}
};

void getLow1141(string&s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A'&&s[i] <= 'Z')
			s[i] += ('a' - 'A');
	}
}
int main1141() {
	map<string, node1141>record;
	vector<node1141>rnk;
	int rk = 0;
	int curScore = 0;
	int n;
	string id, na;
	double score;
	cin >> n;
	while (n--) {
		cin >> id >> score >> na;
		getLow1141(na);
		record[na].name = na;
		switch (id[0]) {
		case 'A':score = score; break;
		case 'B':score /= 1.5; break;
		case 'T':score *= 1.5; break;
		default:break;
		}
		record[na].point += score;
		record[na].num += 1;
	}
	for (auto i : record)
		rnk.push_back(i.second);
	sort(rnk.begin(), rnk.end());
	cout << rnk.size()<<endl;
	rk = 0;
	curScore = int(rnk[0].point);
	for (int i = 0; i < rnk.size();i++) {
		if (int(rnk[i].point) != curScore) {
			rk = i;
			curScore = int(rnk[i].point);
		}
		cout << rk + 1 << " " << rnk[i].name << " ";
		printf("%d", int(rnk[i].point));
		cout << " " << rnk[i].num << endl;
	}
	system("pause");
	return 0;
}