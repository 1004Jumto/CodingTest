/*
	13736�� : �����й�
	��� : C++
	�˰���)
		1. �ϴ� �׽�Ʈ���̽� �Է¹ް� -> for������ ������
		2. a,b,l �Է¹ް�
		3. for������ l�� ������
		4. X = 2X, Y = Y-X �� �� �μ� ũ�� ��
		5. min(); ���
*/

#include<iostream>
using namespace std;

int main(){
	int TestCase;
	int X, Y, L;
	int tmp;

	cin >> TestCase;
	int * res = new int[TestCase];

	for (int i = 0; i < TestCase; i++) {
		cin >> X >> Y >> L;
		
		for (int j = 0; j < L; j++) {
			
			if (X > Y) {
				tmp = Y;
				Y = X;
				X = tmp;
			}

			Y = Y - X;
			X = 2 * X;

		}
		res[i] = min(X, Y);
	}

	for (int i = 0; i < TestCase; i++)
	{
		cout << "#" << i+1 << " " << res[i] << endl;
		
	}




}