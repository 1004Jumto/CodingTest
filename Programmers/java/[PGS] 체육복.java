import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;

        Arrays.sort(lost);
        
        // 실제 체육복이 필요한 학생 리스트
        List<Integer> needCloth = new ArrayList<>();

        // 빌려줄 수 있는 학생들 표시
        boolean[] canBorrow = new boolean[n + 2];
        for (int i : reserve) {
            // 여벌이 있는 학생을 true로 저장
            canBorrow[i] = true;
        }

        // 여벌이 있지만 도난당한 학생 처리
        // 여벌이 있는 학생을 false로 처리하고 실제로 체육복이 필요한 학생 리스트에서는 제외
        for (int i : lost) {
            if (canBorrow[i]) {
                canBorrow[i] = false;
                answer++;
                continue;
            }
            needCloth.add(i);
        }

        // 체육복이 필요한 학생들을 순회하면서 처리
        // 여벌을 빌려준 학생들 false 처리
        for (int i : needCloth) {
            if (canBorrow[i - 1]) {
                canBorrow[i - 1] = false;
                answer++;
                continue;
            } else if (canBorrow[i + 1]) {
                canBorrow[i + 1] = false;
                answer++;
                continue;
            }
        }

        // 전체 학생 수 - 도난당한 학생 수 + 체육복 빌린 학생 수
        return n - lost.length + answer;
    }
}
