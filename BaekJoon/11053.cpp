/*
* [���� 11053] ���� �� �����ϴ� �κм���
* ���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
* ���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 20, 10, 30, 20, 50} �̰�, ���̴� 4�̴�.


*
* [�˰���]
* ���̳��� ���α׷���
* ������ȹ������ Ǯ�� ���ؼ��� ��ȭ�İ� �迭�� �����Ѵٴ� ���� ����Ʈ�̴�!
* 
* dp[n]�� �־��� ������ n��° ���ұ��� �����Ͽ� ���� �� �ִ� ���� �� �����ϴ� �κм����� �����̴�.
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