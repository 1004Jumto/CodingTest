/*
* [���� 10974] ��� ����
* N�� �־����� ��, 1���� N������ ���� �̷���� ������ ���������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

* [�˰���]
* ����Ž�� �˰��� : ������ ��� ����� ���� ���� üũ�� ������ ã�� ���
* �׸���� �ڲ� �򰥸� ���� �ִµ�, �׸���� �� ���� �������� �����ظ� ���� ������ �ش信 �̸��� ����̰�,
* ���� Ž���� ���� ��� �ϳ��ϳ� �� �������� ���
*
*
*/

#include<iostream>	
#include<algorithm>
#include<vector>
#include<string>	

using namespace std;

int N;
int nums[9];
int visited[9];

void Permutation(int n) {
	if (n == N) {
		for (int i = 0; i < N; i++) cout << nums[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			nums[n] = i + 1;
			Permutation(n + 1);
			visited[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	Permutation(0);
	
	return 0;
}

/*

�ƴ� endl�̶� \n�̶� ���̰� �̷��� ũ�ٰ�??
�ƹ��� endl�� flush�� �����Ѵٰ� �ص� �׷��� �̷��Ա��� ���̰� �����̾�? �׷�����..
*/