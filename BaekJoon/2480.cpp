/*
	 [���� 2480] �ֻ�������
	  22-08-26 / c++

	  < ���� >

	  ���� ���� 3���� ������ 10,000��+(���� ��)��1,000���� ����� �ް� �ȴ�.
	  ���� ���� 2���� ������ ��쿡�� 1,000��+(���� ��)��100���� ����� �ް� �ȴ�.
	  ��� �ٸ� ���� ������ ��쿡�� (�� �� ���� ū ��)��100���� ����� �ް� �ȴ�.

	  3�� �ֻ����� ���� ���� �־��� ��, ����� ����ϴ� ���α׷��� �ۼ� �Ͻÿ�.

	  < �˰��� >

	  �ϴ� �ֻ��� ���� ������ ���� ������ ����
	  ���ǹ��� ���� ��� ���� ���� ���� ������ ���

 */

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	int FIRST_NUM, SECOND_NUM, THIRD_NUM;

	cin >> FIRST_NUM >> SECOND_NUM >> THIRD_NUM;

	int retMoney;

	// ��� ���� ��
	if (FIRST_NUM == SECOND_NUM && SECOND_NUM == THIRD_NUM) {
		retMoney = 10000 + FIRST_NUM * 1000;
	}

	// ��� �ٸ� ��
	else if (FIRST_NUM != SECOND_NUM && SECOND_NUM != THIRD_NUM && FIRST_NUM != THIRD_NUM) {
		//���� ū �� ���ϱ�
		int max;
		if (FIRST_NUM > SECOND_NUM && FIRST_NUM > THIRD_NUM) {
			max = FIRST_NUM;
		}

		else if (SECOND_NUM > FIRST_NUM && SECOND_NUM > THIRD_NUM) {
			max = SECOND_NUM;
		}
		else if (THIRD_NUM > SECOND_NUM && THIRD_NUM > FIRST_NUM) {
			max = THIRD_NUM;
		}

		retMoney = max * 100;
	}

	//���� ���� 2��
	else {
		if (FIRST_NUM == SECOND_NUM) {
			retMoney = 1000 + FIRST_NUM * 100;
		}
		else if (FIRST_NUM == THIRD_NUM) {
			retMoney = 1000 + FIRST_NUM * 100;
		}
		else {
			retMoney = 1000 + SECOND_NUM * 100;
		}
	}

	cout << retMoney;
}