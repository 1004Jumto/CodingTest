/*
	 [���� 1427] ��Ʈ�λ��̵�
	  22-08-27 / c++

	  < �˰��� >

		���ڸ� �Է¹ް�
		�ڸ� ���� �ϳ��� �迭�� �����Ѵ�
		�迭 �������ְ�
		�������� ������ ���ش�


 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int iNum[10];
	int idx = 0;

	//�迭 �ʱ�ȭ
	memset(iNum, -1, 10 * 4);

	cin >> N;

	while (N != 0) {
		iNum[idx++] = N % 10;
		N /= 10;
	}

	sort(iNum, iNum + 10);

	for (int k = 9; k >= 0; k--) {
		if (iNum[k] == -1) {
			break;
		}
		cout << iNum[k];
	}

	return 0;
}
