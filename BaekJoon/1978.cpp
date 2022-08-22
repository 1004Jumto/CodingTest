/*
	 [���� 1978] �Ҽ�ã�� 
	  22-08-03 / c++

	  < ���� >

	  �־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	  < �˰��� >

	  �Ҽ� �Ǻ��ϱ�
	  1. ���� �Է¹ް� N,
	  2. N���� �ݺ����� ������ N�� ��������.
	  3. �������� 0�� ������ ���ڰ� ������ �Ҽ��� �ƴϹǷ� �н��Ѵ�
	  4. �̶�, 1�� 2�� for���� ������ �ʰ� �̸� ���� �������ش�
 */

#include<iostream>

using namespace std;

bool isPrime(int N) {
	if (N == 1) {
		return false;
	}
	if (N == 2) {
		return true;
	}
	for (int k = 2; k < N; k++) {
		if (N % k == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int N; // ���� ����
	cin >> N;

	int cnt = 0;
	int *arr = new int[N];		//���� �Է¹ޱ�
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		if (isPrime(arr[i])) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}