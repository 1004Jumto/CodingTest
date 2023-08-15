/*
* [���� 9251] LCS
* LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��, 
* ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.

* ���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.

* [�˰���]
* ���̳��� ���α׷���
* �̰��� �� ó���� ��� �����س����� �ʹ� �ű��ϴ�..
* 
* �� ���ڿ� a, b ���̸� n,m�̶�� ���� ��,
* n*m ũ���� ������ dp�迭�� �����. 
* ���ڿ��� ���ڸ� �ϳ��� ���ϴµ�, �� ���ڰ� ��ġ�Ѵٸ� dp[i, j] = dp[i-1, j-1]+1
* �� ���ڰ� ��ġ���� �ʴ´ٸ� ������ ��ġ�� ���� ������ ū ���� ��������. dp[i, j] = max(dp[i-1, j], dp[i, j-1])

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
			if (B[i] == A[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	}

	cout << dp[B.length()][A.length()];

	return 0;
}
//#include <iostream>
//#include <string>
//using namespace std;
//int dp[1002][1002];
//int mx(int a, int b) {
//    return a > b ? a : b; // ���� ������
//}
//int main() {
//    string s1;
//    string s2;
//    cin >> s1 >> s2;
//    dp[0][0] = 0;
//    for (int i = 0; i <= s1.length(); i++) {
//        dp[i][0] = 0;
//    } for (int i = 0; i <= s2.length(); i++) {
//        dp[0][i] = 0;
//    }
//    for (int i = 1; i <= s1.length(); i++)
//    {
//        for (int j = 1; j <= s2.length(); j++)
//        {
//            if (s1[i - 1] == s2[j - 1])
//            {
//                dp[i][j] = dp[i - 1][j - 1] + 1;
//                // ���ڿ��� ���� lcs�ϳ� �÷���
//            }
//            else
//            {
//                dp[i][j] = mx(dp[i][j - 1], dp[i - 1][j]);
//                //�� �� �� ū �� ����
//            }
//        }
//    }
//    cout << dp[s1.length()][s2.length()];
//    return 0;
//
//}
