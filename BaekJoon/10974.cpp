/*
* [백준 10974] 모든 순열
* N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램을 작성하시오.

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

int N;
int nums[9];
int visited[9];

void Permutation(int n) {
	if (n == N) {
		for (int i = 0; i < N; i++) cout << nums[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			nums[n] = i + 1;
			Permutation(n + 1);
			visited[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	Permutation(0);
	
	return 0;
}

/*

아니 endl이랑 \n이랑 차이가 이렇게 크다고??
아무리 endl이 flush를 내포한다고 해도 그렇지 이렇게까지 차이가 날일이야? 그런가봄..
*/