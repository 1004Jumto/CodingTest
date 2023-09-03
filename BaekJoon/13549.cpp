/*
* 2배를 먼저
* n보다 작으면 무조건 -1
* 그 후 +1
*/

#include<iostream>
#include<algorithm>
#include<vector>	
#include<queue>

using namespace std;

int from, to;
int res = 0;
int visited[100001];
queue<int> q;

void bfs() {
	q.push(from);
	visited[from] = 0;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == to) {
			res = visited[current];
			return;
		}
		if (current * 2 < 100001 && visited[current * 2] > visited[current]) {
			visited[current * 2] = visited[current];
			q.push(current * 2);
		}
		if (current + 1 < 100001 && visited[current + 1] > visited[current] + 1) {
			visited[current + 1] = visited[current] + 1;
			q.push(current + 1);
		}
		if (current - 1 >= 0 && visited[current - 1] > visited[current] + 1) {
			visited[current - 1] = visited[current] + 1;
			q.push(current - 1);
		}

	}

}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> from >> to;
	for (int i = 0; i < 100001; i++)visited[i] = 1000000;
	
	bfs();
	cout << res;
	return 0;
}