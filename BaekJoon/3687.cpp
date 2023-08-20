/*
* [���� 3687] ���ɰ���
* ���ɰ���� ���ڸ� ��Ÿ���⿡ ���� �̻����� �����̴�.
* ���ɰ����� ������ �־����� ��, ���ɰ��� ��� ����ؼ� ���� �� �ִ� ���� ���� ���� ū ���� ã�� ���α׷��� �ۼ��Ͻÿ�.

* [�˰���]
* ���̳��� ���α׷���
* 
* ���� ū �� ����� ��� -> �׸��� : �ڸ����� �ø��� ���� �켱�̴�
* ���� ���� �� ����� ���-> ������ȹ�� : dp[i]�� i���� ����� ���� �ּҰ�
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
	
	DP();		// �ּҰ� �޸������̼� : �迭�� ����
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