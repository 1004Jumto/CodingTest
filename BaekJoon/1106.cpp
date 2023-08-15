/*
* [백준 1106] 호텔
* 세계적인 호텔인 형택 호텔의 사장인 김형택은 이번에 수입을 조금 늘리기 위해서 홍보를 하려고 한다.

* 형택이가 홍보를 할 수 있는 도시가 주어지고, 각 도시별로 홍보하는데 드는 비용과, 그 때 몇 명의 호텔 고객이 늘어나는지에 대한 정보가 있다.

* 예를 들어, “어떤 도시에서 9원을 들여서 홍보하면 3명의 고객이 늘어난다.”와 같은 정보이다. 
* 이때, 이러한 정보에 나타난 돈에 정수배 만큼을 투자할 수 있다. 
* 즉, 9원을 들여서 3명의 고객, 18원을 들여서 6명의 고객, 27원을 들여서 9명의 고객을 늘어나게 할 수 있지만, 3원을 들여서 홍보해서 1명의 고객, 12원을 들여서 4명의 고객을 늘어나게 할 수는 없다.

* 각 도시에는 무한 명의 잠재적인 고객이 있다. 
* 이때, 호텔의 고객을 적어도 C명 늘이기 위해 형택이가 투자해야 하는 돈의 최솟값을 구하는 프로그램을 작성하시오.

* [알고리즘]
* 다이나믹 프로그래밍
* 동적계획법으로 풀기 위해서는 점화식과 배열에 저장한다는 것이 포인트이다!

* 처음엔 i를 고객수, dp[i]를 i명 늘리는데 사용된 비용으로 가정했는데, 알고보니 적어도 C명 늘리는 것이 문제였다. 
* 이걸 놓치다니...
* 그래서 i를 비용, dp[i]를 i만큼 써서 늘릴 수 있는 고객 수로 가정하고 풀었다.

*/

#include<iostream>
#include<algorithm>
#include<vector>	

#define MAX 1000 * 100 +1

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c, n;			// 늘리고 싶은 고객 수, 도시 개수
	cin >> c >> n;

	vector<pair<int, int>> cost_customer;
	int customer, cost;
	cost_customer.push_back(make_pair(0,0));
	for (int i = 1; i <= n; i++) {
		cin >> cost >> customer;
		cost_customer.push_back(make_pair(cost, customer));
	}

	int dp[MAX]; 
	std::fill_n(dp, MAX, 0);

	for (int i = 1; i <= MAX-1; i++) {
		for (int j = 0; j <= n; j++) {
			if (i % cost_customer[j].first == 0) {
				dp[i] = max(dp[i], (i / cost_customer[j].first) * cost_customer[j].second);
			}
			if (i - cost_customer[j].first >= 0) {
				dp[i] = max(dp[i], dp[i - cost_customer[j].first] + cost_customer[j].second);
			}
		}
		if (dp[i] >= c) {
			cout << i;
			return 0;
		}
		
	}

	return 0;
}

