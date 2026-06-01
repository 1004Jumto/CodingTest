import java.util.HashMap;
import java.util.Map;

class Solution {
    public String solution(String[] participant, String[] completion) {
        // 해시맵 사용
        // 이름 String :명수 int
        // participant 문자열을 순회하면서 해시맵에 put
        // completion 순회하면서 containsKey로 검사
        // 동명이인 -> 동시에 value 검사하여 value-1 put(key, ket.get()++) 
        String answer = "";
        
        Map<String, Integer> map = new HashMap<>();
        
        // 맵에 이름과 value 추가. 만약 있으면 ++ -> O(N)
        for(String s : participant){
            int n = map.getOrDefault(s, 0);
            map.put(s, n + 1);
        }
        
        // 완주한 사람 traversing 하면서 -1 -> O(N)
        for(String s : completion){
            if(map.containsKey(s)){
                map.put(s, map.get(s) - 1);
            }
            else{
                return s;
            }
        }
        
        // value가 1인 사람 = 완주 못한 사람 탐색 -> O(N)
        for(Map.Entry<String, Integer> entry : map.entrySet()){
            if(entry.getValue() != 0){
                return entry.getKey();
            }
        }
        return answer;
    }
}

/*
getOrDefault
value 업데이트
Map.Entry로 순회하여 value 탐색 -> Entry는 Map의 프로퍼티

시간복잡도 -> O(3N) -> O(N)
*/