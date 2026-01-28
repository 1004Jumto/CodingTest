package java;
class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;

        // 가장 최악 -> 검사할 스킬 개수 20개, 스킬트리 길이 26개
        // -> String.indexOf() → O(K)
        // -> O(K * N * M)

        for (String s : skill_trees) {
            if (isValid(skill, s)) {
                answer++;
            }
        }

        return answer;
    }

    private boolean isValid(String skillOrder, String userSkillTree) {

        for (int i = 1; i < tree.length(); i++) {
            int next = userSkillTree.indexOf(skillOrder.charAt(i));
            int prev = userSkillTree.indexOf(skillOrder.charAt(i - 1));

            // 이전 스킬 없는데 다음 스킬이 있는 경우
            if (prev == -1 && next >= 0)
                return false;

            // 이전 스킬이 다음 스킬보다 후에 나오는 경우
            if (prev > next && next != -1)
                return false;

        }

        return true;
    }
}