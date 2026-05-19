package java;
import java.util.HashMap;
import java.util.Map;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];

        // <id, index> 를 저장하는 map
        Map<String, Integer> id_index = new HashMap<>();
        // id_list를 순회하면서 각 id와 index를 저장 -> O(N) 1000
        for (int i = 0; i < id_list.length; i++) {
            id_index.put(id_list[i], i);
        }

        // report를 순회하면서 해시맵에 <String, HashSet<String>> map으로
        // key 는 신고당한 id, value(set)에는 해당 유저를 신고한 id들을 저장
        Map<String, Set<String>> map = new HashMap<>();

        for (String str : report) { // -> O(M) 200,000
            String[] temp = str.split(" ");
            String reporter = temp[0]; // 신고자
            String reported = temp[1]; // 신고 당한 사람

            Set<String> set = map.getOrDefault(reported, new HashSet<>()); // -> O(1)
            set.add(reporter);
            map.put(reported, set);
        }
        // System.out.println(map);

        // map을 순회하면서 set의 사이즈가 k이상인 set에 대해
        // 해당 set에 있는 유저들 answer[i]++(answer[i] 유저는 id_list[i]와 동일) -> O(N) 1000
        for (Map.Entry<String, Set<String>> entry : map.entrySet()) {
            String reported = entry.getKey();
            Set<String> reporters = entry.getValue();

            if (reporters.size() > k - 1) {
                // System.out.println(reported);
                // reported를 고발한 유저들의 메일 횟수를 카운트 -> O(N) 1000
                for (String re : reporters) {
                    answer[id_index.get(re)]++; // -> O(1)
                }
            }
        }

        // 시간복잡도는 최종적으로 O(N + M)

        return answer;
    }
}