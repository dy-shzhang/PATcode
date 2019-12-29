#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main1089() {
	int n;
	bool flag = false;
	vector<int>raw, part;
	vector<int>tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tp;
		cin >> tp;
		raw.push_back(tp);
	}

	for (int i = 0; i < n; i++) {
		int tp;
		cin >> tp;
		part.push_back(tp);
	}
	//sort(tmp.begin(), tmp.end());
	int u = 1;
	while (u < part.size() && part[u - 1] < part[u])u++;
	for (int i = u; i < part.size(); i++) {
		if (part[i] != raw[i]) {
			flag = true;
			break;
		}
	}
	if (flag == true) {
		cout << "Merge Sort" << endl;
		int si = u;
		int i = -2 * si;
		int j = 0;
		while (1) {
			i += 2 * si;
			j = i + si;
			if (i >= part.size() || j >= part.size()) {
				break;
			}
			int mx = j + si > part.size() ? part.size() : j + si;
			int idxl = i, idxr = j;
			while (idxl < j &&idxr < mx) {
				if (part[idxl] <= part[idxr]) {
					tmp.push_back(part[idxl++]);
				}
				else
					tmp.push_back(part[idxr++]);
			}
			while (idxl < j)tmp.push_back(part[idxl++]);;
			while (idxr < mx)tmp.push_back(part[idxr++]);
		}
		for (i = tmp.size(); i < part.size(); i++) {
			tmp.push_back(part[i]);
		}
		for (int j = 0; j < tmp.size(); j++) {
			cout << tmp[j];
			if (j != tmp.size()-1) {
				cout << " ";
			}
		}
		cout << endl;
	}
	else {
		cout << "Insertion Sort" << endl;
		int i = part[u];
		int j = u - 1;
		while (j >= 0 && part[j] > i) {
			part[j + 1] = part[j];
			j--;
		}
		part[j+1] = i;
		for (int j = 0; j < part.size(); j++) {
			cout << part[j];
			if (j != part.size()-1) {
				cout << " ";
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}