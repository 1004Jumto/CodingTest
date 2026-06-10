import java.util.*;

class Solution {
    public int solution(int n) {
        
        // 자기 자신은 항상 포함되므로 기본값을 1로 설정
        int answer =1;
        
        for(int i = 1; i <= n / 2; i++) { 
        
            if(isPossible(i, n)) {
                answer++;
            }
        }
        
        return answer;
    }
    
    public boolean isPossible(int start, int target) { 
        
        if(start == target) return true;
        
        if(start < target) {
            return isPossible(start + 1, target - start);
        }
        
        return false;
    }
}