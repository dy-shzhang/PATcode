#include<iostream>
#include<vector>
#include<map>

using namespace std;

// ����ȷ���������г�ʱ������

//dalao �������жϹ������ȵİ취(�����BST)(a>=U && a<=v) || (a<=U && a>=V)
// ��Ҫmap<int,bool> ��¼���ֹ���Ԫ�أ����ж�UV�Ƿ������ϡ�

//ԭʼ���У��ҵ��뷨���Ƚ�������������Ԫ�ء����·��

//�µĴ��У���������-ʡʱ��.����BST���ص㣬�жϸ��ڵ�
//��ǰ����ж��Ƿ��Ǹ��ڵ㣬���ܴӺ���ǰ�жϣ��Ӻ���ǰ��������
//�����ǣ���һ�����԰�����ͨ��
//�������ˣ�֮ǰû�п��ǵ�uvָ��ͬһ���ڵ�ʱ��Ӧ����ô�죬��Ŀ��ֻ˵bst��distinct��û˵���ܲ�ѯͬһ���ڵ�


/**
class Node1143 {
public:
	int value;
	Node1143* left;
	Node1143* right;
	Node1143(int _val) {
		value = _val;
		left = NULL;
		right = NULL;
	}
};

Node1143* cst1143(int t, Node1143* head) {
	if (head == NULL) {
		Node1143* tmp = new Node1143(t);
		return tmp;
	}
	else {
		if (t < head->value)
			head->left = cst1143(t, head->left);
		else
			head->right = cst1143(t, head->right);
		return head;

	}
}
void getpath1143(Node1143* head, int val, vector<int>&path) {
	if (head == NULL) {
		path.clear();
	}
	else if (head->value == val) {
		path.push_back(val);
	}
	else {
		path.push_back(head->value);
		if (val < head->value)
			getpath1143(head->left, val, path);
		else
			getpath1143(head->right, val, path);
	}
}

int main1143() {
	int n, m;
	cin >> n >> m;
	Node1143* Nhead = NULL;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		Nhead = cst1143(tmp, Nhead);
	}
	for (int i = 0; i < n; i++) {
		int t1, t2;
		vector<int>p1;
		vector<int>p2;
		cin >> t1 >> t2;
		getpath1143(Nhead, t1, p1);
		getpath1143(Nhead, t2, p2);
		if (p1.empty() && p2.empty()) {
			cout << "ERROR: " << t1 << " and " << t2 << " are not found." << endl;
		}
		else if (p1.empty()) {
			cout << "ERROR: " << t1 << " is not found." << endl;
		}
		else if (p2.empty()) {
			cout << "ERROR: " << t2 << " is not found." << endl;
		}
		else {
			int j = 0;
			int jmin = p1.size()<p2.size()?p1.size():p2.size();
			while (j < jmin && p1[j] == p2[j])j++;
			if (j == jmin) {
				cout << (p1.size() < p2.size() ? t1 : t2) << " is an ancestor of " << (p1.size() < p2.size() ? t2 : t1) << "." << endl;
			}
			else {
				cout << "LCA of " << t1 << " and " << t2 << " is " << p1[j - 1] << "." << endl;
			}
		}
	}
	system("pause");
	return 0;
}*/

int main1143() {
	int n, k;
	cin >> n >> k;
	map<int, int>toIndex;
	vector<int>record(k+1, 0);
	for (int i = 1; i <= k; i++) {//��1��ʼ��map���ж�0��״̬
		cin >> record[i];
		toIndex[record[i]] = i;
	}
	while (n--) {
		int v1, v2, v3;
		int flag = 0;
		cin >> v1 >> v2;
		int i = toIndex[v1];
		int j = toIndex[v2];
		if (i == 0 && j == 0) {
			cout << "ERROR: " << v1 << " and " << v2 << " are not found." << endl;
			continue;
		}
		else if (i == 0) {
			cout << "ERROR: " << v1 << " is not found." << endl;
			continue;
		}
		else if (j == 0) {
			cout << "ERROR: " << v2 << " is not found." << endl;
			continue;
		}
		else {
			if (i > j) {
				swap(i, j);
				flag = 1;
			}
			else if (i == j) {//���۵�u v��ͬ��ʱ��u��vָ��ͬһ���ڵ㣩��������ĸ��ڵ�
				v3 = i - 1;
				while (v3 >= 0) {
					if (record[v3] > record[i])break;
					v3--;
				}
				if(v3<0)//ͷ
					cout << record[i] << " is an ancestor of " << record[j] << "." << endl;
				else
					cout << "LCA of " << record[j] << " and " << record[i] << " is " << record[v3] << "." << endl;
				system("pause");
				return 0;
			}
			v3 = 0;
			while (v3 <i) {
				if ((record[v3] - record[i])*(record[v3] - record[j]) < 0)
					break;
				v3++;
			}
			if (v3 >=i)
				cout << record[i] << " is an ancestor of " << record[j] << "." << endl;
			else
				if (flag)
					cout << "LCA of " << record[j] << " and " << record[i] << " is " << record[v3] << "." << endl;
				else
					cout << "LCA of " << record[i] << " and " << record[j] << " is " << record[v3] << "." << endl;
		}
	}
	system("pause");
	return 0;
}