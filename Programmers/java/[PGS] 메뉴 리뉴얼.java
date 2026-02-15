import java.util.*;

class Solution {

    Map<Integer, List<String>> combLength = new HashMap<>();

    public String[] solution(String[] orders, int[] course) {
        String[] answer = {};

        Map<String, Integer> orderComb = new HashMap<>();

        // 주문된 음식에 대한 조합을 Map에 저장
        for (String order : orders) {
            makeCombination(order, orderComb);
        }
        // System.out.println(orderComb);
        // System.out.println(combLength);

        // 정렬
        List<Integer> ordered = new ArrayList<>(combLength.keySet());
        for (int count : ordered) {
            List<String> list = combLength.get(count);
            list.sort(new Comparator<String>() {
                @Override
                public int compare(String s1, String s2) {
                    if (s1.length() == s2.length()) {
                        return orderComb.get(s2) - orderComb.get(s1);
                    }
                    return s1.length() - s2.length();
                }
            });
        }
        // System.out.println(combLength);

        // 메뉴 담기
        List<String> list = new ArrayList<>();
        for (int cor : course) {
            List<String> cuisine = combLength.get(cor);
            // System.out.println(cuisine);
            if (cuisine != null) {
                for (int i = 0; i < cuisine.size(); i++) {

                    if (orderComb.get(cuisine.get(i)) >= 2
                            && orderComb.get(cuisine.get(i)) == orderComb.get(cuisine.get(0))) {
                        list.add(cuisine.get(i));
                    }
                }
            }
        }
        // System.out.println(list);

        answer = list.stream().toArray(String[]::new);
        Arrays.sort(answer);
        return answer;
    }

    // str의 조합을 모두 result에 횟수와 저장
    private void makeCombination(String str, Map<String, Integer> result) {
        // "ABCFG" -> "AB" "AC" "AF" "AG" "ABC" "ABF" "ABG"
        dfs(str, result, "", 0, 0);
    }

    private void dfs(String str, Map<String, Integer> result, String com, int depth, int start) {
        if (com.length() > 1) {
            // com을 알파벳 순으로 정렬
            char[] temp = com.toCharArray();
            Arrays.sort(temp);
            com = String.valueOf(temp);

            if (!result.containsKey(com)) {
                combLength.computeIfAbsent(com.length(), l -> new ArrayList<>()).add(com);
            }

            result.put(com, result.getOrDefault(com, 0) + 1);
        }

        if (depth == str.length()) {
            return;
        }

        for (int i = start; i < str.length(); i++) {
            dfs(str, result, com + String.valueOf(str.charAt(i)), depth + 1, i + 1);
        }
    }
}