import java.util.Queue;
import java.util.LinkedList;

// 시간·공간 복잡도 모두 O(N×M)
class Solution {

    // 상,하,좌,우 이동할 수 있는 좌표 배열
    int[] dx = { -1, 1, 0, 0 };
    int[] dy = { 0, 0, -1, 1 };

    public int solution(int[][] maps) {
        int answer = -1;

        // 방문 유무 및 거리 기록
        int[][] visited = new int[maps.length][maps[0].length];

        // BFS 탐색 : 비가중치 최단거리 탐색에 유용
        BFS(maps, visited, 0, 0);

        // 최단 거리
        answer = visited[maps.length - 1][maps[0].length - 1];

        // 0 이면 -1 리턴
        answer = answer != 0 ? answer : -1;

        return answer;
    }

    private void BFS(int[][] graph, int[][] visited, int x, int y) {
        Queue<int[]> q = new LinkedList<>();

        // 방문한 노드 처리
        visited[x][y] = 1;

        // queue에 노드 삽입
        q.offer(new int[] { x, y });

        // 큐가 빌 때까지 탐색 반복
        while (!q.isEmpty()) {
            // 탐색할 좌표를 pop
            int[] cur = q.poll();

            // 좌표와 연결된 상,하,좌,우 모두 탐색
            for (int i = 0; i < 4; i++) {

                // 다음 탐색할 노드
                int[] next = new int[] { cur[0] + dx[i], cur[1] + dy[i] };

                // 범위 벗어나면 continue
                if (next[0] > graph.length - 1 || next[1] > graph[0].length - 1 || next[0] < 0 || next[1] < 0) {
                    continue;
                }

                // 다음 노드가 아직 탐색하지 않은 노드이고, 벽이 아닌 길인 경우만 탐색
                if (visited[next[0]][next[1]] == 0 && graph[next[0]][next[1]] == 1) {
                    visited[next[0]][next[1]] = visited[cur[0]][cur[1]] + 1;
                    q.offer(new int[] { next[0], next[1] });
                }
            }

        }

    }
}