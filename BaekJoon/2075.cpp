#include<iostream>
#include<queue> 
#include<functional>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// vars
	priority_queue<int, vector<int>, cmp> minHeap;
	int N;

	// input
	cin >> N;

	for (int i = 0; i < N*N; i++) {
		int tmp; cin >> tmp;
		minHeap.push(tmp);
		if (minHeap.size() > N) {
			minHeap.pop();
		}
	}

	// print
	cout << minHeap.top();

	return 0;
}