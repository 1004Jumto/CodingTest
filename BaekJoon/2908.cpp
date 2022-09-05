/*
	 [백준 2908] 상수
	  22-08-27 / c++

	  < 알고리즘 >

	  세자리 같지않은 0포함되지도 않은 수를 입력받으므로 뒤에서부터 비교해준다

 */

#include <iostream>
#include <string>

using namespace std;

int main(void) {

	string a, b;
	cin >> a >> b;

	for (int i = 2; i >= 0; i--) {
		int a_tmp = a[i] - '0';
		int b_tmp = b[i] - '0';

		if (a_tmp > b_tmp) {
			cout << a[2] << a[1] << a[0];
			return 0;
		}
		else if (a_tmp < b_tmp) {
			cout << b[2] << b[1] << b[0];
			return 0;
		}
		else
			continue;
	}

	return 0;
}