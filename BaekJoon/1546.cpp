/*
	[���� 1546] ���
	2022-07-14 / c++

	�˰���)
		1. �׽�Ʈ���̽� �Է¹ް�
		2. ���� �Է¹ޱ� --> ���� �迭�� �Է¹޾ƾ���
		3. �ְ��� ã�Ƽ� /M*100 ��� --> �ְ��� ã�� ���� �ݺ���
		4. ��հ�� --> sum / len
*/

#include<iostream>
using namespace std;

int main(void) {
	int TestCase;		//���� ��
	int M = 0;			//�ְ���
	double sum = 0;		//������
	double avg;			//���

	cin >> TestCase;							// testcase �Է¹ޱ�

	double * arr = new double[TestCase];		// ���� �迭 �Ҵ�

	for (int i = 0; i < TestCase; i++)			// ���� �Է¹ޱ�
	{
		cin >> arr[i];
		
		if (M < arr[i])							// �ְ��� ã��
		{
			M = arr[i];
		}
	}

	for (int i = 0; i < TestCase; i++)			// ���	
	{
		arr[i] = arr[i] / M * 100;
		sum += arr[i];
	}

	avg = sum / TestCase;						//��� ���ϱ�
	cout << avg;

	return 0;
}