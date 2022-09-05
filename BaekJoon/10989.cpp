/*
	 [백준 10989] 수 정렬하기
	  22-08-27 / c++

	  < 알고리즘 >

	  배열에 점수 넣고 sort함수로 정렬한 뒤 인덱스로 찾아준다


 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	//속도를 위해 명시해줌
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TESTCASE;
	cin >> TESTCASE;

	int arr[10001] = { 0 };

	for (int i = 0; i < TESTCASE; i++) {
		int num;
		cin >> num;
		arr[num]++;
	}

	for (int j = 0; j < 10001; j++) {
		for (int k = 0; k < arr[j]; k++) {
			cout << j << "\n";
		}
	}

	return 0;
}