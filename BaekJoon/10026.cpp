/*
* [백준 10026] 적록색약
* 적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 
* 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

* 크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 
* 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 
* 또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. 
* (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

* 예를 들어, 그림이 아래와 같은 경우에
	RRRBB
	GGBBB
	BBBRR
	BBRRR
	RRRRR

* 적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 
* 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)

* 그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

* [알고리즘]
* 깊이 우선 탐색
*
* 
*/

#include<iostream>
#include<algorithm>
#include<vector>	
#include<stack>
#include<queue>

using namespace std;

#define MAX 100

int N;
char graph1[MAX][MAX];
char graph2[MAX][MAX];
int res1 = 0, res2 = 0;
char current;

bool dfs(int x, int y) {
	if (x >= N || x < 0 || y < 0 || y >= N)return false;
	if (graph1[x][y] == current) {
		graph1[x][y] = 'X';
		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

bool dfs2(int x, int y) {
	if (x >= N || x < 0 || y < 0 || y >= N)return false;
	if (graph2[x][y] == current) {
		graph2[x][y] = 'X';
		dfs2(x + 1, y);
		dfs2(x - 1, y);
		dfs2(x, y - 1);
		dfs2(x, y + 1);
		return true;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < N; j++) {
			graph1[i][j] = tmp[j];
			graph2[i][j] = tmp[j];
		}
	}


	// 적록색약 x
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph1[i][j] != 'X') current = graph1[i][j];
			else continue;
			if (dfs(i, j)) res1++;
		}
	}

	// 적록색약 o 
	// R을 G로 바꾸고 다시 dfs로 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph2[i][j] == 'R') graph2[i][j] = 'G';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph2[i][j] != 'X') current = graph2[i][j];
			else continue;
			if (dfs2(i, j)) res2++;
		}
	}

	cout << res1 << " " << res2;

	return 0;
}