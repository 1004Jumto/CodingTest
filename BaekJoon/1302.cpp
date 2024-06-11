#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// vars
	int N;
	string book;
	map<string, int> m;

	// input
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> book;
		m[book]++;
	}

	// solution
	// ÃÖ´ñ°ª Ã£±â
	int MAX = -1;

	for (auto itr : m) {
		if (itr.second > MAX) {
			MAX = itr.second;
		}
	}

	for (auto itr : m) {
		if (itr.second == MAX) {
			cout << itr.first;
			return 0;
		}
	} 

	return 0;
}