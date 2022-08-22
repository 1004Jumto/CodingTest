/*
	 [���� 2581] �Ҽ�
	  22-08-03 / c++

	  < ���� >

	  �ڿ��� M�� N�� �־��� �� M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ��� 
	  �̵� �Ҽ��� �հ� �ּڰ��� ã�� ���α׷��� �ۼ��Ͻÿ�.

	  < �˰��� >

	  �ռ� ���� �Ҽ� �Ǻ� �Լ��� ����Ѵ�
	  �Ҽ��� ��쿡 sum�� ���ϰ�, �迭�� �־��ش�
	  sort�Լ��� ����Ͽ� �迭�� �����ϰ� �ּڰ��� arr[0]�� ����Ѵ�
 */

#include<iostream>
#include<algorithm>
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
	int sum = 0;
	int min;
	int index = 0;
	int* arr = new int[10000];

	int N, M;
	cin >> M;
	cin >> N;

	for (int i = M; M <= N; M++) {
		if (isPrime(M)) {
			sum += M;
			arr[index++] = M;
		}
	}

	if (index == 0) {
		cout << -1;
		return 0;
	}

	sort(arr, arr + index);
	cout << sum << "\n" << arr[0];
	return 0;

}