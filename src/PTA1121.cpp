#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

//1输出要求，对位数的要求只能通过printf指定

bool cmp1121(const int&a, const int&b) {
	return a < b;
}

int main1121() {
	int ncp,n;
	map<int, int>rela,tofind;
	vector<int>ans;
	cin >> ncp;
	for (int i = 0; i < ncp; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		rela[t1+1] = t2+1;
		rela[t2+1] = t1+1;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t1;
		cin >> t1;
		if (rela[t1+1] == 0)
			ans.push_back(t1+1);
		else
			tofind[t1+1] = 1;
	}
	for (auto i : tofind) {
		if (tofind[rela[i.first]] == 0)
			ans.push_back(i.first);
	}
	sort(ans.begin(), ans.end(), cmp1121);
	cout << ans.size() << endl;
	if (ans.size()>0) {
		printf("%05d",ans[0]-1);
		for (int i = 1; i < ans.size(); i++)
			printf(" %05d",ans[i]-1);
		cout << endl;
	}
	
	system("pause");
	return 0;
}