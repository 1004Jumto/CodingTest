import java.util.*;

class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // 계단 수
        int N = sc.nextInt();

        // 계단 저장
        int[] steps = new int[N];
        for (int i = 0; i < N; i++) {
            steps[i] = sc.nextInt();
        }

        // 계단이 적게 있는 경우
        if (N == 1)
            System.out.println(steps[0]);
        else if (N == 2)
            System.out.println(steps[0] + steps[1]);
        else {
            // dp : i번째 계단을 올라오기까지 얻을 수 있는 최댓값
            int[] dp = new int[N];

            // 첫 번째, 두 번째, 세 번째 계단은 그대로 초기화
            dp[0] = steps[0];
            dp[1] = steps[1] + dp[0];
            dp[2] = Math.max(dp[0], steps[1]) + steps[2];

            // 네 번째 계단부터 계산
            // i 번째 계단을 올라오는 방법은 두 가지가 있음
            // 1) i - 2 번째 계단을 밟고 두 계단을 올라서 i번째를 밟는 경우
            // 2) i - 3 번째 계단을 밟고 i - 1 번째 계단을 밟고 i를 밟는 경우
            // 이런식으로 해야하는 이유는 연속 세 개의 계단 밟기를 피해야하기 때문
            for (int i = 3; i < N; i++) {
                dp[i] = steps[i] + Math.max(dp[i - 3] + steps[i - 1], dp[i - 2]);
            }

            System.out.println(dp[N - 1]);
        }

    }
}