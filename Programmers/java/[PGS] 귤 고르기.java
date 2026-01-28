/*
크기와 개수 -> map 생각
그리디 -> 가장 최선의 답 선택 -> 가장 많은 개수를 가진 크기의 귤 선택
map value 기준 내림차순 정렬

1. tangerine 순회하면서 map에 값<int, int>을 담는다
2. value 기준 Collection sort로 내림차순 map 정렬을 한다
3. map을 순회하면서 k개가 될 때 까지 더한다.
*/
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        
        Map<Integer, Integer> map = new HashMap<>();        
        
        // map에 값 복사
        for(int n : tangerine){
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        
        // map value 기준 내림차순 정렬 O(NLogN)
        ArrayList<Integer> list = new ArrayList<>(map.keySet());
        list.sort((i1, i2) -> map.get(i2).compareTo(map.get(i1)));
        
        /* (정렬 다른 방법) entrySet 사용
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(map.entrySet());
        list.sort((e1, e2)->e2.getValue().compareTo(e1.getValue()));
        */
        
        // map 순회하면서 k--
        for(Integer i : list){
            answer++;
            k -= map.get(i);
            if(k <= 0) break;
        }
        /* map 순회 방법
        for(Map.Entry<Integer, Integer> m : map.entrySet()){
            System.out.println(m);
            answer++;
            k -= m.getValue();
            if(k <= 0) break;
        }
        */
        
        
        return answer;
    }
}

// map의 순회방법, 정렬방법, compareTo vs compare override, Map.Entry와 EntrySet