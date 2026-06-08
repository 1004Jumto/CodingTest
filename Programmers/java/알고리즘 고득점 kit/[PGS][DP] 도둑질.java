class Solution {
    public int solution(int[] money) {
        int answer = 0;

        // dp[i] : 0 ~ i번째 집까지 돈을 훔칠 때 돈의 최댓값
        // 원형 -> 일자 배열로 고려해서 생각해야함
        // 이 때, 첫번째와 마지막집에 인접하므로 첫번째 집 포함 유무 기준 두 가지 경우로 나눠야함
        // max(case1, case2)
        // case1은 0 ~ n-2, case2는 1 ~ n-1
        // dp[i] = max(dp[i - 2] + + money[i], dp[i - 1])

        // 집 개수
        int len = money.length;

        // 예외처리
        if (len == 1)
            return money[0];
        if (len == 2)
            return Math.max(money[0], money[1]);

        // 각 경우별 최댓값
        int case1 = getMaxMoney(money, 0, len - 2);
        int case2 = getMaxMoney(money, 1, len - 1);

        answer = Math.max(case1, case2);

        return answer;
    }

    // start, end 범위에서 훔칠 수 있는 돈의 최댓값
    private int getMaxMoney(int[] money, int start, int end) {

        int size = end - start + 1;

        if (size == 1)
            return money[start];

        // i까지 훔친 돈 최댓값
        int[] dp = new int[size];

        dp[0] = money[start];
        dp[1] = Math.max(money[start], money[start + 1]);

        for (int i = 2; i < size; i++) {
            dp[i] = Math.max(dp[i - 2] + money[i + start], dp[i - 1]);
        }

        return dp[size - 1];

    }
}