/*
* [백준 1823] 수확
* 성냥개비는 숫자를 나타내기에 아주 이상적인 도구이다. .
* 성냥개비의 개수가 주어졌을 때, 성냥개비를 모두 사용해서 만들 수 있는 가장 작은 수와 큰 수를 찾는 프로그램을 작성하시오.

* [알고리즘]
* 다이나믹 프로그래밍
*
* 그리디처럼 지역적으로 이익이 최대라고 해서 결과값이 최적해(최댓값)이 되지 않는다. -> 재귀로 끝까지 계산해봐야한다.
* 이미 저장된 값은 바뀌지 않으므로 한번 정해진 값은 고정적이다 -> DP
* DP이므로 결과값을 저장해놓고 비교한다.
* 왼쪽과 오른쪽으로 수확하게 되므로 dp[left][right]에 left까지 right까지 수확한 최대 이익을 저장한다.
* 저장할때마다 끝까지 가야하므로, 시간복잡도는 O(N^2) 최대 2000^2
*
* 점화식 dp[left][right]
			= max(왼쪽 수확했을 때 최종 이익, 오른쪽 수확했을 때 최종 이익)
			= max(dp(left+1, right, count+1) + 방금 수확한 이익, dp(left, right -1, count+1) + 방금 수확한 이익)
*
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;
int res[2001][2001]{ 0, };
int w[2001]{ 0, };

int dp(int left, int right, int count) {
	if (left > right) return 0;
	if (res[left][right])return res[left][right];

	int ret = max(dp(left + 1, right, count + 1) + w[left] * count, dp(left, right - 1, count + 1) + w[right] * count);

	res[left][right] = ret;
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> w[i];

	cout << dp(1, N, 1);

	return 0;
}

// 처음엔 vector<int> w로 가치를 저장하는 벡터를 지역변수로 선언하여, 
// dp함수에 벡터까지 같이 넘겨주었는데 시간초과가 났다...
// 이게 이렇게 시간이 많이 걸릴 일인가..? 배열은 매개변수로 넘겨줄때 배열을 복사하는 것이 아니라 포인터 그니까 그 주소를 넘겨서 참조하는 것으로 알고 있는데 