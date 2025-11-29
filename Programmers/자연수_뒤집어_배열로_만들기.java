class Solution {
    public int[] solution(long n) {
        return new StringBuilder(String.valueOf(n)).reverse().toString().chars().map(c -> c - '0').toArray();
    
    }
}
/*
class Solution {
    public int[] solution(long n) {
        int[] answer = {};
        int j =0;
        String s = "";
        s = s.valueOf(n);
        answer = new int[s.length()];
        while(n /10 != 0){
            answer[j] = (int)(n % 10);
            n /= 10;
            j++;
        }
        answer[j] = (int)n;
        
        return answer;
    }
}
*/