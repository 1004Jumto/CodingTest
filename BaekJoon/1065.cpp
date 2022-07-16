/*
	[백준 1065] 평균
	2022-07-14 / c++

	어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다.
	등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다.
	N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.

	알고리즘)
		1. 숫자입력 받아서
		2. 반복문에 한수 판별 함수 돌린다
		3. 한수 판별 : 어떤 숫자가 한수인지 아닌지?
		
		한자리수 == 한수
		두자리수 == 한수
		세자리수만 검사하면 됨!

		숫자abc --> 2*b = a+c
*/

#include<iostream>
using namespace std;

inline bool IsHan(int num) {
	int a, b, c;
	a = num / 100; num %= 100;		//첫째 자리
	b = num / 10; num %= 10;		//둘째 자리
	c = num;						//셋째 자리

	if (2 * b == a + c)				//등차중항
	{
		return true;
	}

	return false;
}

int main(void) {
	int X;			//입력받은 수
	int cnt;
	cin >> X;
	
	if (X == 1000)		//1000인 경우 분리 --> 한수 판별이 세자리 수 전용이기 때문에
	{
		cout << 144;
		return 0;
	}

	if (X < 100)		//99까지는 모두 한수
	{
		cnt = X;
	}

	else				//세자리 수인 경우
	{
		cnt = 99;		//99까지

		for (int i = 100; i <= X ; i++)		//입력받은 수까지 반복
		{
			if (IsHan(i)) {					// 한수인지 판별
				++cnt;
			}
		}
	}

	cout << cnt;
	return 0;
}