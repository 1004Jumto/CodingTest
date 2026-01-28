#include <string>
#include <vector>
#include <iostream>
using namespace std;

void moveQueries(int row, int col, int& a, int& b, vector<vector<int>> query) {
    // 쿼리대로 움직이기
    for (int i = 0; i < query.size(); i++) {
        if (query[i][0] == 0) {  // 왼쪽으로
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

    // 격자 판 처음부터 경우 시작
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // 쿼리대로 움직인 후 위치를 리턴하는 함수(시작점, 쿼리)
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