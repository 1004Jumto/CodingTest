/* 문자열을 회전시키면서 각 문자열에 대해 바른지 아닌지 검사한다
   O(N^2) => 1000*1000 = 100만
*/ 

import java.util.Stack;

class Solution {
    public int solution(String s) {
        int answer = 0;
        
        for(int i = 0 ; i < s.length(); i++){
            String str = s.substring(i) + s.substring(0, i); 
            // 검사
            if(check(str)) answer++;
        }
        
        /* StringBuilder로 문자열 회전
        StringBuilder sb= new StringBuilder(s);
        for(int i = 0 ; i < s.length(); i++){
            sb.append(sb.charAt(0));
            sb.deleteCharAt(0);
        }
        */
        
        return answer;
    }
    
    // 올바른 괄호 문자열인지 검사
    private boolean check(String s){
        Stack<Character> st = new Stack<>();
        
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i); 
            if(ch == ']' || ch == ')' || ch == '}'){
                if(st.isEmpty()) return false;
                if(st.peek() == '[' && ch != ']') return false;
                if(st.peek() == '{' && ch != '}') return false;
                if(st.peek() == '(' && ch != ')') return false;
                st.pop();
            }
            else{
                st.push(ch);    
            } 
        }
        
        // 문자열 순회 다른 코드
        // for(char ch : s.toCharArray()){}
        
        if(st.isEmpty()) return true;
        return false;
    }
}