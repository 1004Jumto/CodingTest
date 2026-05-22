import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        
        /*
         * location과 실행한 프로세스가 일치할 때까지 수행
         * 프로세스를 pop, 큐를 순회하면서 우선순위 확인
         * 실행한 프로세스의 순서와 location 확인 후 순서 리턴
        */
        int answer = 0;     
        int index = 0;      // 몇 번 반복문이 수행됐는지 횟수 저장
        
        // 1. 큐에 int[프로세스, 우선순위] 배열 초기화
        Queue<int[]> queue = new LinkedList<>();
        for(int i = 0; i < priorities.length; i++) {
            queue.offer(new int[]{i, priorities[i]});
            // System.out.println(Arrays.toString(new int[]{i, priorities[i]}));
        } 
        
        // 2. 큐가 빌 때까지 일단 반복
        while(!queue.isEmpty()) {
            // 프로세스 하나를 뽑음
            int[] cur = queue.poll();
            
            // 우선순위 유무 플래그
            boolean flag = false;
            
            // 큐를 순회하면서 우선순위를 확인(확인만 하면 됨)
            for(int[] arr : queue) {
                // 우선순위가 더 높은 요소가 있는 경우
                if(cur[1] < arr[1]) {
                    flag = true;
                    break;
                }
            } 
            
            // 우선순위가 더 높은 요소가 있는 경우
            if(flag) {
                // 해당 프로세스는 그대로 queue에 다시 삽입
                queue.offer(cur);
                
                // 반복
                continue;
                
            }else{  // 더 높은 우선순위가 없는 경우 프로세스 실행
                index++;
            }
              
            // location과 현재 수행한 프로세스가 같은 경우 종료
            if(location == cur[0]) break;
        }
        
        return answer = index;
    }
}