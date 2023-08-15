/*
* [백준 9251] LCS
* LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 
* 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

* 예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

* [알고리즘]
* 다이나믹 프로그래밍
* 이것을 맨 처음에 어떻게 생각해내는지 너무 신기하다..
* 
* 두 문자열 a, b 길이를 n,m이라고 했을 때,
* n*m 크기의 이차원 dp배열을 만든다. 
* 문자열의 문자를 하나씩 비교하는데, 두 문자가 일치한다면 dp[i, j] = dp[i-1, j-1]+1
* 두 문자가 일치하지 않는다면 그전에 일치한 문자 개수중 큰 값을 가져간다. dp[i, j] = max(dp[i-1, j], dp[i, j-1])

*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;
int dp[1001][1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string A, B;
	cin >> A >> B;

	for (int i = 0; i <= A.length(); i++) dp[0][i] = 0;
	for (int i = 0; i <= B.length(); i++) dp[i][0] = 0;
	for (int i = 1; i <= B.length(); i++) {
		for (int j = 1; j <= A.length(); j++)
			if (B[i-1] == A[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	}

	cout << dp[B.length()][A.length()];

	return 0;
}

