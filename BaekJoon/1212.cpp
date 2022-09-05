/*
	 [백준 1212] 8진수 2진수
	  22-09-06 / c++

	  < 문제 >

	  8진수를 2진수로 변형하시오

	  < 알고리즘 >

	  각 수를 십진수로 보고 세 자리의 이진수로 변환한 뒤
	  이어붙인다

 */

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(void) {
	string oc;
	cin >> oc;

	if (oc == "0") {
		cout << 0 << "\n";
	}

	string res;
	for (int i = 0; i < oc.length(); i++) {
		res += to_string((oc[i] - '0') / 4);
		res += to_string(((oc[i] - '0') % 4) / 2);
		res += to_string((((oc[i] - '0') % 4) % 2) / 1);

	}

	bool flag = false;
	for (int i = 0; i < res.length(); i++) {
		if (!flag) {
			if (res[i] == '1') {
				flag = true;
				cout << res[i];
			}
		}
		else {
			cout << res[i];
		}
	}
	cout << "\n";

	return 0;
}