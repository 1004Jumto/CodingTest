#include <string>
#include <vector>
#include <iostream>
using namespace std;

void moveQueries(int row, int col, int& a, int& b, vector<vector<int>> query) {
    // ������� �����̱�
    for (int i = 0; i < query.size(); i++) {
        if (query[i][0] == 0) {  // ��������
            if ((b - query[i][1]) >= 0) {
                b = b - query[i][1];
            }
        }
        else if (query[i][0] == 1) {
            if ((b + query[i][1]) <= col) {
                b = b + query[i][1];
            }
        }
        else if (query[i][0] == 2) {
            if ((a - query[i][1]) >= 0) {
                a = a - query[i][1];
            }
        }
        else if (query[i][0] == 3) {
            if ((a + query[i][1]) <= row) {
                a = a + query[i][1];
            }
        }
    }
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;

    // ���� �� ó������ ��� ����
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // ������� ������ �� ��ġ�� �����ϴ� �Լ�(������, ����)
            int start = i, end = j;

            moveQueries(n, m, start, end, queries);
            if (x == start && y == end) {
                if (answer == -1) {
                    answer = 1;
                }
                else {
                    answer++;
                }
            }
        }
    }
    return answer;
}

int main(void) {
    int n = 2;
    int m = 2;
    int x = 0;
    int y = 0;

    vector<vector<int>> tmp = { {2,1} ,{0,1},{1,1},{0,1},{2,1} };

    cout << solution(n, m, x, y, tmp);

    return 0;
}