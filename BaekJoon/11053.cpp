/*
* [백준 11053] 가장 긴 증가하는 부분수열
* 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
* 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.


*
* [알고리즘]
* 다이나믹 프로그래밍
* 동적계획법으로 풀기 위해서는 점화식과 배열에 저장한다는 것이 포인트이다!
* 
* dp[n]은 주어진 수열의 n번째 원소까지 포함하여 만들 수 있는 가장 긴 증가하는 부분수열의 길이이다.
* 
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}

	vector<int> dp(N, 1);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}