#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�ҵķ������������ѵ��ˣ�ͨ�����ѵ����ж����ˡ�
//�𰸵Ĳο���������ָ�����ˣ���ͨ�������ж����ѵ������ǲ��Ƕ��������������ҽ���һ�����ѵ���
//�ҵķ�����֪������������

/*
int checkState(vector<int>&talk, vector<int>&state, int& n, vector<int>&wlf) {
	int wolf = 0;
	for (int i = 1; i <= n; i++) {
		int idx = abs(talk[i]);
		int _state = talk[i] / idx;
		if (state[idx] != 0) {
			if (state[idx] != _state)
				return -1;//������
		}
		else {
			state[idx] = _state;
			if (_state < 0) {
				wlf[idx]=1;
				wolf++;
			}
		}
	}
	if (wolf < 2) {
		for(int i=1;i<=n;i++)
			if (state[i] == 0) {
				wolf++;
				wlf[i] = 1;
			}
	}
	return wolf;
}

int main() {
	int n;
	vector<int>state, talk;
	cin >> n;
	state.resize(n + 1, 0);
	talk.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> talk[i];
	}
	for (int i = 1; i <= n; i++) {
		talk[i] *= -1;
		for (int j = i + 1; j <= n; j++) {
			talk[j] *= -1;
			vector<int>wlf(n+1,0);
			int flag = checkState(talk, state, n, wlf);
			if (flag == 2) {
				if (state[i] * state[j] <0||(state[i] * state[j] == 0)&&(wlf[i]==1 || wlf[j]==1)) {
					int idx1 = 1;
					int idx2 = n;
					while (!wlf[idx1])idx1++;
					while (!wlf[idx2])idx2--;
					cout << idx1 << " " << idx2 << endl;
					system("pause");
					return 0;
				}
			}
			fill(state.begin(), state.end(), 0);
			talk[j] *= -1;
		}
		talk[i] *= -1;
	}
	cout << "No Solution" << endl;
	system("pause");
	return 0;
}*/

int main1148() {
	int n;
	cin >> n;
	vector<int>talk(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> talk[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			vector<int>isWolf(n + 1, 1);
			isWolf[i] = isWolf[j] = -1;//����ָ��i��jΪ����
			//�������ж�������
			vector<int>lie;
			for (int k = 1; k <= n; k++)
				if (talk[k] * isWolf[abs(talk[k])] < 0)lie.push_back(k);
			//talk[k] �ǵ�k����������״̬ �� isWolf[abs(talk[k])]�ǵ�k�����������˵�ʵ��״̬�������������<0�������Ϊ��k����˵�Ļ������⡣k��lier

			if (lie.size() == 2 && isWolf[lie[0]] + isWolf[lie[1]] == 0) {
				cout << i << " " << j << endl;
				system("pause");
				return 0;
			}
		}
	cout << "No Solution" << endl;
	system("pause");
	return 0;
}