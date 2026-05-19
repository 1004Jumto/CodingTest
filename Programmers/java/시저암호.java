class Solution {
    public int[] solution(String s, int n) { 
        return s.chars().map(c -> c + n).toArray();
    }
}