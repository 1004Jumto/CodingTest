/*
	 [백준 2480] 주사위세개
	  22-08-26 / c++

	  < 문제 >

	  같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다.
	  같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다.
	  모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다.

	  3개 주사위의 나온 눈이 주어질 때, 상금을 계산하는 프로그램을 작성 하시오.

	  < 알고리즘 >

	  일단 주사위 세개 눈금을 각각 변수에 저장
	  조건문을 통해 모두 같은 눈이 나온 경우부터 계산

 */

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	int FIRST_NUM, SECOND_NUM, THIRD_NUM;

	cin >> FIRST_NUM >> SECOND_NUM >> THIRD_NUM;

	int retMoney;

	// 모두 같은 눈
	if (FIRST_NUM == SECOND_NUM && SECOND_NUM == THIRD_NUM) {
		retMoney = 10000 + FIRST_NUM * 1000;
	}

	// 모두 다른 눈
	else if (FIRST_NUM != SECOND_NUM && SECOND_NUM != THIRD_NUM && FIRST_NUM != THIRD_NUM) {
		//가장 큰 눈 구하기
		int max;
		if (FIRST_NUM > SECOND_NUM && FIRST_NUM > THIRD_NUM) {
			max = FIRST_NUM;
		}

		else if (SECOND_NUM > FIRST_NUM && SECOND_NUM > THIRD_NUM) {
			max = SECOND_NUM;
		}
		else if (THIRD_NUM > SECOND_NUM && THIRD_NUM > FIRST_NUM) {
			max = THIRD_NUM;
		}

		retMoney = max * 100;
	}

	//같은 눈이 2개
	else {
		if (FIRST_NUM == SECOND_NUM) {
			retMoney = 1000 + FIRST_NUM * 100;
		}
		else if (FIRST_NUM == THIRD_NUM) {
			retMoney = 1000 + FIRST_NUM * 100;
		}
		else {
			retMoney = 1000 + SECOND_NUM * 100;
		}
	}

	cout << retMoney;
}