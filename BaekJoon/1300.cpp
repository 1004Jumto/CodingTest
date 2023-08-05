/*
* [백준 1300] K번째 수
* 세준이는 크기가 N×N인 배열 A를 만들었다. 배열에 들어있는 수 A[i][j] = i×j 이다. 이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. B를 오름차순 정렬했을 때, B[k]를 구해보자.
* 배열 A와 B의 인덱스는 1부터 시작한다.
*
* [알고리즘]
* 이분 탐색/ 매개 변수 탐색
*
* mid는 특성값이 되려나
* low를 1, high는 N*N으로 하고, 2차원 배열에서 mid보다 작은 애들을 카운트 해서 mid가 몇 번 째 수인지 센다.
* mid가 몇 번째 수인지 셀 때, i번째 행은 i의 배수이므로 mid를 i로 나눈 몫이 그 앞에 있는 수의 개수와 마찬가지이고 이 수를 더하면서 세준다.
* 이 때, mid/i가 N보다 커질 수 있으므로 mid/i와 N중 작은 값을 더한다
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, k; cin >> N >> k;
	int low = 1, high = N * N;
	int mid, cnt, res = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		cnt = 0;

		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}
		if (cnt < k) low = mid + 1;
		else {
			high = mid - 1;
			res = mid;
		}
	}
	cout << res;

	return 0;
}