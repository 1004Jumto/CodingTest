package java;
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int solution(String numbers) {
        int answer = 0;

        // 숫자 배열로 변환
        int[] nums = numbers.chars().map(c -> c - '0').toArray();

        // 만든 숫자를 저장
        Set<Integer> set = new HashSet<>();

        // 완전 탐색
        dfs(nums, new boolean[nums.length], set, 0);

        // 저장된 숫자가 소수인지 판별
        for (int num : set) {
            if (isPrime(num))
                answer++;
        }

        return answer;
    }

    private void dfs(int[] nums, boolean[] visited, Set<Integer> set, int value) {
        set.add(value);

        for (int i = 0; i < nums.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(nums, visited, set, value * 10 + nums[i]);
                visited[i] = false;
            }
        }

    }

    private boolean isPrime(int num) {
        if (num < 2)
            return false;
        if (num == 2 || num == 3)
            return true;

        if (num % 2 == 0)
            return false;

        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0)
                return false;
        }

        return true;
    }
}