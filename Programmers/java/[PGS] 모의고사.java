/*
각 수포자가 찍는 방식을 배열에 담고, 세 명의 수포자 모두 answer와 비교하여 검사한다
*/

import java.util.List;
import java.util.ArrayList;

class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        
        int[] one = {1,2,3,4,5};
        int[] two = {2,1,2,3,2,4,2,5};
        int[] three = {3,3,1,1,2,2,4,4,5,5};
        
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        int len = answers.length;
        for(int i = 0; i < len; i++){ 
            if(one[i % 5] == answers[i]) count1++;
            if(two[i % 8] == answers[i]) count2++;
            if(three[i % 10] == answers[i]) count3++; 
        }
        
        System.out.println(count1 +":"+ count2 +":"+ count3);
        int max = Math.max(Math.max(count1, count2), count3);
        
        List<Integer> list = new ArrayList<>();
        if(count1 >= max) list.add(1);
        if(count2 >= max) list.add(2);
        if(count3 >= max) list.add(3);
        
        answer = list.stream().mapToInt(i->i).toArray();
        
        return answer;
    }
}