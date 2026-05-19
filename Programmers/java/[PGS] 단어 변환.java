import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        int answer = 0;

        Map<String, List<String>> graph = new HashMap<>();

        // 1. 그래프 초기화
        List<String> wordList = new ArrayList<>();
        wordList.add(begin);
        wordList.addAll(Arrays.asList(words));

        initGraph(graph, wordList);
        System.out.println(graph);

        // 2. BFS로 begin에서 target까지의 최단 거리 계산
        answer = bfs(begin, target, graph);

        return answer;
    }

    // String start부터 end까지 최단 거리 계산
    private int bfs(String start, String end, Map<String, List<String>> graph) {
        int result = 0;

        Queue<String> queue = new LinkedList<>();
        boolean[] visited = new boolean[graph.size() + 1];
        int[] distance = new int[graph.size() + 1];

        // visited용 단어 <-> 숫자 매핑
        int idx = 0;
        Map<String, Integer> wordmap = new HashMap<>();
        for (String s : graph.keySet())
            wordmap.put(s, idx++);

        // 첫번째 노드 삽입 및 탐색 시작
        queue.offer(start);
        visited[wordmap.get(start)] = true;

        while (!queue.isEmpty()) {
            String cur = queue.poll();

            if (cur.equals(end)) {
                result = distance[wordmap.get(end)];
                break;
            }

            for (String s : graph.get(cur)) {
                if (!visited[wordmap.get(s)]) {
                    queue.offer(s);
                    visited[wordmap.get(s)] = true;
                    distance[wordmap.get(s)] = distance[wordmap.get(cur)] + 1;
                }
            }
        }

        return result;
    }

    // 그래프 초기화
    private void initGraph(Map<String, List<String>> graph, List<String> words) {
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                String w1 = words.get(i);
                String w2 = words.get(j);
                if (isSibling(w1, w2)) {
                    graph.computeIfAbsent(w1, g -> new ArrayList<>()).add(w2);
                    graph.computeIfAbsent(w2, g -> new ArrayList<>()).add(w1);
                }
            }
        }
    }

    // 둘이 한 알파벳만 다른지 검사
    private boolean isSibling(String s1, String s2) {
        int diff = 0;

        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i))
                diff++;
            if (diff > 1)
                return false;
        }

        return true;
    }
}