/*
* [���� 1535] �ȳ�
* �����̴� ���������� �� �Ŀ� ������ �ʹ� ���� �Կ��� �־���. ���� �����̰� ������ �Կ��� ���� �ڱ⸦ �������� ����鿡�� �����ϴٰ� ���� �����̴�.

�����̸� �������� ����� �� N���� �ִ�. ����� ��ȣ�� 1������ N������ �ִ�. �����̰� i�� ������� �λ縦 �ϸ� L[i]��ŭ�� ü���� �Ұ�, J[i]��ŭ�� ����� ��´�. �����̴� ������ ������� �ִ� 1���� ���� �� �ִ�.

�������� ��ǥ�� �־��� ü�³����� �ִ����� ����� ������ ���̴�. �������� ü���� 100�̰�, ����� 0�̴�. ���� �������� ü���� 0�̳� ������ �Ǹ�, �׾ �ƹ��� ����� �� ���� ���� �ȴ�. �����̰� ���� �� �ִ� �ִ� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

* [�˰���]
* ���̳��� ���α׷���
*
*
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int Testcase;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Testcase;
	int strength[21]{ 0, };
	int happy[21]{ 0, };
	int dp[101]{ 0, };

	for (int i = 1; i <= Testcase; i++) cin >> strength[i];
	for (int i = 1; i <= Testcase; i++) cin >> happy[i];
	for (int i = 1; i <= Testcase; i++) {
		for (int j = 100; j >= strength[i]; j--) {
			dp[j] = max(dp[j], dp[j - strength[i]] + happy[i]);
		}
	}
	for (int i = 0; i < 101; i++) {
		cout << dp[i] << " ";
	}

	cout << dp[100];
	return 0;
}