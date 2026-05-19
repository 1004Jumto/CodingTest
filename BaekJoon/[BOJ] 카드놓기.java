import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 카드 개수
        int N = Integer.parseInt(sc.nextLine());

        // 선택할 카드 개수
        int K = Integer.parseInt(sc.nextLine());

        // 조합한 정수를 저장할 set
        Set<Integer> set = new HashSet<>();

        // 카드 입력받아서 배열에 저장
        String[] cards = new String[N];
        for (int i = 0; i < N; i++) {
            cards[i] = sc.nextLine();
        }

        // 만들 수 있는 정수 탐색
        dfs(cards, K, new boolean[N], 0, "", set);

        System.out.println(set.size());
    }

    // nums 배열의 정수들 중에서 k개를 골라 조합한 정수를 result에 저장
    // 조합
    private static void dfs(String[] nums, int k, boolean[] used, int depth, String num, Set<Integer> result) {
        // k개를 선택했다면 숫자 저장
        if (k == depth) {
            result.add(Integer.parseInt(num));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (!used[i]) {
                used[i] = true;
                dfs(nums, k, used, depth + 1, num + nums[i], result);
                used[i] = false;
            }
        }
    }
}