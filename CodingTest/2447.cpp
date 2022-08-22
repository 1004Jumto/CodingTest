/*
	 [백준 2447] 별찍기-10
	  22-08-04 / c++

	  < 문제 >

	  

	  < 알고리즘 >

	  c

 */

#include<iostream>

using namespace std;
/*
+++
+ +
+++
*/
void PointStar(int N) {
	if (N == 3) {
		cout << "***" << "\n";
		cout << "* *" << "\n";
		cout << "***";
	}

	if (N != 3) {
		for (int i = 0; i < N / 3; i++) {
			for (int k = 0; k < N; k++) {
				PointStar(N / 3);
			}
		}
		cout << "\n";

		for (int i = 0; i < N / 3; i++) {
			for (int k = 0; k < N / 3; k++) {
				PointStar(N / 3);
			}
			for (int k = 0; k < N / 3; k++) {
				cout << " ";
			}
			for (int k = 0; k < N / 3; k++) {
				PointStar(N / 3);
			}
		}
		cout << "\n";

		for (int i = 0; i < N / 3; i++) {
			for (int k = 0; k < N; k++) {
				PointStar(N / 3);
			}

		}

	}

}

int main(void) {
	int N;
	cin >> N;

	PointStar(N);
	return 0;

}