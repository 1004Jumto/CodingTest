/*
	 [���� 1009] �л�ó��
	  22-08-26 / c++

	  < ���� >
	  
	  ����̴� �ֽ� ��ǻ�� 10�븦 ������ �ִ�. 
	  ��� �� ����̴� ���� �����͸� ó���ؾ� �� ���� ���ܼ� �� ��ǻ�Ϳ� 1������ 10�������� ��ȣ�� �ο��ϰ�, 
	  10���� ��ǻ�Ͱ� ������ ���� ������� �����͵��� ó���ϱ�� �Ͽ���.

	  1�� �����ʹ� 1�� ��ǻ��, 2�� �����ʹ� 2�� ��ǻ��, 3�� �����ʹ� 3�� ��ǻ��, ... ,
	  10�� �����ʹ� 10�� ��ǻ��, 11�� �����ʹ� 1�� ��ǻ��, 12�� �����ʹ� 2�� ��ǻ��, ...
	  
	  �� �������� ������ �׻� a^b���� ���·� �־�����. 
	  ����̴� ���� ������ �����Ͱ� ó���� ��ǻ���� ��ȣ�� �ñ�������. �̸� �������ִ� ���α׷��� �ۼ��϶�.

	  < �˰����� >

	  1. ������ ������ �� ������ �ڸ��� ��ǻ�� ��ȣ�� �����ϹǷ� �� ������ �ڸ��� �����ش� --> 99�� 999999��ó�� ���� �������� �߻��ϹǷ� �Ұ���
		 (������ ������ �����ڴ� �������� �����ϴ�)

	  2. �����϶�, �� �ڸ� ���� ��Ģ�� ������ �̿��Ѵ�. 
		1 -> 1 1 1 ...
		2 -> 2 4 8 6 2 ...
		3 -> 3 9 7 1 3 ...
		4 -> 4 6 4 ...
		5 -> 5 5 5 ...
		6 -> 6 6 6 ...
		7 -> 7 9 3 1 7 ...
		8 -> 8 4 2 6 8 ...
		9 -> 9 1 9 ...
		10 -> 0 0 0 ...

 */

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;


int main(void) {
	int TESTCASE, a, b;
	cin >> TESTCASE;

	int* res = new int[TESTCASE];

	for (int i = 0; i < TESTCASE; i++) {
		cin >> a >> b;

		int a_last = a % 10;

		if (a_last == 1 || a_last == 5 || a_last == 6 ) {
			res[i] = a_last;
		}

		else if (a_last == 0) {
			res[i] = 10;
		}

		else if (a_last == 4  || a_last == 9) {
			if (b % 2 == 0) {
				res[i] = (a_last * a_last) % 10;
			}
			else {
				res[i] = a_last;
			}
		}
		else {
			int b_remain = b % 4;
			if (b_remain == 0) {
				b_remain = 4;
			}

			int tmp = pow(a_last, b_remain);
			res[i] = tmp % 10;
		}
	}

	for (int i = 0; i < TESTCASE; i++) {
		cout << res[i] << "\n";
	}

	return 0;
}