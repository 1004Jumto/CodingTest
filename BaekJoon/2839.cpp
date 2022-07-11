#include<iostream>
using namespace std;

/*
 �������� �ּ� ������ ���ؾ� ��!

 �ϴ� N�� 5�� ������ (���� m) -> �������� 0,1,2,3,4
 ������ 0�� ��� : ���� ����
 ������ 1�� ��� : 5Ű�� ¥���� m-1��, 6Ű�� �������Ƿ� 3Ű��¥�� �ΰ� �߰�
 ������ 2�� ��� : 5Ű��¥���� m-1���� �ϸ�, 7Ű�� ���µ� 3�� ��� �ƴϴϱ�
				   5Ű��¥�� m-2��, �׷��� 12Ű�� �����Ƿ� 3Ű��¥�� 4�� �߰���
 ������ 3�� ��� : 5Ű��¥�� m��, 3Ű��¥�� �Ѱ� �߰�
 ������ 4�� ��� : 5Ű��¥�� m-1��, 9Ű�� �����ϱ� 3Ű��¥�� ���� �߰�
*/

int TOTAL;

int main() {
	int N;
	int Kg_5;
	int rem;

	cin >> N;		//�ϴ� Ű�� �Է¹ް�
	Kg_5 = N / 5;
	rem = N % 5;

	switch (rem)
	{
	case 0:
		TOTAL = Kg_5;
		break;

	case 1:
		Kg_5 -= 1;
		TOTAL = Kg_5 + 2;
		break;

	case 2:
		Kg_5 -= 2;
		TOTAL = Kg_5 + 4;
		break;

	case 3:
		TOTAL = Kg_5 + 1;
		break;

	case 4:
		Kg_5 -= 1;
		TOTAL = Kg_5 + 3;
		break;
	}

	if (Kg_5 < 0)
		TOTAL = -1;

	cout << TOTAL;
	return 0;

}