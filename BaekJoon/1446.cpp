#include <iostream>
#include <vector>
using namespace std;


const int INF = 10005;
int N, D;

int from, to, cost;

vector<int> min_(10005, INF);
vector<pair<int, int>> graph[10005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        cin >> from >> to >> cost;
        if (to > D || to - from < cost) continue;
        graph[to].push_back({ from, cost });
    }

    min_[0] = 0;

    for (int i = 1; i <= D; i++) {
        min_[i] = min_[i - 1] + 1;
        for (int j = 0; j < (int)graph[i].size(); j++) {
            min_[i] = min(min_[i], min_[graph[i][j].first] + graph[i][j].second);
        }

    }

    cout << min_[D];

    return 0;
}