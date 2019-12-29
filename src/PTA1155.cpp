#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
void twopart1155(int i, int n, vector<int>tree, vector<int>tmp, vector<vector<int>>& ans) {
	if (i > n) {
		return;
	}
	else {
		tmp.push_back(tree[i]);
		if (2 * i > n && 2 * i + 1 > n)
			ans.push_back(tmp);
		else {
			twopart1155(2 * i + 1, n, tree, tmp, ans);
			twopart1155(2 * i, n, tree, tmp, ans);
		}

	}
}

int checklist1155(vector<int>tmp) {//判断一段数组是否单调
	// return 1 max, return 0 min, return -1 not
	int tmp_size = tmp.size();
	int flag_sum = 0;
	vector<int>flag(tmp_size);
	if (tmp[0] - tmp[tmp_size - 1] > 0)flag[0] = 1;
	else flag[0] = -1;
	for (int i = 1; i < tmp_size; i++) {
		if (tmp[i - 1] - tmp[i] > 0) {
			flag[i] = 1;
		}
		else if (tmp[i - 1] - tmp[i] < 0) {
			flag[i] = -1;
		}
		else {
			flag[i] = flag[0];
		}
	}
	for (int i = 1; i < tmp_size; i++) {
		flag_sum += flag[i];
	}
	if (flag_sum == tmp_size - 1)
		return 1;
	else if (flag_sum == -tmp_size + 1)
		return -1;
	else
		return 0;
}
int main1155() {
	int number, flag_check, flag_tmp;
	cin >> number;
	vector<int>tmp;
	vector<int>tree(number + 1);
	vector<vector<int>>ans;
	for (int i = 1; i <= number; i++) {
		cin >> tree[i];
	}
	twopart1155(1, number, tree, tmp, ans);

	for (int i = 0; i < ans.size(); i += 1) {
		cout << ans[i][0];
		for (int j = 1; j < ans[i].size(); j++) {
			cout << ' ' << ans[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < ans.size(); i += 1) {
		flag_check = checklist1155(ans[i]);
		if (i == 0) {
			flag_tmp = flag_check;
		}
		if (flag_check == 0 || flag_check != flag_tmp) {
			cout << "Not Heap" << endl;
			system("pause");
			return 0;
		}
	}
	if (flag_check == 1)
		cout << "Max Heap" << endl;
	else
		cout << "Min Heap" << endl;
	system("pause");
	return 0;
}