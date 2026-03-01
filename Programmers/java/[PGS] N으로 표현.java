import java.util.*;

class Solution {
    public int solution(int N, int number) {
        int answer = -1;
        /*
         * dp[k] : N을 k번 사용해서 만들 수 있는 모든 정수 값들의 집합(Set)
         * 예시
         * dp[1] = {5}
         * 
         * dp[2]는
         * - 붙여쓰기: 55
         * - dp[1]과 dp[1] 조합: 5+5=10, 5-5=0, 5*5=25, 5/5=1
         * → dp[2] = {55, 10, 0, 25, 1}
         * 
         * dp[3]는
         * - 555
         * - dp[1] + dp[2], dp[2] + dp[1]
         * 
         */

        // dp[k] : N을 k번 사용해서 만들 수 있는 모든 정수 값들의 집합(Set)
        // dp 초기화
        Set<Integer>[] dp = new HashSet[10];
        for (int i = 0; i < 10; i++) {
            dp[i] = new HashSet<>();
        }

        dp[0].add(0);

        for (int i = 1; i < 10; i++) {

            // 붙여쓰기
            // 순수하게 N을 i번 연속으로 붙여서 만들 수 있는 수를 추가
            // 예를 들면, N = 5 i = 4 라고 했을 때, 55555를 추가
            dp[i].add(Integer.parseInt(String.valueOf(N).repeat(i)));

            // dp[j] 와 dp[i-j] 조합
            for (int j = 1; j < i; j++) {
                for (int num1 : dp[j]) {
                    for (int num2 : dp[i - j]) {
                        dp[i].add(num1 + num2);
                        dp[i].add(num1 - num2);
                        dp[i].add(num1 * num2);
                        if (num2 != 0)
                            dp[i].add(num1 / num2);
                    }
                }
            }

            if (dp[i].contains(number))
                return i;
        }

        return answer;
    }
}