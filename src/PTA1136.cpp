#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
//stoi �� atos ���� �������ķ�Χ�����ƣ�ֻ����int��Χ��
//���ڱ�����Ϊ������1000λ��Զ����int��Χ
//���Բ���ֱ����stoi �� atos ����ת��string ��int

string sadd1136(string s, string c) {
	int flag = 0;
	int i = s.size()-1, j = c.size()-1;
	string ans;
	while (i >=0 && j>= 0) {
		int tmp = (s[i] - '0') + (c[i] - '0') + flag;
		if (tmp > 9) {
			flag = 1;
			tmp -= 10;
		}
		else
			flag = 0;
		ans.push_back(tmp + '0');
		i--; j--;
	}
	while (i >= 0 && flag==1) {
		int tmp = s[i]-'0' + flag;
		if (tmp > 9) {
			tmp -= 9;
			flag = 1;
		}
		else {
			flag = 0;
		}
		ans.push_back(tmp + '0');
		i--;
	}
	while (j >= 0 && flag == 1) {
		int tmp = c[j] - '0' + flag;
		if (tmp > 9) {
			tmp -= 9;
			flag = 1;
		}
		else {
			flag = 0;
		}
		ans.push_back(tmp + '0');
		j--;
	}
	if (flag == 1)
		ans.push_back('1');
	reverse(ans.begin(), ans.end());
	return ans;
}

int main1136() {
	int idx = 0;
	string s, ss;
	cin >> s;
	while (idx < 10) {
		ss = s;
		reverse(ss.begin(), ss.end());
		if (s == ss)
			break;
		auto tmp = sadd1136(s,ss);
		cout << s << " + " << ss << " = " << tmp << endl;
		s = tmp;
		idx++;
	}
	if (idx >= 10)
		cout << "Not found in 10 iterations." << endl;
	else
		cout << s << " is a palindromic number." << endl;
	system("pause");
	return 0;
}