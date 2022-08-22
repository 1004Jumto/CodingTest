/*
	 [백준 10872] 팩토리얼
	  22-08-04 / c++

	  < 문제 >

	  M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

	  < 알고리즘 >

		재귀함수

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