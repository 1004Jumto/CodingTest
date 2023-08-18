/*
* [���� 1823] ��Ȯ
* ���ɰ���� ���ڸ� ��Ÿ���⿡ ���� �̻����� �����̴�. .
* ���ɰ����� ������ �־����� ��, ���ɰ��� ��� ����ؼ� ���� �� �ִ� ���� ���� ���� ū ���� ã�� ���α׷��� �ۼ��Ͻÿ�.

* [�˰���]
* ���̳��� ���α׷���
*
* �׸���ó�� ���������� ������ �ִ��� �ؼ� ������� ������(�ִ�)�� ���� �ʴ´�. -> ��ͷ� ������ ����غ����Ѵ�.
* �̹� ����� ���� �ٲ��� �����Ƿ� �ѹ� ������ ���� �������̴� -> DP
* DP�̹Ƿ� ������� �����س��� ���Ѵ�.
* ���ʰ� ���������� ��Ȯ�ϰ� �ǹǷ� dp[left][right]�� left���� right���� ��Ȯ�� �ִ� ������ �����Ѵ�.
* �����Ҷ����� ������ �����ϹǷ�, �ð����⵵�� O(N^2) �ִ� 2000^2
*
* ��ȭ�� dp[left][right]
			= max(���� ��Ȯ���� �� ���� ����, ������ ��Ȯ���� �� ���� ����)
			= max(dp(left+1, right, count+1) + ��� ��Ȯ�� ����, dp(left, right -1, count+1) + ��� ��Ȯ�� ����)
*
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;
int res[2001][2001]{ 0, };
int w[2001]{ 0, };

int dp(int left, int right, int count) {
	if (left > right) return 0;
	if (res[left][right])return res[left][right];

	int ret = max(dp(left + 1, right, count + 1) + w[left] * count, dp(left, right - 1, count + 1) + w[right] * count);

	res[left][right] = ret;
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> w[i];

	cout << dp(1, N, 1);

	return 0;
}

// ó���� vector<int> w�� ��ġ�� �����ϴ� ���͸� ���������� �����Ͽ�, 
// dp�Լ��� ���ͱ��� ���� �Ѱ��־��µ� �ð��ʰ��� ����...
// �̰� �̷��� �ð��� ���� �ɸ� ���ΰ�..? �迭�� �Ű������� �Ѱ��ٶ� �迭�� �����ϴ� ���� �ƴ϶� ������ �״ϱ� �� �ּҸ� �Ѱܼ� �����ϴ� ������ �˰� �ִµ� 