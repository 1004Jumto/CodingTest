import java.util.*;

class Solution {
    public int solution(String arr[]) {

        /*
         * 연산자 기준으로 분리해서 생각
         * dp[i][j]는 i부터 j구간에서의 최댓값/최솟값
         * + : 왼쪽구간 최댓값 + 오른쪽 최댓값 / 왼쪽구간 최솟값 + 오른쪽 최솟값
         * - : 왼쪽구간 최댓값 - 오른쪽 최솟값 / 왼쪽구간 최솟값 - 오른쪽 최댓값
        */
        
        // 0. 변수 초기화
        int answer = -1; 
        int n = (arr.length + 1) / 2;
        
        int[] nums = new int[n];
        String[] ops = new String[n - 1];
        for(int i = 0; i < arr.length; i++) {
            if(i % 2 == 0) {
                nums[i / 2] = Integer.parseInt(arr[i]);
            }
            else {
                ops[i / 2] = arr[i];
            }
        } 
        
        int[][] dpMax = new int[n][n];
        int[][] dpMin = new int[n][n];
        for(int i = 0; i < n; i++) {
            Arrays.fill(dpMax[i], Integer.MIN_VALUE);
            Arrays.fill(dpMin[i], Integer.MAX_VALUE);
        }
        for(int i = 0; i < n; i++) {    // i번째 하나만 선택되는 경우는 그 숫자 그대로
            dpMax[i][i] = nums[i];
            dpMin[i][i] = nums[i];
        }
        
        // 1. 구간의 길이 별로 계산
        for(int len = 2; len <= n; len++) {
            for(int start = 0; start <= n - len; start++) {
                int end = start + len - 1;
                
                // [start, end] 구간을 mid 기준으로 왼쪽 오른쪽 분리
                for(int mid = start; mid < end; mid++) {
                    String op = ops[mid];
                    
                    if(op.equals("+")) {
                        int maxNum = dpMax[start][mid] + dpMax[mid + 1][end];
                        int minNum = dpMin[start][mid] + dpMin[mid + 1][end];
                        
                        dpMax[start][end] = Math.max(dpMax[start][end], maxNum);
                        dpMin[start][end] = Math.min(dpMin[start][end], minNum);
                    }
                    else {
                        int maxNum = dpMax[start][mid] - dpMin[mid + 1][end];
                        int minNum = dpMin[start][mid] - dpMax[mid + 1][end];
                        
                        dpMax[start][end] = Math.max(dpMax[start][end], maxNum);
                        dpMin[start][end] = Math.min(dpMin[start][end], minNum);    
                    }
                }
            }
        }
         
        // 0부터 끝까지 전체 구간의 최댓값
        return answer = dpMax[0][n - 1];
    }
}