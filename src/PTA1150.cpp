#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define INFI 0X7FFFFFFF
//看清楚题目要求
//方法耗时太多


using namespace std;
class Solution1150 {
public:
	int verter;
	int edge;
	int gradis[201][201];
	int known[201];
public:
	Solution1150(int _ver, int _edge) :verter(_ver), edge(_edge) {
		fill(gradis[0], gradis[0] + 201 * 201, INFI);
		fill(known, known + 201, 0);
	};
	int getDistance(vector<int>path) {
		fill(known, known + verter + 1, 0);
		//known[path[0]] = true;
		int dist = 0;
		for (int i = 1; i < path.size(); i++) {
			if (gradis[path[i - 1]][path[i]] != INFI) {
				dist += gradis[path[i - 1]][path[i]];
				known[path[i]] ++;
			}
			else {
				return INFI;
			}
		}
		return dist;
	};
	int isCycle() {
		int flag = 0;
		for (int i = 1; i <= verter; i++) {
			if (known[i] == 0)
				return -1;
			if (known[i] >= 2)
				flag=1;
		}
		if (flag == 1)
			return 1;
		return 0;
	};
};

int main1150() {
	int N, M, K;
	int dis, shortest, idx;
	int flag = 0;
	vector<pair<int, int>>ans;
	cin >> N >> M;
	Solution1150 gra(N, M);
	for (int i = 0; i < gra.edge; i++) {
		int c1, c2, dis;
		cin >> c1 >> c2 >> dis;
		gra.gradis[c1][c2] = dis;
		gra.gradis[c2][c1] = dis;
	}
	cin >> K;
	shortest = INFI;
	for (int i = 1; i <= K; i++) {
		int nb;
		vector<int>path;
		cin >> nb;
		for (int j = 0; j < nb; j++) {
			int tmp;
			cin >> tmp;
			path.push_back(tmp);
		}
		dis = gra.getDistance(path);
		flag = gra.isCycle();
		ans.push_back(pair<int, int>(dis, flag));
		if(flag>=0)
			shortest = shortest < dis ? shortest : dis;
	}
	for (int i = 0; i < K; i++) {
		cout << "Path " << i+1 << ": ";
		if (ans[i].first == INFI)
			cout << "NA ";
		else
			cout << ans[i].first << " ";
		if (ans[i].first == shortest) {
			idx = i+1;
		}

		if (ans[i].second == 0)
			cout << "(TS simple cycle)"<<endl;
		else if (ans[i].second == -1)
			cout << "(Not a TS cycle)"<<endl;
		else if(ans[i].second == 1)
			cout << "(TS cycle)" << endl;
	}
	cout << "Shortest Dist(" << idx << ")" << " = " << shortest << endl;
	system("pause");
	return 0;
}