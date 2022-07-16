/*
	[백준 1110] 더하기사이클
	2022-07-13 / c++

	알고리즘)
		1.먼저 수 입력받고
		2.첫번째 수 a, 두번째 수b 분리한다--> /10, %10 사용
		3.두 수 더한다 sum
		4.새로운 수 만든다 b*10 + sum%10
		5.비교 --> 같으면 탈출, 아니면 반복

*/

#include<iostream>
using namespace std;

int CountCycle(int num) {
	int NumofCycle = 0;		//사이클 수
	int a, b;				//십의자리, 일의자리
	int sum;			    //두 자리 더한 수
	int NewNum = num;		//새로운 수

	do
	{
		++NumofCycle;
		a = NewNum / 10;
		b = NewNum % 10;
		sum = a + b;
		NewNum = b * 10 + sum % 10;

	} while (num != NewNum);

	return NumofCycle;

}

int main() {
	int N;
	cin >> N;

	cout << CountCycle(N);
	return 0;
}