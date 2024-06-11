#include<iostream> 
#include<deque>

using namespace std;
  
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// vars 
	int N, ans;
	deque<int> dq;

	// input 
	cin >> N;
	for (int i = 1; i <= N; i++)dq.push_back(i);

	// solution
	while (dq.size() > 1) {
		dq.pop_front();
		dq.push_back(dq.front());
		dq.pop_front();
	}

	// print 
	cout << dq.front();

	return 0;
}
 