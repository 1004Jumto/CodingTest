/*
	[���� 1110] ���ϱ����Ŭ
	2022-07-13 / c++

	�˰���)
		1.���� �� �Է¹ް�
		2.ù��° �� a, �ι�° ��b �и��Ѵ�--> /10, %10 ���
		3.�� �� ���Ѵ� sum
		4.���ο� �� ����� b*10 + sum%10
		5.�� --> ������ Ż��, �ƴϸ� �ݺ�

*/

#include<iostream>
using namespace std;

int CountCycle(int num) {
	int NumofCycle = 0;		//����Ŭ ��
	int a, b;				//�����ڸ�, �����ڸ�
	int sum;			    //�� �ڸ� ���� ��
	int NewNum = num;		//���ο� ��

	do
	{
		++NumofCycle;
		a = NewNum / 10;
		b = NewNum % 10;
		sum = a + b;
		NewNum = b * 10 + sum % 10;

	} while (num != NewNum);

	return NumofCycle;

}

int main() {
	int N;
	cin >> N;

	cout << CountCycle(N);
	return 0;
}