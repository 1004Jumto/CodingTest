/*
	 [백준 1009] 분산처리
	  22-08-26 / c++

	  < 문제 >
	  
	  재용이는 최신 컴퓨터 10대를 가지고 있다. 
	  어느 날 재용이는 많은 데이터를 처리해야 될 일이 생겨서 각 컴퓨터에 1번부터 10번까지의 번호를 부여하고, 
	  10대의 컴퓨터가 다음과 같은 방법으로 데이터들을 처리하기로 하였다.

	  1번 데이터는 1번 컴퓨터, 2번 데이터는 2번 컴퓨터, 3번 데이터는 3번 컴퓨터, ... ,
	  10번 데이터는 10번 컴퓨터, 11번 데이터는 1번 컴퓨터, 12번 데이터는 2번 컴퓨터, ...
	  
	  총 데이터의 개수는 항상 a^b개의 형태로 주어진다. 
	  재용이는 문득 마지막 데이터가 처리될 컴퓨터의 번호가 궁금해졌다. 이를 수행해주는 프로그램을 작성하라.

	  < 알고리즘 >

	  1. 데이터 개수의 맨 마지막 자리가 컴퓨터 번호를 결정하므로 맨 마지막 자리를 구해준다 --> 99의 999999승처럼 수가 무한으로 발산하므로 불가능
		 (참고로 나머지 연산자는 정수형만 가능하다)

	  2. 곱셈일때, 뒷 자리 수가 규칙이 있음을 이용한다. 
		1 -> 1 1 1 ...
		2 -> 2 4 8 6 2 ...
		3 -> 3 9 7 1 3 ...
		4 -> 4 6 4 ...
		5 -> 5 5 5 ...
		6 -> 6 6 6 ...
		7 -> 7 9 3 1 7 ...
		8 -> 8 4 2 6 8 ...
		9 -> 9 1 9 ...
		10 -> 0 0 0 ...

 */

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;


int main(void) {
	int TESTCASE, a, b;
	cin >> TESTCASE;

	int* res = new int[TESTCASE];

	for (int i = 0; i < TESTCASE; i++) {
		cin >> a >> b;

		int a_last = a % 10;

		if (a_last == 1 || a_last == 5 || a_last == 6 ) {
			res[i] = a_last;
		}

		else if (a_last == 0) {
			res[i] = 10;
		}

		else if (a_last == 4  || a_last == 9) {
			if (b % 2 == 0) {
				res[i] = (a_last * a_last) % 10;
			}
			else {
				res[i] = a_last;
			}
		}
		else {
			int b_remain = b % 4;
			if (b_remain == 0) {
				b_remain = 4;
			}

			int tmp = pow(a_last, b_remain);
			res[i] = tmp % 10;
		}
	}

	for (int i = 0; i < TESTCASE; i++) {
		cout << res[i] << "\n";
	}

	return 0;
}