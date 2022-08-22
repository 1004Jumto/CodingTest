/*
	 [���� 10870] �Ǻ���ġ �� 5
	  22-08-04 / c++

	  < ���� >

	  �Ǻ���ġ ���� 0�� 1�� �����Ѵ�. 0��° �Ǻ���ġ ���� 0�̰�, 1��° �Ǻ���ġ ���� 1�̴�. 
	  �� ���� 2��° ���ʹ� �ٷ� �� �� �Ǻ���ġ ���� ���� �ȴ�.
	  �̸� ������ �Ẹ�� Fn = Fn-1 + Fn-2 (n �� 2)�� �ȴ�.
	  n=17�϶� ���� �Ǻ���ġ ���� �Ẹ�� ������ ����.
	  0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
	  n�� �־����� ��, n��° �Ǻ���ġ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	  < �˰��� >

		����Լ�

 */

#include<iostream>

using namespace std;
int Fibonacci(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 0) {
		return 0;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main(void) {
	int NUM;
	cin >> NUM;

	if (NUM == 0) {
		cout << 0;
		return 0;
	}
	int ans = Fibonacci(NUM);
	
	cout << ans;
	return 0;
}