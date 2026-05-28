import java.util.*;

class Solution {
    public String solution(String number, int k) {
        
        /*
         * 맨 앞에 최대한 큰 수가 있어야함
         * 앞자리와 바로 뒷자리 수를 비교했을 때 앞자리 수가 더 크면 넘어가고, 뒷자리가 크면 삭제
         * 스택에 숫자가 있고, 아직 삭제 횟수가 남아 있고, 이전에 선택한 마지막 숫자가 현재 숫자보다 작다면
        */
        
        // 0. 변수 초기화
        String answer = ""; 
        int count = 0;
        Stack<Integer> stack = new Stack<>();
        
        // 1. 숫자 순회하면서 비교 
        for(int i = 0; i < number.length(); i++) {
            int cur = number.charAt(i) - '0';
            
            while(!stack.isEmpty() && stack.peek() < cur && count < k) {
                stack.pop();
                count++;
            }
            
            stack.push(cur);
            
            // System.out.println(stack);  
        }
        
        while(count < k) {
            stack.pop();
            count++;
        }
        
        while(!stack.isEmpty()){
            answer = String.valueOf(stack.pop()) + answer;
        }
        
        return answer;
    }
}