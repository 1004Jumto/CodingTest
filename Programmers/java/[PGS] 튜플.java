import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = {};

        // "{{2},{2,1},{2,1,3},{2,1,3,4}}" -> ["2", "2,1", "2,1,3", "2,1,3,4"]
        String[] parsedTuple = s.substring(2, s.length() - 2).split("\\}\\,\\{");
        Map<Integer, Integer> count = new HashMap<>();

        // ["2", "2,1", "2,1,3", "2,1,3,4"]
        for (String str : parsedTuple) {
            String[] element = str.split(","); // -> [2], [2,1] ...

            for (String ele : element) {
                int num = Integer.parseInt(ele);
                count.put(num, count.getOrDefault(num, 0) + 1);

            }
        }

        // value 기준 내림차순 정렬
        List<Integer> values = new ArrayList<>(count.keySet());
        values.sort((n1, n2) -> count.get(n2) - count.get(n1));

        // 리스트 -> 배열
        answer = values.stream().mapToInt(i -> i).toArray();

        return answer;
    }
}