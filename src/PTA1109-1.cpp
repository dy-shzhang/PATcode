#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp1109_1(pair<string, int>&a, pair<string, int>&b) {
	if (a.second > b.second)
		return true;
	else if (a.second == b.second)
		return a.first < b.first;
	return false;
}

int main1109_1() {

	int n, k,r;
	cin >> n >> k;
	r = n / k;
	vector<pair<string, int>>record;
	vector<string>final(n,"");
	for (int i = 0; i < n; i++) {
		string name;
		int height;
		cin >> name >> height;
		record.push_back(pair<string, int>(name, height));
	}
	sort(record.begin(), record.end(), cmp1109_1);
	int count = 0;
	for (int i = k-1; i >=0; i--) {
		int length = r;
		if (i == k - 1) {
			length += n - k*r;
		}
	
		for (int j = 0; j <= length / 2; j++) {
			if (j == 0) {
				final[i*r + length / 2 ] = record[count++].first;
			}
			else {
				if (length / 2 - j >= 0)
					final[i*r + length / 2 - j] = record[count++].first;
				if(length / 2  + j<length)
					final[i*r + length / 2 +j] = record[count++].first;
			}
		}
	}
	for (int i = k-1; i >=0; i--) {
		int length = r;
		if (i == k - 1) {
			length += n - k * r;
		}
		cout << final[i*r];
		for (int j = 1; j < length; j++)
			cout << " " << final[i*r + j];
		cout << endl;
	}
	system("pause");
	return 0;
}