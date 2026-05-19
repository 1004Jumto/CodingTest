/*
두개의 스택을 사용하나?
유사문제 -> BOJ 스택수열
1~N까지 숫자를 입력받은 순서대로 출력하는 문제

1. 보조 컨테이너 스택, 박스 개수, 현재 박스 번호를 저장할 변수 선언
2. order 순회
3. order[i] > box 인 경우, order[i]==box 까지 이전 박스는 스택에 보관
4. order[i] == box 인 경우, count(answer)++, 그리고 다음 박스순서로 넘어감
5. order[i] < box 인 경우, 보조 컨테이너 peek==order[i]인지 검사 후 실는다 
*/

import java.util.Stack;

class Solution {
    public int solution(int[] order) {
        int answer = 0;
        int box = 1;                            // 현재 박스 번호
        int len = order.length;                 // 박스 개수
        Stack<Integer> st = new Stack<>();      // 보조 컨테이너 벨트
        
        for(int i = 0; i < len; i++){
            int target = order[i];
            
            while(target > box) {
                st.push(box);
                box++;
            }
            
            if(target == box){
                answer++;
                box++;
                continue;
            }
            
            if(target < box){
                if(st.peek() == target){
                    st.pop();
                    answer++;
                    continue;
                }
                else break;
            }
        }
        
        
        return answer;
    }
}