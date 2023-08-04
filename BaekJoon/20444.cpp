/*
* [백준 20444] 색종이와 종이
* 오늘도 역시 준성이는 어김없이 색종이와 쿼리를 푸는 데 실패하였다!!
* 색종이에 열등감을 느낀 준성이는 가위로 눈에 보이는 색종이를 모두 잘라 버리려고 한다!!

* 종이를 자를 때는 다음과 같은 규칙을 따른다.
	* 색종이는 직사각형이며, 색종이를 자를 때는 한 변에 평행하게 자른다.
	* 자르기 시작했으면, 경로 상의 모든 색종이를 자를 때까지 멈추지 않는다.
	* 이미 자른 곳을 또 자를 수 없다.

*분노에 찬 가위질을 하던 준성이는 갑자기 하나의 색종이를 정확히 n번의 가위질로 k개의 색종이 조각으로 만들 수 있는지 궁금해졌다.
* 궁금하지만 화가 나서 코딩에 집중할 수 없는 준성이 대신 코드를 작성해주도록 하자.
*
* [알고리즘]
* 이분 탐색/ 매개 변수 탐색
* 32비트 = 4바이트 = int
* 64bit = 8byte = long long
* 
* 
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, k, mid;
	cin >> n >> k;
	long long low = 0; long long high = n / 2;

	while (low <= high) {
		mid = (low + high) / 2;
		long long tmp = (mid + 1) * (n - mid + 1);
		if (tmp == k) {
			cout << "YES"; return 0;
		}
		else if (tmp > k) high = mid - 1;
		else low = mid + 1;
	}
	cout << "NO";

	return 0;
}