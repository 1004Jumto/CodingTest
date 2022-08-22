/*
	 [백준 1978] 소수찾기 
	  22-08-03 / c++

	  < 문제 >

	  주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

	  < 알고리즘 >

	  소수 판별하기
	  1. 숫자 입력받고 N,
	  2. N까지 반복문을 돌리며 N을 나눠본다.
	  3. 나머지가 0이 나오는 숫자가 있으면 소수가 아니므로 패스한다
	  4. 이때, 1과 2는 for문을 돌리지 않고 미리 값을 리턴해준다
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
	int N; // 숫자 개수
	cin >> N;

	int cnt = 0;
	int *arr = new int[N];		//숫자 입력받기
	
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