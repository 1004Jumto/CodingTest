/*
	 [백준 2525] 오븐시계
	  22-08-02 / c++

	  < 문제 >
	  훈제오리구이를 시작하는 시각과 오븐구이를 하는 데 필요한 시간이 분단위로 주어졌을 때, 
	  오븐구이가 끝나는 시각을 계산하는 프로그램을 작성하시오.

	  첫째 줄에는 현재 시각이 나온다. 
	  현재 시각은 시 A (0 ≤ A ≤ 23) 와 분 B (0 ≤ B ≤ 59)가 정수로 빈칸을 사이에 두고 순서대로 주어진다. 
	  두 번째 줄에는 요리하는 데 필요한 시간 C (0 ≤ C ≤ 1,000)가 분 단위로 주어진다. 

	  < 알고리즘 >
	  시간을 분으로 바꾸고 계산한 뒤 다시 시와 분으로 고쳐준다.

 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int H, M;		
	int T;

	cin >> H >> M;
	cin >> T;

	int retTime = H * 60 + M + T;

	if (retTime >= 60 * 24) {
		retTime -= 60 * 24;
	}

	H = retTime / 60;
	M = retTime - (H * 60);

	cout << H << " " << M;

	return 0;

}