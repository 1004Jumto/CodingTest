/*
	 [백준 2750] 수 정렬하기
	  22-08-02 / c++

	  N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
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