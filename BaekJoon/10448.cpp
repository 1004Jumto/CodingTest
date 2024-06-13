#include<iostream>

using namespace std;

int T(int num) {
	return num * (num + 1) / 2;
}

bool solve(int k) {
	for (int i = 1; i < k; i++) {
		for (int j = 1; j < k; j++) {
			for (int m = 1; m < k; m++) {
				if (T(i) + T(j) + T(m) == k) {
					return true;
				}
			}
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//vars
	int testcase, k;

	//input
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> k;
		if (solve(k)) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}