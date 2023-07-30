/*
* [���� 5525] IOIOI
* N+1���� I�� N���� O�� �̷���� ������, I�� O�� ����� ������ ���ڿ��� PN�̶�� �Ѵ�.
	P1 IOI
	P2 IOIOI
	P3 IOIOIOI
	PN IOIOI...OI (O�� N��)
* I�� O�θ� �̷���� ���ڿ� S�� ���� N�� �־����� ��, 
* S�ȿ� PN�� �� ���� ���ԵǾ� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*
* [�˰���]
* OI�� �� ��Ʈ�� ����, ���� ���ڰ� I�̸� ���� ���ڿ��� OI�� ��쿡 ī��Ʈ�Ѵ�.
* ī��Ʈ�� ���� n�� �������� Pn�� �����ϴ� ���̹Ƿ� ������� ������Ų��
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	string S;
	int ans = 0;

	cin >> N >> M >> S;
	for (int i = 1; i < S.size(); i++) {
		int cnt = 0;
		if (S[i - 1] == 'I') {
			while (S[i] == 'O' && S[i + 1] == 'I') {
				i += 2;
				cnt++;
				if (cnt == N) {
					cnt--; ans++;
				}
			}
		}
	}

	cout << ans;
	return 0;

}