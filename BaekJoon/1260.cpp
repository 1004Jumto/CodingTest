/*
* [백준 1260] DFS와 BFS
* 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.
* 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
* 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

* [알고리즘]
* 깊이 우선 탐색, 너비 우선 탐색
* 
* 깊이 우선 탐색은 재귀 혹은 스택으로 구현할 수 있다.
* 너비 우선 탐색은 큐를 써서 구현할 수 있다.
*
*/

#include<iostream>
#include<algorithm>
#include<vector>	
#include<stack>
#include<queue>

using namespace std;

int N, E, V;	// 정점 개수, 간선 개수, 시작 정점 번호

void dfs(int start, vector<int> graph[], bool visited[]) {
	stack<int> s;
	s.push(start);
	visited[start] = true;
	cout << start << " ";

	while (!s.empty()) {
		int currentNode = s.top();
		s.pop();

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextNode = graph[currentNode][i];
			if (!visited[nextNode]) {
				cout << nextNode << " ";
				visited[nextNode] = true;
				s.push(currentNode);
				s.push(nextNode);
				break;
			}
		}
	}
}

void dfs_recursion(int start, vector<int> graph[], bool visited[]) {
	visited[start] = true;
	cout << start << " ";
	
	for (int i = 0; i < graph[start].size(); i++) {
		int nextNode = graph[start][i];

		if (!visited[nextNode]) dfs(nextNode, graph, visited);
	}

}

void bfs(int start, vector<int> graph[], bool visited[]) {
	queue<int> q;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int top = q.front();
		q.pop();
		cout << top << " ";

		for (int i = 0; i < graph[top].size(); i++) {
			if (!visited[graph[top][i]]) {
				q.push(graph[top][i]);
				visited[graph[top][i]] = true;
			}
		}
	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E >> V;
	vector<int>* graph = new vector<int>[N + 1];	// 그래프 선언
	bool* visited = new bool[N + 1];				// 방문 유무 저장하는 배열 선언 및 초기화
	fill_n(visited, N + 1, false);

	// 그래프 입력받기
	for (int i = 0; i < E; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// 순차적 접근을 위해 정렬
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V, graph, visited);
	cout << "\n";

	fill_n(visited, N + 1, false);
	bfs(V, graph, visited);

	return 0;
}