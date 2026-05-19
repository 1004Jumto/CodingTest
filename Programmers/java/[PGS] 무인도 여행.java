import java.util.*;

class Solution {

    // 방향 배열
    int[] dx = { -1, 1, 0, 0 };
    int[] dy = { 0, 0, 1, -1 };

    public int[] solution(String[] maps) {
        int[] answer = {};

        // 행, 열 길이 저장
        int col = maps[0].length();
        int row = maps.length;

        // 탐색 유무 저장 배열
        boolean[][] visited = new boolean[row][col];

        // 정답 저장할 리스트
        List<Integer> list = new ArrayList<>();

        // 지도를 순회하면서 X가 아닌 숫자 탐색
        // 숫자를 발견하면 dfs로 주변 섬을 탐색하여 합계 반환
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (Character.isDigit(maps[i].charAt(j)) && !visited[i][j]) {
                    list.add(dfs(i, j, visited, maps));
                }
            }
        }

        list.sort(Comparator.naturalOrder());

        if (list.size() > 0)
            answer = list.stream().mapToInt(i -> i).toArray();
        else
            answer = new int[] { -1 };

        return answer;
    }

    private int dfs(int x, int y, boolean[][] visited, String[] maps) {
        int count = 0;

        visited[x][y] = true;
        count += maps[x].charAt(y) - '0';

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < maps.length && ny < maps[0].length()) {
                if (!visited[nx][ny] && Character.isDigit(maps[nx].charAt(ny))) {
                    visited[nx][ny] = true;
                    count += dfs(nx, ny, visited, maps);
                }
            }

        }

        return count;
    }
}