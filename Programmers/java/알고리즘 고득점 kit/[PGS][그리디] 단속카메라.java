import java.util.*;

class Solution {
    public int solution(int[][] routes) {

        // 0. 변수 초기화
        int answer = 0;
        int cctvCnt = 1;
        int[] common = new int[]{-30000, 30000};
        
        // 1. 시작지점 기준 오름차순 정렬
        Arrays.sort(routes, (a, b) -> a[0] - b[0]);
        // for(int[] tmp : routes) {
        //     System.out.println(Arrays.toString(tmp));
        // }
        
        // 2. routes 순회하면서 cctv 카운트
        for(int[] route : routes) {
             
                // 시작지점이 공통범위 사이에 있는 경우
                if(common[0] <= route[0] && route[0] <= common[1]) {
                    
                    // 공통범위 업데이트
                    common[0] = Math.max(common[0], route[0]);
                    common[1] = Math.min(common[1], route[1]);
                }
                // 공통범위 사이에 없는 경우
                else{
                    // 새로운 그룹
                    common = new int[]{route[0], route[1]};
                    
                    // 이전 그룹에 대해 cctv 수 증가
                    cctvCnt++;
                }
            
        }
        
        return answer = cctvCnt;
    }
}
