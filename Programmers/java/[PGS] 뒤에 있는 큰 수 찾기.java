// 주식가격과 같은 문제인 것 같음
// 인덱스를 저장하는 용도로 스택 사용
/*
numbers 순회
numbers[st.peek] < numbers[i] -> pop -> answer에 numbers[i]저장 
*/ 

import java.util.Stack;

class Solution {
    public int[] solution(int[] numbers) {
        Stack<Integer> st = new Stack<>();
        int len = numbers.length;
        int[] answer = new int[len];
        
        for(int i=0; i<len; i++){
            while(!st.isEmpty() && numbers[st.peek()] < numbers[i]){
                answer[st.pop()] = numbers[i];
            }
            st.push(i);
        }
        
        while(!st.isEmpty()){
            answer[st.pop()] = -1;
        }
        
        return answer;
    }
}