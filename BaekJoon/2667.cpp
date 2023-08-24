#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#define MAX_SIZE 25

int N;
int graph[MAX_SIZE][MAX_SIZE];
vector<int> apts;
int cnt = 0;	// 단지 내 아파트 수 저장

// 범위를 벗어난 곳에서는 탐색 중지
// 
bool dfs(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) return false;

	if (graph[x][y] != 0) {
		cnt++;
		graph[x][y] = 0;
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 사이즈 입력받고 초기화
	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < N; j++) {
			graph[i][j] = tmp[j] - '0';
		}
	}

	int aptComplex = 0;		// 아파트 단지 수
	// 이차원 배열 원소 하나하나를 돌면서 검사한다. 
	// true면 단지 수 하나를 늘리고, 해당 단지 아파트 수를 저장한다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dfs(i, j)) {
				aptComplex++;
				apts.push_back(cnt);
				cnt = 0;
			}
		}
	}

	// 아파트 수 정렬
	sort(apts.begin(), apts.end());
	cout << aptComplex << "\n";

	for (int n : apts) {
		cout << n << "\n";
	}

	return 0;
}

// lvalue : 이름을 지니는 변수
// rvalue : 임시변수