#include<iostream>	
#include<string>	
#include<vector>

using namespace std;

int main(void) {

	string str;
	cin >> str;
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - i - 1]) {
			cout << 0; return 0;
		}
	}
	cout << 1; return 0;
}	