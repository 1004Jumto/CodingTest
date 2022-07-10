#include<iostream>
using namespace std;

int main() {
	// Baekjoon 2588
	int x, y;
	cin >> x;
	cin >> y;

	cout.unsetf(ios::fixed);
	int digit, ten_digit, hundred_digit;
	hundred_digit = x * (y / 100);

	y = y % 100;
	ten_digit = x * (y / 10);

	y = y % 10;
	digit = x * y;

	int res = digit + ten_digit * 10 + hundred_digit * 100;

	cout << digit << endl;
	cout << ten_digit << endl;
	cout << hundred_digit << endl;
	cout << res;



}