class Solution {
    private String[] vowels = { "A", "E", "I", "O", "U" };
    private int index = 0;

    public int solution(String word) {
        int answer = 0;

        dfs("", 0, word);

        return index;
    }

    // 원하는 문자열을 찾았는지 아닌지 반환
    private boolean dfs(String str, int depth, String target) {
        if (target.equals(str))
            return true;
        if (depth == 5)
            return false;

        for (String v : vowels) {
            index++;

            if (dfs(str + v, depth + 1, target)) {
                return true;
            }
        }

        return false;
    }
}