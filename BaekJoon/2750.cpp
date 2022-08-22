/*
	 [���� 2750] �� �����ϱ�
	  22-08-02 / c++

	  N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
 */

#include<iostream>
using namespace std;

void bubbleSort(int* arr, int size) {
	int tmp;

	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main(void) {
	int N;
	cin >> N;

	int *IntArray = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> IntArray[i];
	}

	bubbleSort(IntArray, N);

	for (int i = 0; i < N; i++) {
		cout << IntArray[i] << endl;
	}

	delete[]IntArray;
	return 0;
	
}