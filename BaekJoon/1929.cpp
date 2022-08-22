/*
	 [���� 1929] �Ҽ����ϱ�
	  22-08-04 / c++

	  < ���� >

	  M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	  < �˰��� >

	  �����佺�׼����� ü �˰���
	  
 */

#include<iostream>
#include<algorithm>

using namespace std;

bool isPrime(int N) {
	if (N == 1) {
		return false;
	}
	if (N == 2 || N == 3) {
		return true;
	}
	if (N % 2 == 0) {
		return false;
	}
	for (int k = 2; k <= N / 2; k++) {
		if (N % k == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int M, N;
	cin >> M >> N;

	for (int i = M; M <= N; M++) {
		if (isPrime(M))
		{
			cout << M << "\n";
		}
	}

}