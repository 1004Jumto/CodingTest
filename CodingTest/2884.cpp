/*
	[���� 2884] �˶��ð�
	2022-07-09 / c++

	�˰���)
		���� �ð� �Է¹ް�,
		�� ������ ��ģ�� (���� : 0 ~ 1440)
		45�� ����
		������ ����� +1440
		�ٽ� ��/������ �ٲ��ش�

*/

#include<iostream>
using namespace std;

int main() {
	int H, M;
	cin >> H >> M;

	int tmp;
	tmp = H * 60 + M;

	tmp -= 45;

	if (tmp < 0) {
		tmp += 1440;
	}

	H = tmp / 60;
	M = tmp % 60;

	cout << H << " " << M;
}