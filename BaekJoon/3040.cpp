#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// vars
	vector<int> v;
	int a, b, sum = 0;

	// input
	for (int i = 0; i < 9; i++) {
		int tmp; 
		cin >> tmp;
		v.push_back(tmp);
		sum += tmp;
	}

	// solution
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (sum - v[i] - v[j] == 100) {
				a = i; b = j;
			}
		}
	}

	// print
	for (int i = 0; i < v.size(); i++) {
		if (i == a || i == b) continue;
		cout << v[i] << "\n";
	}

	return 0;
}