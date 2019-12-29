#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int vedge1142[201][201];
int has1142[201];
int main1142() {
	fill(vedge1142[0], vedge1142[0] + 201 * 201, 0);
	int nv, ne, nm, nn;
	cin >> nv >> ne;
	for (int i = 0; i < ne; i++) {
		int tp1, tp2;
		cin >> tp1 >> tp2;
		vedge1142[tp1][tp2] = 1;
		vedge1142[tp2][tp1] = 1;
	}
	cin >> nm;
	for (int i = 0; i < nm; i++) {
		vector<int>pa;
		pa.clear();
		fill(has1142, has1142 + 201, 0);
		cin >> nn;
		for (int j = 0; j < nn; j++) {
			int tp;
			cin >> tp;
			pa.push_back(tp);
			has1142[tp] = 1;
		}
		int ni = 0;
		for (; ni < nn; ni++) {
			int nk = ni + 1;
			for (; nk < nn; nk++) {
				if (vedge1142[pa[ni]][pa[nk]] == 0)
					break;
			}
			if (nk != nn)
				break;
		}
		if (ni != nn) {
			cout << "Not a Clique" << endl;

		}
		else {
			int j = 1;
			for (; j <= nv; j++) {
				if (has1142[j] == 1)
					continue;
				int k = 0;
				for (; k < nn; k++) {
					if (vedge1142[j][pa[k]] == 0)
						break;
				}
				if(k==nn){
					cout << "Not Maximal" << endl;
					break;
				}
			}
			if (j == nv + 1)
				cout << "Yes" << endl;
		}
	}
	system("pause");
	return 0;
}