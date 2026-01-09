package java11725;

import java.io.BufferedReader; 
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());

        // 그래프
        List<Integer>[] tree = new ArrayList[N + 1];
        // 그래프 초기화
        for (int i = 0; i <= N; i++) {
            tree[i] = new ArrayList<>();
        }

        // 노드 입력받기
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int parent = Integer.parseInt(st.nextToken());
            int child = Integer.parseInt(st.nextToken());

            tree[parent].add(child);
            tree[child].add(parent);
        }

        // for(List<Integer> list : tree){
        // System.out.println(list);
        // }

        // 각 노드의 부모 노드 저장 배열
        int[] answer = new int[N + 1];

        // 각 노드의 부모 노드 저장
        dfs(tree, new boolean[N + 1], 1, answer);

        for (int i = 2; i <= N; i++) {
            System.out.println(answer[i]);
        }

    }

    private static void dfs(List<Integer>[] graph, boolean[] visited, int node, int[] answer) {
        // 이미 방문한 노드인 경우
        if (visited[node])
            return;

        // 노드 방문 처리
        visited[node] = true;

        // 연결된 노드 방문
        for (int next : graph[node]) {
            if (!visited[next]) {
                answer[next] = node;
                dfs(graph, visited, next, answer);
            }
        }

    }

}
