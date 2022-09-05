/*
	 [백준 25305] 커트라인
	  22-08-27 / c++

	  < 알고리즘 >

	  배열에 점수 넣고 sort함수로 정렬한 뒤 인덱스로 찾아준다


 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int TESTCASE, iCutLine;
	cin >> TESTCASE >> iCutLine;

	int* score = new int[TESTCASE];

	for (int i = 0; i < TESTCASE; i++) {
		cin >> score[i];
	}

	sort(score, score + TESTCASE);		//오름차순 정렬

	cout << score[TESTCASE - iCutLine];

	

}