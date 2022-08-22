/*
	 [백준 1929] 소수구하기
	  22-08-04 / c++

	  < 문제 >

	  M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

	  < 알고리즘 >

	  에라토스테세스의 체 알고리즘
	  
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