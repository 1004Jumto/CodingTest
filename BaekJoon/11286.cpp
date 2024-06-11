#include<iostream>
#include<queue>
#include<functional>

using namespace std;

struct cmp {
	bool operator()(int root, int sub) {
		if (abs(root) == abs(sub)) return root > sub;
		return abs(root) > abs(sub);
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// var
	int N, x; 
	priority_queue<int, vector<int>, cmp> minHeap;

	// input
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		
		// solution
		if (x == 0) {
			if (minHeap.empty()) cout << "0\n";
			else {
				cout << minHeap.top() << "\n";
				minHeap.pop();
			}
		}
		else {
			minHeap.push(x);
		}
	}

	// print

	return 0;
}