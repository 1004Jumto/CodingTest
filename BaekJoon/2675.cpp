/*
	 [백준 2675] 문자열 반복
	  22-08-27 / c++

	  < 알고리즘 >

	  문자열을 입력받고
	  빈 문자열 변수에 반복문으로 돌리며 문자열을 붙여준다

 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int TESTCASE;
	cin >> TESTCASE;

	for (int i = 0; i < TESTCASE; i++) {
		
		int N;
		string Str;
		cin >> N >> Str;
		for (int j = 0; j < Str.length(); j++) {
			for (int k = 0; k < N; k++) {
				cout << Str[j];
			}
		}

		cout << "\n";
	}
    return 0;
}