#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

//������������ظ���������vector+����İ취
//Ҫ�ж�ȱʧ��������set����Ϊ�޷�ֱ�ӷ���Ԫ��
//map����ֱ�ӷ��ʣ�ֻҪ��������0���ǳ��֣��ҵ�һ������==0 ��λ��
//�߽�������������������ʱ���������⣬��n+1λ���ǵ�һ��ȱʧ��

int main1144() {
	map<int,int>num;
	int n, np;
	cin >> n;
	np = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > 0) {
			num[tmp]++;;
			np++;
		}

	}
	int i = 1;
	for (; i <= np; i++) {
		if (num[i] ==0) {
			break;
		}
	}
	cout << i << endl;
	system("pause");
	return 0;
}