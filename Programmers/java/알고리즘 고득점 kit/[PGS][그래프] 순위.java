import java.util.*;

class Solution {
    public int solution(int n, int[][] results) {

        /*
         * 인사이트: 간접승패 또한 알아야한다. 즉, [a, b], [b, c] 인 경우 [a, c] 도 추가될 수 있다
         * 중간자가 필요한 경우 -> 플로이드 위셜
         * boolean을 활용해 이긴사람 진사람 관계를 표시
         * 중간자를 하나씩 대입해보며 간접 승패를 표시
         * [참고] 플로이드-위셜 사용가능한 곳
            - 모든 노드 쌍
            - A에서 B까지 갈 수 있는가
            - A와 B의 관계를 알 수 있는가
            - 중간 노드를 거쳐서 관계가 생긴다
            - 간접 관계를 모두 구해야 한다
            - n이 그렇게 크지 않다
        */
        
        // 0. 변수 초기화
        int answer = 0; 
        boolean[][] win = new boolean[n + 1][n + 1];
        
        // 1. 직접 승패 기록
        for(int[] result: results) {
            int winner = result[0];
            int loser = result[1];
            
            win[winner][loser] = true;
        }
        
        // 2. 간접 승패 기록
        for(int mid = 1; mid <= n; mid++) {
            for(int winner = 1; winner <= n; winner++) {
                for(int loser = 1; loser <= n; loser++) {
                    if(win[winner][mid] && win[mid][loser]) {
                        win[winner][loser] = true;
                    }
                }
            }
        }
        
        // 3. 1번 선수부터 순위 확정 가능한 선수 탐색
        for(int i = 1;  i <= n; i++) {
            int count = 0;
            
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                
                if(win[i][j] || win[j][i]) count++;
            }
            
            if(count == n - 1) answer++;
        }
       
        
        return answer;
    }
}