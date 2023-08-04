/*
* [���� 20444] �����̿� ����
* ���õ� ���� �ؼ��̴� ������ �����̿� ������ Ǫ�� �� �����Ͽ���!!
* �����̿� ����� ���� �ؼ��̴� ������ ���� ���̴� �����̸� ��� �߶� �������� �Ѵ�!!

* ���̸� �ڸ� ���� ������ ���� ��Ģ�� ������.
	* �����̴� ���簢���̸�, �����̸� �ڸ� ���� �� ���� �����ϰ� �ڸ���.
	* �ڸ��� ����������, ��� ���� ��� �����̸� �ڸ� ������ ������ �ʴ´�.
	* �̹� �ڸ� ���� �� �ڸ� �� ����.

*�г뿡 �� �������� �ϴ� �ؼ��̴� ���ڱ� �ϳ��� �����̸� ��Ȯ�� n���� �������� k���� ������ �������� ���� �� �ִ��� �ñ�������.
* �ñ������� ȭ�� ���� �ڵ��� ������ �� ���� �ؼ��� ��� �ڵ带 �ۼ����ֵ��� ����.
*
* [�˰���]
* �̺� Ž��/ �Ű� ���� Ž��
* 32��Ʈ = 4����Ʈ = int
* 64bit = 8byte = long long
* 
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

	long long n, k, mid;
	cin >> n >> k;
	long long low = 0; long long high = n / 2;

	while (low <= high) {
		mid = (low + high) / 2;
		long long tmp = (mid + 1) * (n - mid + 1);
		if (tmp == k) {
			cout << "YES"; return 0;
		}
		else if (tmp > k) high = mid - 1;
		else low = mid + 1;
	}
	cout << "NO";

	return 0;
}