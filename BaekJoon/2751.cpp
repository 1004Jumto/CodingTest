/*
	 [백준 2751] 수 정렬하기2
	  22-08-02 / c++

	  N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
	  시간복잡도가 O(nlogn)인 정렬 사용하기
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