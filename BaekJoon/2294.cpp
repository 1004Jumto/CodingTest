/*
* [백준 2294] 동전2
* n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 
* 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.

* 사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

* [알고리즘]
* 다이나믹 프로그래밍
* 동적계획법으로 풀기 위해서는 점화식과 배열에 저장한다는 것이 포인트이다!

* 

*/

#include<iostream>
#include<algorithm>
#include<vector>	

#define INF 10001
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k; cin >> n >> k;
	vector<int> coin(n+1);
	for (int i = 1; i <= n; i++)cin >> coin[i];

	int dp[10001];
	fill_n(dp, 10001, INF);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	if (dp[k] == INF) cout << -1;
	else cout << dp[k];

	return 0;
}

/// 아 C++에서 맨날 벡터만 쓰고 배열 초기화 방법을 제대로 모르고 있었더니 초기화를 잘못해서 참사가 발생했다
/// 배열 크기만큼 한번에 초기화하는 것은 0만 가능하다. {0, }; 이런식으로 가능. 그러나 다른 수로 초기화 못함. 
/// 다른 수로 모두 초기화하기 위해 반복문을 쓰거나 위처럼 fill_n함수를 써서 초기화할 수 있다.