/*
	 [백준 1427] 소트인사이드
	  22-08-27 / c++

	  < 알고리즘 >

		숫자를 입력받고
		자리 수를 하나씩 배열에 저장한다
		배열 정렬해주고
		내림차순 정렬을 해준다


 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int iNum[10];
	int idx = 0;

	//배열 초기화
	memset(iNum, -1, 10 * 4);

	cin >> N;

	while (N != 0) {
		iNum[idx++] = N % 10;
		N /= 10;
	}

	sort(iNum, iNum + 10);

	for (int k = 9; k >= 0; k--) {
		if (iNum[k] == -1) {
			break;
		}
		cout << iNum[k];
	}

	return 0;
}
