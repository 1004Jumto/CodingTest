/*
	 [���� 10872] ���丮��
	  22-08-04 / c++

	  < ���� >

	  M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	  < �˰��� >

		����Լ�

 */

#include<iostream>

using namespace std;

int Factorial(int N) {
	if (N == 1) {
		return 1;
	}
	return N * Factorial(N - 1);
}

int main(void) {
	int NUM;
	cin >> NUM;

	if (NUM == 0) {
		cout << 1;
		return 0;
	}

	int ans = Factorial(NUM);

	cout << ans;
	return 0;

}