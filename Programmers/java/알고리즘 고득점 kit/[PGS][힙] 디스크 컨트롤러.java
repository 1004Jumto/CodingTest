import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        
        // 0. 변수 초기화
        int answer = 0; 
        int cur = 0;
        int turnaround = 0;
        int idx = 0;
        int completed = 0; 
        int n = jobs.length;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((arr1, arr2) -> {
            // 작업의 소요시간 기준 오름차순
            if(arr1[1] != arr2[1]) {
                return arr1[1] - arr2[1];
            }
            
            // 작업의 요청 시각 기준 오름차순
            if(arr1[0] != arr2[0]) {
                return arr1[0] - arr2[0];
            }
            
            // 작업 번호 기준 오름차순 -> 사실상 그냥 놔두면 되는?
            return 0;
        });
        
        // 1. 요청 시각 기준 배열 정렬
        Arrays.sort(jobs, (arr1, arr2) -> {
            if(arr1[0] != arr2[0]) {
                return arr1[0] - arr2[0];
            }
            
            return arr1[1] - arr2[1];
        });
         
        // 2. 작업을 모두 수행할 때까지 반복 
        while (completed < n) {

            // 현재 시간까지 요청된 작업들을 모두 pq에 넣기
            while (idx < n && jobs[idx][0] <= cur) {
                pq.offer(jobs[idx]);
                idx++;
            }

            // 실행 가능한 작업이 없다면 다음 작업 요청 시간으로 점프
            if (pq.isEmpty()) {
                cur = jobs[idx][0];
                continue;
            }

            // 소요 시간이 가장 짧은 작업 실행
            int[] task = pq.poll();

            cur += task[1];

            // 반환 시간 = 작업 종료 시각 - 작업 요청 시각
            turnaround += cur - task[0];

            completed++;
        }

        return turnaround / n; 
    }
}