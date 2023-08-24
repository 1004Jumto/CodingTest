#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#define MAX_SIZE 25

int N;
int graph[MAX_SIZE][MAX_SIZE];
vector<int> apts;
int cnt = 0;	// ���� �� ����Ʈ �� ����

// ������ ��� �������� Ž�� ����
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

	// ������ �Է¹ް� �ʱ�ȭ
	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < N; j++) {
			graph[i][j] = tmp[j] - '0';
		}
	}

	int aptComplex = 0;		// ����Ʈ ���� ��
	// ������ �迭 ���� �ϳ��ϳ��� ���鼭 �˻��Ѵ�. 
	// true�� ���� �� �ϳ��� �ø���, �ش� ���� ����Ʈ ���� �����Ѵ�.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dfs(i, j)) {
				aptComplex++;
				apts.push_back(cnt);
				cnt = 0;
			}
		}
	}

	// ����Ʈ �� ����
	sort(apts.begin(), apts.end());
	cout << aptComplex << "\n";

	for (int n : apts) {
		cout << n << "\n";
	}

	return 0;
}

// lvalue : �̸��� ���ϴ� ����
// rvalue : �ӽú���