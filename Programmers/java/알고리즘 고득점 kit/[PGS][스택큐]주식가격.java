import java.util.Stack;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        
//      굳이 스택을..? 시간복잡도 O(N^2)이지만 테스트는 통과함.
        /*
        for(int i = 0; i < prices.length - 1; i++){
            int count = 0;
            int price = prices[i];
            
            for(int j = i + 1; j < prices.length; j++){
                count++;
                if(price > prices[j]) break;
            }
            answer[i] = count;
        }
        */
        // 스택 사용해서 시간복잡도O(N)으로 풀어보기
        /*
        스택에는 아직 떨어지지 않은 가격에 대한 인덱스를 저장
        가격이 st.peek 보다 떨어지는 경우 스택에 있는 인덱스를 pop
        현재(i)시간에서 pop한 인덱스의 시간 차이를 정답 배열에 저장
        */
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < prices.length; i++){
            // 현재 가격price[i]이 떨어지기 전까지 
            while(!st.isEmpty() && prices[st.peek()] > prices[i]){
                int idx = st.pop();
                answer[idx] = i - idx;
            }
            st.push(i);
            
            
        }
        
        while(!st.isEmpty()){
            int idx = st.pop();
            answer[idx] = prices.length - idx - 1;
        }
        
        return answer;
    }
}