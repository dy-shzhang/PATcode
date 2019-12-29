#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//读题不仔细，要求看错了之前用了DFS
//用map空间复杂度比数组小
//时间复杂度较高
//测试案例有两个不通过，问题不明

//新方法，只记录同性别朋友和全部关系网
//从同性朋友中找有联系的朋友

// 主要是三个问题 1： -0000 和 0000 用int的时候都是 0 ，无法区分男女，
//所以先用 string 接受输入，判断完了性别再转为int型用

//2： 当输入的AB两个人直接认识的时候，也是不能直接联系。
//3： 当id时0023 时候，int型记录的时23，所以输出 的时候要用 %04d

/*
bool cmp1139(pair<int, int>&a, pair<int, int>&b) {
	if (a.first < b.first)
		return true;
	else if (a.first == b.first) {
		if (a.second < b.second)
			return true;
	}
	return false;
}

int main1139() {
	map<string, vector<string>>record;
	map<pair<string, string>, int>con;
	int n, m, nm;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1.size() == s2.size()) {
			record[s1].push_back(s2);
			record[s2].push_back(s1);
		}

		con[pair<string, string>(s1, s2)] = 1;
		con[pair<string, string>(s2, s1)] = 1;
	}
	cin >> nm;
	for (int i = 0; i < nm; i++) {
		string s, e;
		cin >> s >> e;
		vector<pair<int, int>>tmp;
		for (auto its = record[s].begin(); its != record[s].end(); its++) {
			if ((*its)== e)
				continue;
			for (auto ite = record[e].begin(); ite != record[e].end(); ite++) {
				if ((*ite)== s || *ite == *its)
					continue;
				if (con[pair<string, string>(*its, *ite)] == 1)
					tmp.push_back(pair<int, int>(abs(stoi(*its)), abs(stoi(*ite))));
			}
		}
		sort(tmp.begin(), tmp.end(), cmp1139);
		cout << tmp.size() << endl;
		for (int j = 0; j < tmp.size(); j++) {
			cout << tmp[j].first << " " << tmp[j].second << endl;
		}
	}
	system("pause");
	return 0;
}
*/
bool cmp1139(pair<int, int>&a, pair<int, int>&b) {
	
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
		return a.second < b.second;
	return false;
}

int main1139() {
	int n, k, check;
	cin >> n >> k;
	map<int, int>relationShip;
	map<int, vector<int>>record;
	for (int i = 0; i < k; i++) {
		int p1, p2;
		string ps1, ps2;
		cin >> ps1 >> ps2;
		p1 = stoi(ps1);
		p2 = stoi(ps2);
		if (ps1.size() == ps2.size()) {//只记录同性别朋友,主要是为了区分-0000 0000 的区别
			record[p1].push_back(p2);
			record[p2].push_back(p1);
		}
		relationShip[abs(p1) * 10000 + abs(p2)] = relationShip[abs(p2) * 10000 + abs(p1)] = 1;
	}
	cin >> check;
	while (check--) {
		int p1, p2;
		vector<pair<int, int>>ans;
		cin >> p1 >> p2;
		for (int j : record[p1])
			for (int i : record[p2]) {
				if (relationShip[abs(i) * 10000 + abs(j)] && p2!=j && p1!=i)ans.push_back(pair<int, int>(abs(j), abs(i)));
			}
		sort(ans.begin(), ans.end(), cmp1139);
		cout << ans.size() << endl;
		for (auto i : ans) {
			printf("%04d %04d\n", i.first, i.second);//当用int储存name时，name=0000的时候输出会是0，所以要用%04d
		}
		ans.clear();
	}
	system("pause");
	return 0;
}