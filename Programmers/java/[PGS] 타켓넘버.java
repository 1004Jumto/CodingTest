class Solution {
    int answer = 0;
    
    public int solution(int[] numbers, int target) {
        
        // DFS로 모든 경우의 수 탐색
        DFS(numbers, target, 0, 0);
        
        return answer;
    }
    
    private void DFS(int[] graph, int target, int sum, int depth){
        // 끝까지 탐색했고, 합이 target과 같으면 answer++
        if(depth == graph.length){
            if(sum == target) answer++;
            return;
        }
        
        // + 인 경우
        DFS(graph, target, sum + graph[depth], depth + 1);
        
        // - 인 경우
        DFS(graph, target, sum - graph[depth], depth + 1);
        
    }
}