/*
* [���� 3687] ���ɰ���
* ���ɰ���� ���ڸ� ��Ÿ���⿡ ���� �̻����� �����̴�.
* ���ɰ����� ������ �־����� ��, ���ɰ��� ��� ����ؼ� ���� �� �ִ� ���� ���� ���� ū ���� ã�� ���α׷��� �ۼ��Ͻÿ�.

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

void DP(int num) {

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Testcase;
	for (int i = 0; i < Testcase; i++) {
		int numOFmat; cin >> numOFmat;
		DP(numOFmat);
		cout << "\n";
	}

	return 0;
}