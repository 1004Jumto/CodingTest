/*
* [���� 1722] ������ ����
* 1���� N������ ���� ���Ƿ� �迭�� ������ �� N! = N��(N-1)������2��1 ������ �ִ�.

* ������ ������ ������ �� �� �ִ�.
* ���� ���  N=3�� ��� {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}�� ������ ������ �� �ִ�.
* ù ��° ���� ���� ���� �����󿡼� �ռ���, ù ��° ���� ������ �� ��° ���� ���� ����,
* �� ��° ���� ������ �� ��° ���� ���� ���̡�.

* N�� �־�����, �Ʒ��� �� �ҹ��� �߿� �ϳ��� Ǯ��� �Ѵ�.
* k�� �־����� k��° ������ ���ϰ�, ������ ������ �־����� �� ������ �� ��° ���������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

* [�˰���]
* ����Ž�� �˰��� : ������ ��� ����� ���� ���� üũ�� ������ ã�� ���
* �׸���� �ڲ� �򰥸� ���� �ִµ�, �׸���� �� ���� �������� �����ظ� ���� ������ �ش信 �̸��� ����̰�,
* ���� Ž���� ���� ��� �ϳ��ϳ� �� �������� ���
*
*
*/

#include<iostream>	
#include<algorithm>
#include<vector>
#include<string>	

using namespace std;

int cnt = 0;
int k = 0;
int Permutaion_with_visited(int v[], bool visited[], int output[], int depth, int n, int r) {
	if (depth == r) {
		cnt++;
		if (k == cnt) {
			for (int i = 0; i < depth; i++) {
				cout << output[i] << " ";
			}
		}
		return cnt;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] != true) {
			visited[i] = true;
			output[depth] = v[i];
			if(Permutaion_with_visited(v, visited, output, depth + 1, n, r) == k) return k;
			visited[i] = false;
		}
	}
}

int* res;
void Permutaion_with_visited2(int v[], bool visited[], int output[], int depth, int n, int r) {
	if (depth == r) {
		cnt++;
		if (equal(res, res+depth, output)) {
			cout << cnt; return;
		}
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] != true) {
			visited[i] = true;
			output[depth] = v[i];
			Permutaion_with_visited2(v, visited, output, depth + 1, n, r);
			visited[i] = false;
		}
	}
}

int main(void) {
	int N; std::cin >> N;
	int P; cin >> P;
	int* arr = new int[N];
	int* output = new int[N];
	bool* visited = new bool[N];
	res = new int[N];

	// �迭 �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}

	if (P == 1) {		// k��° ���� ���
		cin >> k;
		Permutaion_with_visited(arr, visited, output, 0, N, N);
	}
	else{				// �־��� ������ ���° �������� ���
		for (int i = 0; i < N; i++) {
			int tmp; cin >> tmp;
			res[i] = tmp;
		}
		Permutaion_with_visited2(arr, visited, output, 0, N, N);
	}
	return 0;
}