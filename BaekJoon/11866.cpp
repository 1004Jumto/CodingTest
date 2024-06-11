#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// vars
	vector<int> v, ans;
	int N, K, idx = 0;
	cin >> N >> K;

	// input
	for (int i = 1; i <= N; i++)v.push_back(i);

	while (!v.empty()) {
		idx += K - 1;
		idx %= v.size();
		ans.push_back(v[idx]);
		v.erase(v.begin() + idx);
	}

	// print
	cout << "<";
	for (int i = 0; i < ans.size()-1; i++)cout << ans[i] << ", ";
	cout << ans[ans.size() - 1] << ">";

	return 0;
}