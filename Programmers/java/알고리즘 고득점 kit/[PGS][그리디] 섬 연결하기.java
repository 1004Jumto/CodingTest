import java.util.*;

class Solution {
    public int solution(int n, int[][] costs) {

        /*
         * 1. 비용 기준으로 다리 정렬
         * 2. 싼 다리부터 확인
         * 3. 두 섬이 아직 연결되어 있지 않으면 선택
         * 4. Union-Find로 연결 상태 관리
         * 5. n - 1개의 다리를 선택하면 종료
        */
        
        // 0. 변수 초기화
        int answer = 0;
        int edgeCnt = 0;
        int[] parent = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        // 1. 비용 기준으로 오름차순
        Arrays.sort(costs, (a, b) -> a[2] - b[2]);
        
        // 2. 다리 탐색
        for(int[] cost: costs) {
            int dept = cost[0];
            int dest = cost[1];
            int price = cost[2];
            
            // 사이클 발생 유무 확인
            if(find(parent, dept) != find(parent, dest)) {
                
                // 사이클 발생안하면 다리 선택
                union(parent, dept, dest);
                answer += price;
                edgeCnt++;
            }
            
            // 다리를 모두 고르면 그만
            if(edgeCnt == n - 1) {
                break;
            }
        }
        
        return answer;
        
    }
    
    // 이미 같은 그룹인지(사이클 유무 확인)
    static int find(int[] parent, int x) {
        if(parent[x] == x) {
            return x;
        }
        
        return parent[x] = find(parent, parent[x]);
    }
    
    // 다리 합침
    static void union(int[] parent, int x, int y) {
        int rootA = find(parent, x);
        int rootB = find(parent, y);
        
        if(rootA != rootB) {
            parent[rootB] = rootA;
        }
    }
}