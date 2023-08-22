/*
* [���� 1260] DFS�� BFS
* �׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
* ��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, 
* �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�.

* [�˰���]
* ���� �켱 Ž��, �ʺ� �켱 Ž��
* 
* ���� �켱 Ž���� ��� Ȥ�� �������� ������ �� �ִ�.
* �ʺ� �켱 Ž���� ť�� �Ἥ ������ �� �ִ�.
*
*/

#include<iostream>
#include<algorithm>
#include<vector>	
#include<stack>
#include<queue>

using namespace std;

int N, E, V;	// ���� ����, ���� ����, ���� ���� ��ȣ

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
	vector<int>* graph = new vector<int>[N + 1];	// �׷��� ����
	bool* visited = new bool[N + 1];				// �湮 ���� �����ϴ� �迭 ���� �� �ʱ�ȭ
	fill_n(visited, N + 1, false);

	// �׷��� �Է¹ޱ�
	for (int i = 0; i < E; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// ������ ������ ���� ����
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V, graph, visited);
	cout << "\n";

	fill_n(visited, N + 1, false);
	bfs(V, graph, visited);

	return 0;
}