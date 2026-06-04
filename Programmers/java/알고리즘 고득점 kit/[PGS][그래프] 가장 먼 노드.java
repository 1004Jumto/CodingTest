import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
        
        // 0. 변수 초기화
        int answer = 0; 
        int[] count = new int[n + 1];
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int i = 0; i < edge.length; i++) {
            graph.computeIfAbsent(edge[i][0], g->new ArrayList<>()).add(edge[i][1]);
            graph.computeIfAbsent(edge[i][1], g->new ArrayList<>()).add(edge[i][0]);
        }
        // System.out.println(graph);
        Queue<Integer> queue = new LinkedList<>();
        int[] visited = new int[n + 1]; 
        Arrays.fill(visited, -1);
        
        // 1. 시작점 1 추가
        queue.offer(1);
        visited[1] = 0;
        
        // 2. BFS로 각 노드 거리 저장
        while(!queue.isEmpty()) {
            int cur = queue.poll();   
            // System.out.println("현재 노드=" + cur);
            
            for(int i : graph.get(cur)){
                if(visited[i] == -1) {
                    queue.offer(i); 
                    visited[i] = visited[cur] + 1;
                    count[visited[i]] += 1;
                }
            }
            // System.out.println(queue);
            // System.out.println(Arrays.toString(count));
        } 
        
        // 3. 가장 먼 노드 개수 탐색
        for(int i = 0; i < count.length; i++) {
            if(count[i] != 0) answer = count[i];
        }
        
        return answer;
    }
}