import java.util.*;

class Solution {
    public int solution(int[][] points, int[][] routes) {
        /*
         * 각 포인터 별로 최단거리 루트를 저장
         * 루트는 맵에 저장 -> [경로 몇번째, 위치 : 카운트] 
         * 최단거리는 bfs로 탐색 -> 굳이 BFS로 탐색할 필요가 없음 -> R을 먼저 맞추고 C를 맞추면 됨
         * 루트끼리 서로 비교하여 같은 인덱스에 같은 위치에 있으면 위험상황으로 카운트
        */
        
        // 0. 변수 초기화
        int answer = 0;
        Map<String, Integer> map = new HashMap<>();      // [경로 순서, 위치 r, 위치 c] : 횟수
        
        // 1. 경로 순회하면서 t초 기준 이동 경로와 위치 카운트
        for(int i = 0; i < routes.length; i++) {
            int time = 0;
            
            for(int j = 0; j < routes[i].length - 1; j++) {
                int start = routes[i][j] - 1;
                int dest = routes[i][j + 1] - 1;
                
                // 루트마다 지나가는 경로를 저장
                // System.out.println("이동목표=" + points[start][0] + ", " + points[start][1] + " -> " + points[dest][0] +", " + points[dest][1]);
                time = navigate(map, time, points[start][0], points[start][1], points[dest][0], points[dest][1]);
            }
        }
        
        // System.out.println(map);
        
        // 2. 맵 순회하면서 위험 상황 카운트
        for(int val : map.values()) {
            if(val > 1) answer++;
        }
        
        
        return answer;
    }
    
    public int navigate(Map<String, Integer> map, int time, int sr, int sc, int dr, int dc) {
         
        String str = String.valueOf(time) + "," + String.valueOf(sr) + "," + String.valueOf(sc); 
        // System.out.println("이동=" + str);
        if(time == 0) map.put(str, map.getOrDefault(str, 0) + 1);
        
        // r부터 위치를 맞춘 뒤 c에 맞게 이동
        while(sr != dr) {
            if(sr < dr) {
                sr++;
            }
            else{
                sr--;    
            }
            
            time++;
                
            str = String.valueOf(time) + "," + String.valueOf(sr) + "," + String.valueOf(sc); 
            // System.out.println("이동=" + str);
            map.put(str, map.getOrDefault(str, 0) + 1);
        }
        
        while(sc != dc) {
            if(sc < dc) {
                sc++;
            }
            else{
                sc--;    
            }
            
            time++;
                
            str = String.valueOf(time) + "," + String.valueOf(sr) + "," + String.valueOf(sc); 
             // System.out.println("이동=" + str);
            map.put(str, map.getOrDefault(str, 0) + 1);
        }
        
        return time;
    }
}