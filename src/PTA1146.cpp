#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;
class Node1146 {
public:
	set<int>comeIn;
	int number;
	Node1146() {
		number = 0;
	}
}vertices1146[1001];
bool known1146[1001];
int main1146() {
	int N, M, tmp, Np;
	bool flag=true;
	vector<int>check;
	vector<int>ans;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int tp1, tp2;
		cin >> tp1 >> tp2;
		vertices1146[tp2].comeIn.insert(tp1);
		vertices1146[tp2].number++;
	}
	cin >> Np;
	for (int i = 0; i < Np; i++) {
		check.clear();
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			check.push_back(tmp);
		}
		fill(known1146, known1146 + N + 1, false);
		flag = true;
		for (int j = 0; j < N; j++) {
			if (vertices1146[check[j]].number == 0)
				known1146[check[j]] = true;
			else {
				for (auto k = vertices1146[check[j]].comeIn.begin(); k != vertices1146[check[j]].comeIn.end(); k++) {
					if (known1146[*k] == false) {
						ans.push_back(i);
						flag = false;
						break;
					}
				}
				if (flag == false)
					break;
				known1146[check[j]] = true;
			}
		}
	}
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++) {
		cout << " " << ans[i];
	}
	cout << endl;
	system("pause");
	return 0;
}
