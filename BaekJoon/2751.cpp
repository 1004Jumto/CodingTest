/*
	 [���� 2751] �� �����ϱ�2
	  22-08-02 / c++

	  N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	  �ð����⵵�� O(nlogn)�� ���� ����ϱ�
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);

	int SIZE;
	cin >> SIZE;

	int* arr = new int[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] <<"\n";
	}
	return 0;
}	