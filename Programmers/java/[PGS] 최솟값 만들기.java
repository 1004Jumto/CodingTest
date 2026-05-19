import java.util.*;

// 하나의 배열에서는 큰 수, 다른 배열에서는 작은 수를 골라 곱해 최소값을 만든다
// A배열은 오름차순, B배열은 내림차순
class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;

        Arrays.sort(A);
        Arrays.sort(B);

        for (int i = 0; i < A.length; i++) {
            answer += (A[i] * B[B.length - i - 1]);
        }

        return answer;
    }
}