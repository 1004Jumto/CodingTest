class Solution {
    public String solution(String s) {
        String answer = "";
        StringBuilder sb = new StringBuilder();
        
        // 먼저 모두 대문자로 바꿔놓은 뒤, 홀수번째만 소문자로 변환
        s = s.toUpperCase();
        int idx = 0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == ' ' ){
                idx = 0;
                sb.append(s.charAt(i));
                continue;
            } 
            if(idx % 2 == 1) sb.append((char)(s.charAt(i) + 32));
            else sb.append(s.charAt(i));
            
            idx++;
        }
        
        answer = sb.toString();
        
        return answer;
    }
}