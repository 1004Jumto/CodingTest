/*
	 [���� 2908] ���
	  22-08-27 / c++

	  < �˰��� >

	  ���ڸ� �������� 0���Ե����� ���� ���� �Է¹����Ƿ� �ڿ������� �����ش�

 */

#include <iostream>
#include <string>

using namespace std;

int main(void) {

	string a, b;
	cin >> a >> b;

	for (int i = 2; i >= 0; i--) {
		int a_tmp = a[i] - '0';
		int b_tmp = b[i] - '0';

		if (a_tmp > b_tmp) {
			cout << a[2] << a[1] << a[0];
			return 0;
		}
		else if (a_tmp < b_tmp) {
			cout << b[2] << b[1] << b[0];
			return 0;
		}
		else
			continue;
	}

	return 0;
}