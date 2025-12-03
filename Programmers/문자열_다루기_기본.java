class Solution {
    public boolean solution(String s) {
        boolean answer = true;
         
        // 길이검사
        if(s.length() != 4 && s.length() != 6) return false;
        
        // 아스키코드로 검사
        // for(int i = 0; i < s.length(); i++){
        //     int c = s.charAt(i) - '0';
        //     System.out.println(c);
        //     if( c > 9 ||  c < 0) return false;
        // }
        
        return s.chars().allMatch(c -> c <= '9' && c >= '0');
        
        // return answer;
    }
}