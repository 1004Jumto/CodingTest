#include<iostream>
using namespace std;

/*
 설탕봉지 최소 개수를 구해야 함!

 일단 N을 5로 나눈다 (몫은 m) -> 나머지는 0,1,2,3,4
 나머지 0인 경우 : 문제 없음
 나머지 1인 경우 : 5키로 짜리는 m-1개, 6키로 남았으므로 3키로짜리 두개 추가
 나머지 2인 경우 : 5키로짜리는 m-1개라 하면, 7키로 남는데 3의 배수 아니니깐
				   5키로짜리 m-2개, 그러면 12키로 남으므로 3키로짜리 4개 추가됨
 나머지 3인 경우 : 5키로짜리 m개, 3키로짜리 한개 추가
 나머지 4인 경우 : 5키로짜리 m-1개, 9키로 남으니까 3키로짜리 세개 추가
*/

int TOTAL;

int main() {
	int N;
	int Kg_5;
	int rem;

	cin >> N;		//일단 키로 입력받고
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