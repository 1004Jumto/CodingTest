import java.util.*;

class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;

        // 1. 그래프 선언 및 초기화
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i <= n; i++) {
            graph.put(i, new ArrayList<>());

            // i = 0인 경우는 존재하지 않으므로 continue
            if (i == 0)
                continue;

            for (int j = 1; j <= n; j++) {
                if (i == j)
                    continue; // 자기 자신인 경우
                if (computers[i - 1][j - 1] == 1)
                    graph.get(i).add(j);
            }
        }
        System.out.println(graph);

        // 2. DFS 탐색, visited가 모두 true가 될 때까지 탐색
        boolean[] visited = new boolean[n + 1];

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                answer++;
                dfs(graph, visited, i);
            }
        }

        return answer;
    }

    private void dfs(Map<Integer, List<Integer>> graph, boolean[] visited, int node) {
        visited[node] = true;

        for (int next : graph.get(node)) {
            if (!visited[next]) {
                dfs(graph, visited, next);
            }
        }
    }

}