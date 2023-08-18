/*
* [백준 3687] 성냥개비
* 성냥개비는 숫자를 나타내기에 아주 이상적인 도구이다.
* 성냥개비의 개수가 주어졌을 때, 성냥개비를 모두 사용해서 만들 수 있는 가장 작은 수와 큰 수를 찾는 프로그램을 작성하시오.

* [알고리즘]
* 다이나믹 프로그래밍
*
*
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int Testcase;

void DP(int num) {

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Testcase;
	for (int i = 0; i < Testcase; i++) {
		int numOFmat; cin >> numOFmat;
		DP(numOFmat);
		cout << "\n";
	}

	return 0;
}