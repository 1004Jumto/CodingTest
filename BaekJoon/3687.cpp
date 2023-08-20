/*
* [백준 3687] 성냥개비
* 성냥개비는 숫자를 나타내기에 아주 이상적인 도구이다.
* 성냥개비의 개수가 주어졌을 때, 성냥개비를 모두 사용해서 만들 수 있는 가장 작은 수와 큰 수를 찾는 프로그램을 작성하시오.

* [알고리즘]
* 다이나믹 프로그래밍
* 
* 가장 큰 수 만드는 경우 -> 그리디 : 자릿수를 늘리는 것이 우선이다
* 가장 작은 수 만드는 경우-> 동적계획법 : dp[i]는 i개를 사용해 만든 최소값
*
*/

#include<iostream>
#include<algorithm>
#include<vector>	
#include<string>

using namespace std;

typedef long long ll;

ll dp[101]{ 0, };
int num[9]{ 0,0,1,7,4,2,0,8,10 };
int testcase;

void DP() {
	for (int i = 1; i <= 8; i++) dp[i] = num[i];
	dp[6] = 6;

	for (int i = 9; i <= 100; i++) {
		dp[i] = 888888888888888;
		for (int j = 2; j < 8; j++) {
			dp[i] = min(dp[i], dp[i - j] * 10 + num[j]);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testcase;
	
	DP();		// 최소값 메모이제이션 : 배열에 저장
	for (int i = 0; i < testcase; i++) {
		int numOFmat; cin >> numOFmat;
		cout << dp[numOFmat] << " ";

		while (numOFmat) {
			if (numOFmat % 2 != 0) {
				cout << 7; numOFmat -= 3;
			}
			else {
				cout << 1;
				numOFmat -= 2;
			}
		}
		cout << "\n";
	}
	
	return 0;
}