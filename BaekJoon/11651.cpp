#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> dot;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		dot.push_back(make_pair(y, x));
	}

	sort(dot.begin(), dot.end());

	for (int i = 0; i < N; i++) {
		cout << dot[i].second << " " << dot[i].first << "\n";
	}

	return 0;
}