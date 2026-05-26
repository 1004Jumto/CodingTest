/*
while 총 작업완료한 개수 < 전체 작업 개수 
    배열에서 스피드에 따라 진척도 업데이트 for문
    while문으로 진척도 100이상인 작업 카운트
    카운트가 0이 아니라면 큐에 저장
*/

import java.util.Queue;
import java.util.LinkedList;
import java.util.Arrays;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        int taskCount = 0;
        int idx = 0;
        Queue<Integer> done = new LinkedList<>();
        
        if(progresses.length == 1) {
                answer = new int[1];
                answer[0] = 1; 
        }
        
        while(taskCount < progresses.length){
            
            // 진척도 업데이트
            // 이미 100 이상이면 패스
            // idx 이전은 완료된 작업이므로 idx부터 시작
            for(int i = idx; i < progresses.length; i++){
                if(progresses[i] >= 100) continue;
                progresses[i] += speeds[i];
            }
            
            // 다 된 작업은 큐에 저장
            int count = 0;
            while(idx < progresses.length && progresses[idx] >= 100){
                count++;
                idx++;
            }
            
            if(count != 0) {
                done.offer(count);
                taskCount += count;
            }
        }
       
        System.out.println(done);
        answer = done.stream().mapToInt(i -> i).toArray();
        return answer;
    }
}