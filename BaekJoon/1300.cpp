/*
* [���� 1300] K��° ��
* �����̴� ũ�Ⱑ N��N�� �迭 A�� �������. �迭�� ����ִ� �� A[i][j] = i��j �̴�. �� ���� ������ �迭 B�� ������ B�� ũ��� N��N�� �ȴ�. B�� �������� �������� ��, B[k]�� ���غ���.
* �迭 A�� B�� �ε����� 1���� �����Ѵ�.
*
* [�˰���]
* �̺� Ž��/ �Ű� ���� Ž��
*
* mid�� Ư������ �Ƿ���
* low�� 1, high�� N*N���� �ϰ�, 2���� �迭���� mid���� ���� �ֵ��� ī��Ʈ �ؼ� mid�� �� �� ° ������ ����.
* mid�� �� ��° ������ �� ��, i��° ���� i�� ����̹Ƿ� mid�� i�� ���� ���� �� �տ� �ִ� ���� ������ ���������̰� �� ���� ���ϸ鼭 ���ش�.
* �� ��, mid/i�� N���� Ŀ�� �� �����Ƿ� mid/i�� N�� ���� ���� ���Ѵ�
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, k; cin >> N >> k;
	int low = 1, high = N * N;
	int mid, cnt, res = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		cnt = 0;

		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}
		if (cnt < k) low = mid + 1;
		else {
			high = mid - 1;
			res = mid;
		}
	}
	cout << res;

	return 0;
}