/*
* [���� 1182] �κ� ������ ��
* N���� ������ �̷���� ������ ���� ��, ũ�Ⱑ ����� �κм��� �߿��� �� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

* [�˰���]
* ����Ž�� �˰��� : ������ ��� ����� ���� ���� üũ�� ������ ã�� ���
* �׸���� �ڲ� �򰥸� ���� �ִµ�, �׸���� �� ���� �������� �����ظ� ���� ������ �ش信 �̸��� ����̰�,
* ���� Ž���� ���� ��� �ϳ��ϳ� �� �������� ���
*
*
*/

#include<iostream>	
#include<algorithm>
#include<vector>
#include<string>	

using namespace std;

int main(void) {
	int N, S;
	vector<int> num;
	int i, j, sum;
	int cnt = 0;

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		num.push_back(tmp);
	}

	for (i = 1; i < (1 << num.size()); i++) {
		sum = 0;
		for (j = 0; j < num.size(); j++) {
			if (i & (1 << j)) sum += num[j];
		}
		if (sum == S) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}