/*
	 [���� 1929] �Ҽ����ϱ�
	  22-08-04 / c++

	  < ���� >

	  M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	  < �˰��� >

	  �����佺�׼����� ü �˰���
	  -> ���� �� ���� �� 2�� ������� �ϳ��� ���������� ���
	  2�ǹ��, 3�ǹ��, 4�ǹ��...�� ���� ���� ���� ����Ѵ�.
	  
 */

#include<iostream>
#include<algorithm>

using namespace std;

void PrimeNumberSieve(int start, int end) 
{
	int* num = new int[end + 1];
	
	//�迭 �ʱ�ȭ
	for (int i = 0; i <= end; i++) {
		num[i] = i;
	}

	//2���� ����� �����ش�
	for (int i = 2; i <= end; i++)
	{
		//num[i] �� 0�̸� �̹� �Ҽ��� �ƴϹǷ� continue
		if (num[i] == 0)
			continue;

		for (int j = 2 * i; j <= end; j += i)
			num[j] = 0;
	}

	//1�� �Ҽ��� �ƴϹǷ� ����ó��
	num[1] = 0;

	//���
	for (int k = start; k <= end; k++) {
		if (num[k] != 0) {
			cout << num[k] << "\n";
		}
	}


}

int main() {
	int M, N;
	cin >> M >> N;

	PrimeNumberSieve(M, N);
	return 0;
}