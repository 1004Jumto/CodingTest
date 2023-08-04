/*
* [���� 1477] �ްԼ� �����
* �ټ��̴� ���� ��ӵ��θ� ������ �ִ�. �ټ��̴� ���� ��ӵ��ο� �ްԼҸ� N�� ������ �ִµ�, �ްԼ��� ��ġ�� ��ӵ����� �������κ��� ��ŭ ������ �ִ����� �־�����. �ټ��̴� ���� �ްԼҸ� M�� �� ������� �Ѵ�.

* �ټ��̴� �̹� �ްԼҰ� �ִ� ���� �ްԼҸ� �� ���� �� ����, ��ӵ����� ������ �ްԼҸ� ���� �� ����. �ްԼҴ� ���� ��ġ���� ���� �� �ִ�.

* �ټ��̴� �� ��ӵ��θ� �̿��� ��, ��� �ްԼҸ� �湮�Ѵ�. �ټ��̴� �ްԼҸ� M�� �� ��� �ްԼҰ� ���� ������ ������ �ִ��� �ּҷ� �Ϸ��� �Ѵ�. (�ݵ�� M���� ��� ����� �Ѵ�.)

* ���� ���, ��ӵ����� ���̰� 1000�̰�, ���� �ްԼҰ� {200, 701, 800}�� �ְ�, �ްԼҸ� 1�� �� ������� �Ѵٰ� �غ���.

* �ϴ�, ���� �� ��ӵ��θ� Ÿ�� �޸� ��, �ްԼҰ� ���� ������ �ִ��� 200~701������ 501�̴�. ������, ���ο� �ްԼҸ� 451������ ���� �Ǹ�, �ִ밡 251�� �Ǿ �ּҰ� �ȴ�.
*
* [�˰���]
* �̺� Ž��/ �Ű� ���� Ž��
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, L;			// �ްԼ� ����, �� �������� �ްԼ� ����, ��ӵ��� ����
	vector<int> locations;	// �ްԼ� ��ġ

	cin >> N >> M >> L;
	locations.push_back(0);
	locations.push_back(L);
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		locations.push_back(tmp);
	}
	sort(locations.begin(), locations.end());

	int low = 0; int high = L;
	int mid, res = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		
		int count = 0;
		for (int i = 1; i < locations.size(); i++) {
			int dist = locations[i] - locations[i - 1];
			count += (dist / mid);
			if (dist % mid == 0) count--;
		}
		if (count > M) low = mid + 1;
		else {
			high = mid - 1;
			res = mid;
		}
	}
	cout << res;

	return 0;

}