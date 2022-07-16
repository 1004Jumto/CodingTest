/*
	[백준 1546] 평균
	2022-07-14 / c++

	알고리즘)
		1. 테스트케이스 입력받고
		2. 점수 입력받기 --> 숫자 배열에 입력받아야함
		3. 최고점 찾아서 /M*100 계산 --> 최고점 찾기 위해 반복문
		4. 평균계산 --> sum / len
*/

#include<iostream>
using namespace std;

int main(void) {
	int TestCase;		//과목 수
	int M = 0;			//최고점
	double sum = 0;		//점수합
	double avg;			//결과

	cin >> TestCase;							// testcase 입력받기

	double * arr = new double[TestCase];		// 동적 배열 할당

	for (int i = 0; i < TestCase; i++)			// 숫자 입력받기
	{
		cin >> arr[i];
		
		if (M < arr[i])							// 최고점 찾기
		{
			M = arr[i];
		}
	}

	for (int i = 0; i < TestCase; i++)			// 계산	
	{
		arr[i] = arr[i] / M * 100;
		sum += arr[i];
	}

	avg = sum / TestCase;						//평균 구하기
	cout << avg;

	return 0;
}