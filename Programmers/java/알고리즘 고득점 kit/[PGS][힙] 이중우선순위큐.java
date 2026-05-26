import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = {};
    
        // 0. 변수 초기화
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        PriorityQueue<Integer> reversedPq = new PriorityQueue<>(Collections.reverseOrder());
        
        // 1. operations 순회
        for(String op : operations) {
            String[] str = op.split(" ");
            
            // 큐 삽입
            if(str[0].equals("I")) {
                pq.offer(Integer.parseInt(str[1]));
                reversedPq.offer(Integer.parseInt(str[1]));
            } 
            // 최댓값 삭제
            else if(str[1].equals("1") && !reversedPq.isEmpty()) { 
                reversedPq.poll();
                
                // pq와 동기화
                pq.clear();
                pq.addAll(reversedPq);
            }
            else if(str[1].equals("-1") && !pq.isEmpty()) {
                pq.poll();
                
                // 동기화
                reversedPq.clear();
                reversedPq.addAll(pq);
            }
            
        }
        
        // 2. 결과값 도출
        if(pq.isEmpty()) answer = new int[]{0, 0};
        else if(pq.size() == 1) answer = new int[]{pq.peek(), pq.poll()};
        else{
            answer = new int[]{reversedPq.poll(), pq.poll()};
        }
        
        return answer;
    }
}

/////////////// TreeMap을 사용한 풀이 ///////////////
/// TreeMap은 key가 중복될 수 없으므로, value에 해당 key의 개수를 저장하여 구현
/// 최댓값 삭제 시, 가장 큰 key의 value를 1 감소시키고, value가 0이 되면 해당 key 제거
/// 최솟값 삭제 시, 가장 작은 key의 value를 1 감소시키고, value가 0이 되면 해당 key 제거
/// 최종적으로 TreeMap이 비어있으면 [0, 0] 반환, 그렇지 않으면 [최댓값, 최솟값] 반환
////////////////////////////////////////////////////
/* 
import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        TreeMap<Integer, Integer> map = new TreeMap<>();

        for (String operation : operations) {
            String[] parts = operation.split(" ");
            String command = parts[0];
            int value = Integer.parseInt(parts[1]);

            if (command.equals("I")) {
                map.put(value, map.getOrDefault(value, 0) + 1);
            } else {
                if (map.isEmpty()) continue;

                int target = value == 1 ? map.lastKey() : map.firstKey();

                if (map.get(target) == 1) {
                    map.remove(target);
                } else {
                    map.put(target, map.get(target) - 1);
                }
            }
        }

        if (map.isEmpty()) {
            return new int[]{0, 0};
        }

        return new int[]{map.lastKey(), map.firstKey()};
    }
}
*/
