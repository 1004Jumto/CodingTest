import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int idx = 0;

        for (int[] cmd : commands) {
            int i = cmd[0];
            int j = cmd[1];
            int k = cmd[2];

            // K번째 수를 구하는 함수
            answer[idx++] = getKIndex(array, i, j, k);
        }

        return answer;
    }

    public int getKIndex(int[] narr, int start, int end, int target) {
        List<Integer> list = new ArrayList<>();

        for (int i = start - 1; i < end; i++) {
            list.add(narr[i]);
        }

        Collections.sort(list);

        return list.get(target - 1);
    }
}