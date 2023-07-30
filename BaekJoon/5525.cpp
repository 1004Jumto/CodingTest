/*
* [백준 5525] IOIOI
* N+1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다.
	P1 IOI
	P2 IOIOI
	P3 IOIOIOI
	PN IOIOI...OI (O가 N개)
* I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, 
* S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.
*
* [알고리즘]
* OI를 한 세트로 보고, 현재 문자가 I이면 뒤의 문자열이 OI일 경우에 카운트한다.
* 카운트한 값이 n과 같아지면 Pn에 존재하는 것이므로 결과값을 증가시킨다
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	string S;
	int ans = 0;

	cin >> N >> M >> S;
	for (int i = 1; i < S.size(); i++) {
		int cnt = 0;
		if (S[i - 1] == 'I') {
			while (S[i] == 'O' && S[i + 1] == 'I') {
				i += 2;
				cnt++;
				if (cnt == N) {
					cnt--; ans++;
				}
			}
		}
	}

	cout << ans;
	return 0;

}