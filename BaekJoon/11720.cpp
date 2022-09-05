/*
	 [백준 11720] 숫자의 합
	  22-08-27 / c++

	  < 알고리즘 >

	  문자열로 입력받아 반복문을 돌리면서 하나씩 떼어낸다
	  정수형으로 변환시켜 모두 더한다

 */

#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);;
	cout.tie(NULL);;

	int TESTCASE, iSum = 0;
	string str;

	cin >> TESTCASE;
	cin >> str;

	for (int i = 0; i < TESTCASE; i++) {
		int tmp = str[i] - '0';
		iSum += tmp;
	}

	cout << iSum;
	return 0;


}