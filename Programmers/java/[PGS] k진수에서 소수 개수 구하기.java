package java;

// 1. 아라토스테네스의 체를 사용해서 소수 판별
// 2. 진법 변환 내장 함수 사용
// - 10진법 -> k진법 : Integer.toString(s, k)
// - k진법 -> 10진법 : Integer.parseInt(s, k)
import java.util.Arrays;

class Solution {

    private boolean[] isPrime;

    public int solution(int n, int k) {
        int answer = 0;

        // 소수 판별 배열 초기화 -> 이렇게 푸는 거 아님
        // init(1000000000);

        // n을 k진수로 변환
        String snum = Integer.toString(n, k);
        // System.out.println(snum);

        // string으로 변환 후 split("0")
        String[] sarr = snum.split("0");
        // System.out.println(Arrays.toString(sarr));

        // sarr을 순회하면서 소수인지 판별
        for (String s : sarr) {
            if (s.isBlank()) continue;

            long num = Long.parseLong(s);
            // System.out.println(num + ":" + isPrime[num]);
            
            if (isPrimeNum(num)) answer++;
        }

        return answer;
    }

    // 그냥 소수 판별
    private boolean isPrimeNum(long num) {
        if (num < 2) return false;

        if (num == 2) return true;
        if (num == 3) return true;

        if (num % 2 == 0) return false;

        for (long i = 3; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // 에라토스테네스의 체를 사용하여 소수 판별
    private void init(int len) {
        isPrime = new boolean[len + 1];

        // boolean배열의 default값은 false이므로 true로 저장
        for (int i = 0; i < isPrime.length; i++) {
            isPrime[i] = true;
        }

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i <= Math.sqrt(len); i++) {
            if (isPrime[i]) {
                // 소수의 배수들은 모두 false처리
                for (int j = i * i; j <= len; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return;
    }
}