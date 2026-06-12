import java.util.*;

class Solution {
    
    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, 1, 0, -1};
        
    Map<Integer, Integer> map = new HashMap<>();
    
    public int solution(int[][] land) {
        /*
         * 맵을 모두 순회하면서 석유가 발견된 곳이 있으면 연결된 곳 전체 탐색 -> 같은 칸에는 같은 숫자로 표시 -> 100부터 시작
         * 맵에 저장 [구역 : 석유 덩어리 수]
         * 열을 탐색하면서 set에 구역 저장
         * 구역 별로 석유 덩어리 합산
        */
        
        int answer = 0;
        int h = land.length;        // 행
        int w = land[0].length;     // 열
        int[][] visited = new int[h][w];    
        int areaNum = 100;
        
        // 맵을 전체 탐색하면서 석유 발견하여 구역 저장
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                
                // 석유 발견한 경우 탐색
                if(land[i][j] == 1 && visited[i][j] == 0) {
                    int count = dfs2(land, visited, i, j, areaNum); 
                    
                    // 탐색 후 맵에 석유 덩어리 수 저장
                    map.put(areaNum, count);
                    areaNum++;
                }
            }
        }
          
        
        // 열을 순회하며 제일 뽑을 수 있는 가장 큰 석유량 탐색
        for(int i = 0; i < w; i++) {
            Set<Integer> area = new HashSet<>();
            for(int j = 0; j < h; j++) {
                if(land[j][i] == 1) area.add(visited[j][i]);
            }
            
            // 석유량 합산
            int sum = 0;
            for(int amount : area) {
                sum += map.get(amount);
            }
            answer = Math.max(answer, sum);
        }
        
        return answer;
    }
    
    public int dfs(int[][] land, int[][] visited, int x, int y, int num) {
        if(visited[x][y] == 0) visited[x][y] = num;  
        
        int count = 1;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < land.length && ny < land[0].length && nx >= 0 && ny >= 0 && visited[nx][ny] == 0 && land[nx][ny] == 1) {
                count += dfs(land, visited, nx, ny, num);   
            }
        }
        
        return count;
        
    }
    
    public int dfs2(int[][] land, int[][] visited, int x, int y, int num) {
        
        int count = 0;
        
        Deque<int[]> stack = new ArrayDeque<>();
        stack.push(new int[]{x, y});
        visited[x][y] = num;
        
        while(!stack.isEmpty()){
            int[] cur = stack.pop();
            int cx = cur[0];
            int cy = cur[1];
            
            count++;
            
            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= land.length || ny >= land[0].length) {
                    continue;
                }
                if(visited[nx][ny] != 0) continue;
                if(land[nx][ny] != 1) continue;
                
                visited[nx][ny] = num;
                stack.push(new int[]{nx, ny});
            }
        }
        
        return count;
    }
}
