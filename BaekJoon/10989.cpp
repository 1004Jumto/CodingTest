/*
	 [���� 10989] �� �����ϱ�
	  22-08-27 / c++

	  < �˰��� >

	  �迭�� ���� �ְ� sort�Լ��� ������ �� �ε����� ã���ش�


 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	//�ӵ��� ���� �������
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TESTCASE;
	cin >> TESTCASE;

	int arr[10001] = { 0 };

	for (int i = 0; i < TESTCASE; i++) {
		int num;
		cin >> num;
		arr[num]++;
	}

	for (int j = 0; j < 10001; j++) {
		for (int k = 0; k < arr[j]; k++) {
			cout << j << "\n";
		}
	}

	return 0;
}