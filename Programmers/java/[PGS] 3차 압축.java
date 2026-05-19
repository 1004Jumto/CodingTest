/*
사전 -> map 사용


1. map<Integer, String> 생성, 색인번호 A~Z까지 초기화 
2. msg 순회
3. while(containsKey) 맵에 key가 있을때까지 문자열 += 하나씩 추가
4. 없는 문자열 map에 추가
5. 문자열 위치 가리키는 인덱스 필요 -> msg 순회

*/
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    public int[] solution(String msg) {
        int[] answer = {};
        ArrayList<Integer> list = new ArrayList<>();
        
        // map 초기화
        Map<String, Integer> map = new HashMap<>();
        for(char ch = 'A'; ch <= 'Z'; ch++){
            map.put(String.valueOf(ch), ch - 'A' + 1);
        }
        //System.out.println(map);
        
        // msg 순회
        int idx = 0;
        int idxNum = 27;
        while(idx < msg.length()){
            String str = msg.substring(idx, idx+1); 
            String newStr = str; 
            int innerIdx = idx + 1;
            
            // map에 문자열이 있을 때까지 계속 확인
            while(innerIdx < msg.length() && map.containsKey(newStr)){    
                str = newStr;
                newStr = str + String.valueOf(msg.charAt(innerIdx));
                innerIdx++;
            }
            // 새로운 문자열은 map에 추가
            if(!map.containsKey(newStr)) {
                map.put(newStr, map.size() + 1);
                // 색인된 문자에 대해 추가
                list.add(map.get(str));
                idx = idx + str.length();
            }
            else{
                // 맨 마지막에 idx에서 걸려서 끝난 경우를 위해 추가
                list.add(map.get(newStr));
                idx += newStr.length();
            }
            
            // System.out.println(newStr);
        }
        
        // 리스트를 배열에 담기
        answer = list.stream().mapToInt(i -> i).toArray();
        
        return answer;
        
    }
}