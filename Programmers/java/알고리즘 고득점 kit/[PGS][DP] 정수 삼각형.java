import java.util.*;

class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        
        // dp[i][j] : 꼭대기에서부터 (i, j)까지 내려왔을 때 최댓값
        int[][] dp = new int[triangle.length][];
        
        // 초기화
        for(int i = 0; i < triangle.length; i++) {
            dp[i] = new int[triangle[i].length];
        }
        
        // 맨 꼭대기 값 초기화 
        dp[0][0] = triangle[0][0];
        
        // dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]
        // i, j 영역 확인
        for(int i = 1; i < triangle.length; i++) {
            for(int j = 0; j < triangle[i].length; j++) {
                // if 맨 왼쪽 줄이거나 맨 오른쪽 줄은 선택지가 하나
                if(j == 0) { 
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if(j == triangle[i].length - 1) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
            }
        }
        
        // for(int[] arr: dp) {
        //     System.out.println(Arrays.toString(arr));
        // }
        
        // 맨 아래 줄 순회하면서 최댓값 탐색
        for(int num : dp[triangle.length - 1]) {
            answer = Math.max(answer, num);
        }
                                                                                                                                                         
        return answer;
    }
}