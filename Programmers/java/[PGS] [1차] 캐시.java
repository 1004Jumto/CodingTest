import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        /*
         * LRU: 가장 오랫동안 참조되지 않은 데이터를 캐시에서 먼저 삭제(교체)하는 알고리즘
         * 
         * (고민)
         * 도시 별 사용된 순서를 저장해야함 -> 해시맵, 트리맵, 셋 + 큐?
         * 셋으로 현재 캐시에 있는 도시 탐색, 큐에서는 계속 poll, offer
         *
         * 도시 모두 lowercase로 변환 필요
         * 
         * 도시를 순회하면서 아래를 반복
         * - 셋에 도시가 없으면, 셋에 새로운 도시 추가 오래된 도시 삭제, 큐에서 poll 후 새 도시 offer
         * - 셋에 도시가 있으면, 셋은 그대로, 큐에서 해당 도시를 맨 뒤로 다시 큐를 세팅
         */

        int answer = 0;

        if (cacheSize < 1)
            return 5 * cities.length;

        // 해시 셋
        Set<String> cache = new HashSet<>();

        // 큐
        Queue<String> queue = new LinkedList<>();

        for (String city : cities) {
            city = city.toLowerCase();

            // 캐시에 있는지 검사
            // 1. 캐시에 있는 경우
            if (cache.contains(city)) {
                // cache hit 이므로 실행시간 1
                answer += 1;

                // 캐시는 건드리지 않고, 큐 순서를 다시 재조정 [A B C -> B -> A C B]
                String target = "";
                int size = queue.size();
                for (int i = 0; i < size; i++) {
                    String temp = queue.poll();

                    if (!temp.equals(city)) {
                        queue.offer(temp);
                    } else {
                        target = temp;
                    }
                    // System.out.println(queue);
                }
                // 가장 최근 도시를 가장 뒤로 세팅
                queue.offer(target);

            } else { // 2. 캐시에 없는 경우
                // cache miss이므로 실행시간은 5
                answer += 5;

                // 캐시 꽉 찬 경우
                if (cache.size() >= cacheSize) {
                    // queue에서 가장 오래된 도시 poll
                    String old = queue.poll();

                    // cache에 새로운 도시 add, 오래된 도시는 remove
                    cache.remove(old);
                }

                // 큐, 캐시에 새로운 도시 추가
                queue.offer(city);
                cache.add(city);

            }

            // System.out.println("도시=" + city + " cache=" + cache + " queue=" + queue);
        }

        return answer;
    }
}