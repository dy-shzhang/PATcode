#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Node1095 {
	string plate;
	string state;
	int time;
	Node1095(string _p, int _t, string _s) {
		plate = _p;
		state = _s;
		time = _t;
	}
};

bool cmp11095(Node1095&a, Node1095&b) {
	if (a.plate > b.plate)
		return true;
	else if (a.plate == b.plate) {
		return a.time < b.time;
	}
	return false;
}

bool cmp21095(Node1095&a, Node1095&b) {
	return a.time < b.time;
}

int main1095() {
	int n, k;

	string idx;
	cin >> n >> k;
	getchar();
	vector<Node1095>record;
	vector<string>ans;
	int longtime = 0;
	for (int i = 0; i < n; i++) {
		string p,t,s;
		cin >> p >> t >> s;
		int _t = 0;
		_t = atoi(t.substr(0, 2).c_str()) * 3600 + atoi(t.substr(3, 2).c_str()) * 60 + atoi(t.substr(6, 2).c_str());
		//cout << t.substr(0, 2) << " " << t.substr(3, 2) << " " << t.substr(6, 2) << endl;
		Node1095 tmp(p, _t, s);
		record.push_back(tmp);
	}
	sort(record.begin(), record.end(), cmp11095);
	idx = record[0].plate;
	for (auto i = record.begin(); i < record.end() - 1;) {
		if ((i+1)->plate != idx) {
			idx = (i+1)->plate;
			++i;
			continue;
		}
		else {
			if (i->state == (i + 1)->state) {
				if (i->state == "in") {
					i = record.erase(i);
				}
				else {
					i = record.erase((i + 1));
				}
			}
			else
				++i;
		}
	}
	idx = "";
	int timetmp = 0;
	for (int i = 0; i < record.size(); ) {

		if (idx != record[i].plate) {
			timetmp = 0;
		}
		timetmp += record[i + 1].time - record[i].time;

		if (timetmp > longtime) {
			longtime = timetmp;
			ans.clear();
			ans.push_back(record[i].plate);
		}
		else if (timetmp == longtime) {
			ans.push_back(record[i].plate);
		}
		
		idx = record[i].plate;
		i += 2;
	}
	getchar();
	sort(record.begin(), record.end(), cmp21095);
	int incnt = 0;
	int otcnt = 0;
	int it = 0;
	for (int i = 0; i < k; i++) {
		string t;
		cin >> t;
		int _t = 0;
		_t = atoi(t.substr(0, 2).c_str()) * 3600 + atoi(t.substr(3, 2).c_str()) * 60 + atoi(t.substr(6, 2).c_str());
		for (; it < record.size(); it++) {
			if (record[it].time <= _t) {
				if (record[it].state == "in") {
					incnt++;
				}
				else
					otcnt++;
			}
			else
				break;
		}
		cout << incnt - otcnt << endl;
	}
	sort(ans.begin(), ans.end());
	cout << ans[0];
	string check = ans[0];
	for (int i = 1; i < ans.size(); i++) {
		if (ans[i] != check) {
			check = ans[i];
			cout << " " << ans[i];
		}
		else
			continue;
	}
	printf(" %02d:%02d:%02d\n", longtime / 3600, (longtime % 3600) / 60, (longtime % 3600) % 60);
	system("pause");
	return 0;
}