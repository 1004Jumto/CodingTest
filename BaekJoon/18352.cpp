#include<iostream>
#include<algorithm>
#include<vector>	
#include<queue>

using namespace std;

int N, M, X, K;		//도시 개수, 도로 개수, 거리정보, 출발 도시
vector<int> graph[300001];
bool visited[300001];
vector<int> res;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ K,0 });
	visited[K] = true;

	while (!q.empty()) {
		int current = q.front().first;
		int curDepth = q.front().second;
		q.pop();

		if (curDepth == X) res.push_back(current);
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];

			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, curDepth + 1 });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X >> K;
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
	}

	bfs();

	if (res.size() == 0) {
		cout << -1;
		return 0;
	}
	sort(res.begin(), res.end());
	for (auto a : res) cout << a << "\n";


	return 0;
}