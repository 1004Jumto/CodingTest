package java18352;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 도시 개수
        int N = Integer.parseInt(st.nextToken());

        // 도로 개수
        int M = Integer.parseInt(st.nextToken());

        // 거리 정보(최단거리)
        int K = Integer.parseInt(st.nextToken());

        // 출발 도시 번호
        int X = Integer.parseInt(st.nextToken());

        // 도시 맵
        List<Integer>[] graph = new ArrayList[N + 1];
        // 맵 초기화
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        // 맵 입력받기
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int e = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            graph[e].add(v);
        }

        // 다익스트라 최단 거리 탐색
        // visited 는 방문, dist는 거리배열
        // 거리가 짧은 순으로 방문 탐색
        // 연결된 노드와의 거리 갱신
        // 모든 노드를 방문할 때까지 반복
        // 이 때, 음수 가중치가 있으면 더 짧은 경로가 생길 수 있어 벨만-포드 알고리즘을 사용한다
        // 시간복잡도는 배열기반 O(V^2), 우선순위큐 O(ElogV)
        searchCity(graph, K, X);

    }

    /**
     * start에서 시작해 dest 거리의 정점을 모두 출력하는 함수
     * 
     * @param graph 간선 노드 그래프
     * @param dest  목표거리
     * @param start 시작정점
     */

    private static void searchCity(List<Integer>[] graph, int targetDist, int start) {

        // dist[i] = start -> i 최단거리
        int[] dist = new int[graph.length];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        // pq: {정점, 거리}
        PriorityQueue<int[]> pq = new PriorityQueue<>(
                (a, b) -> a[1] - b[1]);

        pq.offer(new int[] { start, 0 });

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int now = cur[0];
            int nowDist = cur[1];

            // 이미 더 짧은 경로가 있으면 무시
            if (nowDist > dist[now])
                continue;

            for (int next : graph[now]) {
                int nextDist = nowDist + 1;
                if (dist[next] > nextDist) {
                    dist[next] = nextDist;
                    pq.offer(new int[] { next, nextDist });
                }
            }
        }

        boolean found = false;
        for (int i = 1; i < dist.length; i++) {
            if (dist[i] == targetDist) {
                System.out.println(i);
                found = true;
            }
        }

        if (!found)
            System.out.println(-1);
    }
    /*
     * private static void searchCity(List<Integer>[] graph, int dest, int start) {
     * 
     * // 다익스트라 우선순위 큐
     * Queue<Integer> pq = new LinkedList<>();
     * 
     * // 방문 유무
     * boolean[] visited = new boolean[graph.length];
     * 
     * // 정점 거리
     * int[] dist = new int[graph.length];
     * // 거리 초기화
     * Arrays.fill(dist, Integer.MAX_VALUE);
     * dist[start] = 0;
     * 
     * // 우선순위 큐에 삽입
     * pq.offer(start);
     * 
     * while (!pq.isEmpty()) {
     * int cur = pq.poll();
     * 
     * if (!visited[cur]) {
     * // 방문처리
     * visited[cur] = true;
     * 
     * // 해당 노드와 연결된 노드 거리 갱신
     * for (int node : graph[cur]) {
     * dist[node] = Math.min(dist[node], dist[cur] + 1);
     * pq.offer(node);
     * }
     * }
     * }
     * 
     * // 출력
     * int count = 0;
     * for (int i = 0; i < dist.length; i++) {
     * if (dist[i] == dest) {
     * count++;
     * System.out.println(i);
     * }
     * }
     * 
     * if(count == 0) System.out.println(-1);
     * 
     * }
     */
}
