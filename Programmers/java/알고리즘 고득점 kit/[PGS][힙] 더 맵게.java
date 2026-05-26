import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        int min = -1;
        int second = -1;
        
        // 우선순위 큐를 사용하여 정렬
        // 가장 작은 수를 min에 저장한 뒤, min이 K보다 클때까지 계속 반복
        // 이 때, 큐가 isEmpty 확인
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i : scoville) {
            pq.offer(i);
        }
        // System.out.println(pq);
        
        while(pq.size() > 1 && pq.peek() < K) {
            min = pq.poll();
            second = pq.poll();
            
            // 새롭게 스코빌 섞기
            pq.offer(min + second * 2);
            answer++;
            
            // System.out.println("큐="+pq+" 횟수=" + answer);
        }
        
        // 스코빌 실패한 경우
        if(pq.peek() < K) answer = -1;
        
        return answer;
    }
}