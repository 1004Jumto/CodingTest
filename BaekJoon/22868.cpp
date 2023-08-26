#include<iostream>
#include<algorithm>
#include<vector>	
#include<queue>

using namespace std;
#define START 1
int res = 0;
int computer, edge;

void bfs(int start, vector<int> graph[], bool visited[]) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < graph[current].size(); i++) {
			if (!visited[graph[current][i]]) {
				q.push(graph[current][i]);
				res++;
				visited[graph[current][i]] = true;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> computer >> edge;
	vector<int>* graph = new vector<int>[computer + 1];
	bool* visited = new bool[computer + 1];
	fill_n(visited, computer, false);

	for (int i = 0; i < edge; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bfs(START, graph, visited);
	cout << res;

	return 0;
}