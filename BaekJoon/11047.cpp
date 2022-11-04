#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;
	
	int answer = 0;
	vector<int> coin;

	for (int i = 0; i < N; i++) {
		int unit;
		cin >> unit;
		coin.push_back(unit);
	}

	for (int i = coin.size()-1; i >= 0; i--) {
		answer += (K / coin[i]);
		K = K % coin[i];
	}

	cout << answer;

	return 0;	
}