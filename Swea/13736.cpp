/*
	13736번 : 사탕분배
	언어 : C++
	알고리즘)
		1. 일단 테스트케이스 입력받고 -> for문으로 돌릴것
		2. a,b,l 입력받고
		3. for문으로 l번 돌린다
		4. X = 2X, Y = Y-X 한 후 두수 크기 비교
		5. min(); 출력
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