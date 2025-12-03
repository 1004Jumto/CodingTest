class Solution {
    public int[] solution(String s, int n) {
        String answer = ""; 
        return s.chars().map(c -> c + n).toArray();
    }
}