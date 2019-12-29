#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#define INFI 0x7fffffff
using namespace  std;

//hash(i) = name%TSize.�����ͻ����
//���ԡ�ƽ��������
//loc=(hash(i)+j*j)%TSize;
//�ж�ĳ����n�Ƿ���hash���У�������hash(n)��Ӧ��λ��Ϊ��(û�����)ʱ������Ϊhash����û�д�n
//

bool isPrime1145(int n) {
	if (n == 2 || n == 3)
		return true;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}
int main1145() {
	int MS, N, M;
	int cont = 0;
	cin >> MS >> N >> M;
	while (isPrime1145(MS) == false)MS++;
	vector<int>myhash;
	myhash.resize(MS,INFI);
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		int j = 0;
		for (; j <=MS; j++) {
			int loc = (tmp%MS + j * j) % MS;
			if (myhash[loc] == INFI) {
				myhash[loc] = tmp;
				break;
			}
		}
		if (j == MS+1 ) {
			cout << tmp << " cannot be inserted." << endl;
		}
	}
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		for (int j=0; j <= MS; j++) {
			cont++;
			int loc = (tmp%MS + j * j) % MS;
			if (myhash[loc] == tmp || myhash[loc]==INFI) {//������ж�������������
				break;
			}
		}
	}
	printf("%0.1f\n", double(cont) / M);
	system("pause");
	return 0;
}