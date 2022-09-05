/*
	 [백준 1929] 소수구하기
	  22-08-04 / c++

	  < 문제 >

	  M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

	  < 알고리즘 >

	  에라토스테세스의 체 알고리즘
	  -> 범위 내 수들 중 2의 배수부터 하나씩 지워나가는 방법
	  2의배수, 3의배수, 4의배수...를 지워 남은 수만 출력한다.
	  
 */

#include<iostream>
#include<algorithm>

using namespace std;

void PrimeNumberSieve(int start, int end) 
{
	int* num = new int[end + 1];
	
	//배열 초기화
	for (int i = 0; i <= end; i++) {
		num[i] = i;
	}

	//2부터 배수를 지워준다
	for (int i = 2; i <= end; i++)
	{
		//num[i] 가 0이면 이미 소수가 아니므로 continue
		if (num[i] == 0)
			continue;

		for (int j = 2 * i; j <= end; j += i)
			num[j] = 0;
	}

	//1은 소수가 아니므로 예외처리
	num[1] = 0;

	//출력
	for (int k = start; k <= end; k++) {
		if (num[k] != 0) {
			cout << num[k] << "\n";
		}
	}


}

int main() {
	int M, N;
	cin >> M >> N;

	PrimeNumberSieve(M, N);
	return 0;
}