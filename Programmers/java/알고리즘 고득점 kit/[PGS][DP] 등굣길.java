import java.util.*;

class Solution {
    
    public static int MOD_VALUE = 1000000007;
    
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        
        // dp[i][j] : (1, 1)에서 (i, j)까지 도달하는 경로 개수
        int[][] dp = new int[n + 1][m + 1];
        
        // puddle인 곳은 막아야함. 
        // 검사 편의성을 위해 boolean으로 저장
        boolean[][] isBlocked = new boolean[n + 1][m + 1];
        for(int[] pos : puddles) {
            isBlocked[pos[1]][pos[0]] = true;
        }
                
        // x, y로 올 수 있는 경로 개수는, 위에서 내려오는 방법 + 왼쪽에서 오른쪽으로 오는 방법
        // 점화식: dp[x][y] = dp[x - 1][y] + dp[x][y - 1]
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(isBlocked[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 1 && j == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD_VALUE;
            }
        }
        
        // for(int[] arr: dp) {
        //     System.out.println(Arrays.toString(arr));
        // }
        
        return answer = dp[n][m];
    }
}