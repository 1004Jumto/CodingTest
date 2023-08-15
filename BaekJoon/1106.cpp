/*
* [���� 1106] ȣ��
* �������� ȣ���� ���� ȣ���� ������ �������� �̹��� ������ ���� �ø��� ���ؼ� ȫ���� �Ϸ��� �Ѵ�.

* �����̰� ȫ���� �� �� �ִ� ���ð� �־�����, �� ���ú��� ȫ���ϴµ� ��� ����, �� �� �� ���� ȣ�� ���� �þ������ ���� ������ �ִ�.

* ���� ���, ��� ���ÿ��� 9���� �鿩�� ȫ���ϸ� 3���� ���� �þ��.���� ���� �����̴�. 
* �̶�, �̷��� ������ ��Ÿ�� ���� ������ ��ŭ�� ������ �� �ִ�. 
* ��, 9���� �鿩�� 3���� ��, 18���� �鿩�� 6���� ��, 27���� �鿩�� 9���� ���� �þ�� �� �� ������, 3���� �鿩�� ȫ���ؼ� 1���� ��, 12���� �鿩�� 4���� ���� �þ�� �� ���� ����.

* �� ���ÿ��� ���� ���� �������� ���� �ִ�. 
* �̶�, ȣ���� ���� ��� C�� ���̱� ���� �����̰� �����ؾ� �ϴ� ���� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

* [�˰���]
* ���̳��� ���α׷���
* ������ȹ������ Ǯ�� ���ؼ��� ��ȭ�İ� �迭�� �����Ѵٴ� ���� ����Ʈ�̴�!

* ó���� i�� ����, dp[i]�� i�� �ø��µ� ���� ������� �����ߴµ�, �˰��� ��� C�� �ø��� ���� ��������. 
* �̰� ��ġ�ٴ�...
* �׷��� i�� ���, dp[i]�� i��ŭ �Ἥ �ø� �� �ִ� �� ���� �����ϰ� Ǯ����.

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

	int c, n;			// �ø��� ���� �� ��, ���� ����
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

