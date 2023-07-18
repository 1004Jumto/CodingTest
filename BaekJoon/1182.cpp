/*
* [백준 1182] 부분 수열의 합
* N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

* [알고리즘]
* 완전탐색 알고리즘 : 가능한 모든 경우의 수를 모투 체크해 정답을 찾는 방법
* 그리디와 자꾸 헷갈릴 때가 있는데, 그리디는 현 로컬 시점에서 최적해를 따라 최종적 해답에 이르는 방법이고,
* 완전 탐색은 정말 경우 하나하나 다 따져보는 방법
*
*
*/

#include<iostream>	
#include<algorithm>
#include<vector>
#include<string>	

using namespace std;

int main(void) {
	int N, S;
	vector<int> num;
	int i, j, sum;
	int cnt = 0;

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		num.push_back(tmp);
	}

	for (i = 1; i < (1 << num.size()); i++) {
		sum = 0;
		for (j = 0; j < num.size(); j++) {
			if (i & (1 << j)) sum += num[j];
		}
		if (sum == S) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}