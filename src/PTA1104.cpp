#include<iostream>
using namespace std;
//用float不行，用double就能通过了
//yyyyyyyy？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
int main1104() {
	int n;
	double sum = 0.;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double tmp;
		cin >> tmp;
		sum += (n - i)*(i + 1)*tmp;
	}

	printf("%.2f\n", sum);
	system("pause");
	return 0;
}