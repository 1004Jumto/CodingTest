import java.util.*;

class Solution {
    public int solution(int n, int[][] wires) {
        int answer = Integer.MAX_VALUE;
        
        // 그래프 초기화
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int i = 0; i < wires.length; i++){
            graph.computeIfAbsent(wires[i][0], g -> new ArrayList<>()).add(wires[i][1]);
            graph.computeIfAbsent(wires[i][1], g -> new ArrayList<>()).add(wires[i][0]);
        } 
        
        // 탐색, 간선 하나씩 끊어서 탐색
        // bfs(graph, new boolean[n + 1], 1);
        for(int[] wire : wires) {
            // 1. 간선 삭제
            graph.get(wire[0]).remove(Integer.valueOf(wire[1]));     // 이 때, remove(0)는 0번째 요소 삭제
            graph.get(wire[1]).remove(Integer.valueOf(wire[0]));     // 따라서, remove(Object o)로 써야 특정 요소 삭제 가능 
            // 2. dfs 탐색 및 탐색한 노드 개수 반환
            int count = dfs(graph, new boolean[n + 1], 1);
            
            // 3. 절대값 계산 및 정답 업데이트
            answer = Math.min(answer, Math.abs(2 * count - n));
            
            // 4. 그래프 복구
            graph.get(wire[0]).add(wire[1]);
            graph.get(wire[1]).add(wire[0]); 
        }
        
        return answer;
    }

    
    private int dfs(Map<Integer, List<Integer>> graph, boolean[] visited, int node) {
        int count = 1;
        
        if(!visited[node]) visited[node] = true;
        
        for(int next : graph.get(node)) {
            if(!visited[next]) {  
                count += dfs(graph, visited, next);  
            }
        }
        
        return count;
    }
    
    
    
        
    private void bfs(Map<Integer, List<Integer>> graph, boolean[] visited, int start) { 
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);
        visited[start] = true;
        
        while(!queue.isEmpty()) {
            int cur = queue.poll();
            
            for(int next : graph.get(cur)) {
                if(!visited[next]) {
                    visited[next] = true;
                    queue.offer(next);
                }
            }
            
            System.out.println(queue);
        }
        
    }
}