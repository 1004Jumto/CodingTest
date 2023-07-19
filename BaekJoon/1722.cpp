/*
* [백준 1722] 순열의 순서
* 1부터 N까지의 수를 임의로 배열한 순열은 총 N! = N×(N-1)×…×2×1 가지가 있다.

* 임의의 순열은 정렬을 할 수 있다.
* 예를 들어  N=3인 경우 {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}의 순서로 생각할 수 있다.
* 첫 번째 수가 작은 것이 순서상에서 앞서며, 첫 번째 수가 같으면 두 번째 수가 작은 것이,
* 두 번째 수도 같으면 세 번째 수가 작은 것이….

* N이 주어지면, 아래의 두 소문제 중에 하나를 풀어야 한다.
* k가 주어지면 k번째 순열을 구하고, 임의의 순열이 주어지면 이 순열이 몇 번째 순열인지를 출력하는 프로그램을 작성하시오.

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

int cnt = 0;
int k = 0;
int Permutaion_with_visited(int v[], bool visited[], int output[], int depth, int n, int r) {
	if (depth == r) {
		cnt++;
		if (k == cnt) {
			for (int i = 0; i < depth; i++) {
				cout << output[i] << " ";
			}
		}
		return cnt;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] != true) {
			visited[i] = true;
			output[depth] = v[i];
			if(Permutaion_with_visited(v, visited, output, depth + 1, n, r) == k) return k;
			visited[i] = false;
		}
	}
}

int* res;
void Permutaion_with_visited2(int v[], bool visited[], int output[], int depth, int n, int r) {
	if (depth == r) {
		cnt++;
		if (equal(res, res+depth, output)) {
			cout << cnt; return;
		}
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] != true) {
			visited[i] = true;
			output[depth] = v[i];
			Permutaion_with_visited2(v, visited, output, depth + 1, n, r);
			visited[i] = false;
		}
	}
}

int main(void) {
	int N; std::cin >> N;
	int P; cin >> P;
	int* arr = new int[N];
	int* output = new int[N];
	bool* visited = new bool[N];
	res = new int[N];

	// 배열 초기화
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}

	if (P == 1) {		// k번째 순열 출력
		cin >> k;
		Permutaion_with_visited(arr, visited, output, 0, N, N);
	}
	else{				// 주어진 순열이 몇번째 순열인지 출력
		for (int i = 0; i < N; i++) {
			int tmp; cin >> tmp;
			res[i] = tmp;
		}
		Permutaion_with_visited2(arr, visited, output, 0, N, N);
	}
	return 0;
}