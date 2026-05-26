import java.util.*;

class Solution {
    public int solution(String name) {
        int answer = 0;
        int n = name.length();
        int move = n - 1;
        
        /*
         * 알파벳을 바꾸는 횟수는 항상 동일
         * 어떤 위치들을 어떤 경로로 방문할지가 중요
        */
        
        for(int i = 0; i < n; i++) {
            char c = name.charAt(i);
            
            // 0. 알파벳 변환 횟수 계산
            answer += Math.min(c - 'A', 'Z' - c + 1);
            
            // 1. 위치별로 최소 이동을 계산
            int next = i + 1;
            
            while(next < n && name.charAt(next) == 'A') {
                next++;
            }
            
            move = Math.min(move, i * 2 + n - next);
            move = Math.min(move, (n - next) * 2 + i);
        }
        
         
        return answer += move;
    }
}