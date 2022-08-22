/*
	 [백준 2581] 소수
	  22-08-03 / c++

	  < 문제 >

	  자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 
	  이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.

	  < 알고리즘 >

	  앞서 만든 소수 판별 함수를 사용한다
	  소수일 경우에 sum에 더하고, 배열에 넣어준다
	  sort함수를 사용하여 배열을 정렬하고 최솟값인 arr[0]을 출력한다
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