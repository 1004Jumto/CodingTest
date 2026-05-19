package java11724;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.List;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.StringTokenizer;

/**
 * 그림을 그려보면 여기서 말하는 연결요소는 연결된 덩어리뭉텡이 개수임을 알 수 있음
 * 
 * 연결된 노드를 따라서 visited를 체크
 * 무방향
 * 아래처럼 Map<Integer, List<Integer>> 에 입력받아 놓고,
 * 예제 1)
 * 1 : 2, 5
 * 2 : 1, 5
 * 3 : 4
 * 4 : 3, 6
 * 5 : 1, 2
 * 6 : 4
 * 
 * 처음부터 돌면서 visited를 체크한다.
 * visited = 1, 2, 5 끝 -> 카운트++
 * visited 2 는 이미 방문함
 * visited 3 = 4, 6 끝 -> 카운트++
 * visited 4, 5, 6은 이미 방문함
 * 탐색 종료
 */
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 정점 개수
        int N = Integer.parseInt(st.nextToken());

        // 간선 개수
        int M = Integer.parseInt(st.nextToken());

        // 입력받기
        Map<Integer, List<Integer>> map = new HashMap<>();
        boolean[] visited = new boolean[N + 1];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            // key의 value가 없으면 새로 만들어서 삽입
            map.computeIfAbsent(u, k -> new LinkedList<>()).add(v);
            map.computeIfAbsent(v, k -> new LinkedList<>()).add(u);
        }

        // 정점들을 순회하면서 연결 요소를 카운트
        int count = 0;
        for (int i = 1; i <= N; i++) {
            // 방문 안한 경우
            if (!visited[i]) {
                dfs(i, map, visited);
                count++;
            }
        }

        System.out.println(count);
    }

    private static void dfs(int node, Map<Integer, List<Integer>> graph, boolean[] visited) {
        // 방문한 노드로 표시
        visited[node] = true;

        // 연결된 노드가 하나도 없는 경우
        if (!graph.containsKey(node))
            return;

        // 지금 방문한 노드와 연결된 노드들도 방문
        for (int next : graph.get(node)) {
            if (!visited[next]) {
                dfs(next, graph, visited);
            }
        }
    }

}