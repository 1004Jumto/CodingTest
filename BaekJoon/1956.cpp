#include<iostream>
#include<algorithm>
#include<vector>	
#include<queue>

using namespace std;

#define INF 999999
#define MAX 401

int v, e, res = INF;
int graph[MAX][MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			graph[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		int x, y, z; cin >> x >> y >> z;
		graph[x][y] = z;
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
					if (i == j) res = min(res, graph[i][j]);
				}
			}
		}
	}

	cout << (res == INF) ? -1 : res;

	return 0;
}