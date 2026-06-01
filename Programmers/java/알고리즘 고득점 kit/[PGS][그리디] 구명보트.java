import java.util.*;
import java.util.Arrays;

class Solution {
    public int solution(int[] people, int limit) {
        
        /*
         * 몸무게가 limit - 40KG 초과이면 혼자 탈 수 밖에 없음
         * 혼자 타는 사람을 제외하고 모두 리스트에 저장
         * 길이가 1이하이면 바로 리턴
         * 오름차순으로 정렬
         * 가장 무거운 사람과 가장 가벼운 사람을 매칭
         
         * => 결국 투 포인터로 앞 뒤를 하나씩 매칭하면서 보트 수를 늘린다
        */
        
        // 0. 변수 초기화
        int answer = 0;
        int right = people.length - 1;
        int left = 0;
        
        // 1. 1명인 경우
        if(left == right) return 1;
        
        // 2. 정렬
        Arrays.sort(people);
        
        // 3. 투포인터로 인덱스 탐색
        while(left <= right) {
            
            // 가장 몸무게가 적은 사람과 못타는 사람은 혼자 타야함
            if(people[left] + people[right] > limit) {
                right--;
            }else {
                right--;
                left++;
            }
           
            answer++; 
        }
         
        return answer;
    }
}