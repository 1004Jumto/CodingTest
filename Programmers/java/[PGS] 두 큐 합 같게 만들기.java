import java.util.Queue;
import java.util.LinkedList;
import java.util.Arrays;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = -1;
        long sum1 = 0;
        long sum2 = 0;
        long target = 0;
        int count = 0; 
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();
        
        // 각 큐의 합과 목표합 구하기
        for(int i : queue1) {
            sum1 += i;
            q1.offer(i);
        }
        for(int i : queue2) {
            sum2 += i;
            q2.offer(i);
        }
        target = (sum1 + sum2) / 2; 
        
        // 큐1의 합이 목표합이 될 때까지 반복
        while(sum1 != target && !q1.isEmpty() && !q2.isEmpty()){
            
            // 목표합보다 작은 경우
            if(sum1 < target){
                int n = q2.poll();
                q1.offer(n);
                sum1 += n;
            }
            // 목표합보다 큰 경우
            else if(sum1 > target){
                int n = q1.poll();
                q2.offer(n);
                sum1 -= n;
            }
            count++;
            
            // 각 큐의 원소가 이동할 수 있는 횟수보다 count가 커지면 리턴
            if(count > (q1.size() + q2.size())*2){
                break;
            }
            // System.out.println(q1 + " : " + q2);

        } 
        
        if(sum1 != target) answer = -1;
        else answer = count;
         
         
        return answer;
    }
}