import java.util.*;

/**
 * 포켓몬의 종류가 가져갈 포켓몬 수보다 많으면 종류별로 "한 마리씩" 포켓몬 수만큼 가져갈 수 있으므로 포켓몬 수
 * 포켓몬의 종류가 가져갈 포켓몬 수보다 적으면 종류가 "겹치게 종류별로" 가져가므로 포켓몬 종류 수
 */
class Solution {
    public int solution(int[] nums) {
        int answer = 0;

        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }

        int type = set.size();          // 포켓몬 종류 수
        int count = nums.length / 2;    // 가져갈 포켓몬 마리 수

        answer = Math.min(type, count);

        return answer;
    }
}