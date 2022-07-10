/*
	[백준 2884] 알람시계
	2022-07-09 / c++

	알고리즘)
		먼저 시간 입력받고,
		분 단위로 고친다 (범위 : 0 ~ 1440)
		45를 뺀다
		음수면 결과에 +1440
		다시 시/분으로 바꿔준다

*/

#include<iostream>
using namespace std;

int main() {
	int H, M;
	cin >> H >> M;

	int tmp;
	tmp = H * 60 + M;

	tmp -= 45;

	if (tmp < 0) {
		tmp += 1440;
	}

	H = tmp / 60;
	M = tmp % 60;

	cout << H << " " << M;
}