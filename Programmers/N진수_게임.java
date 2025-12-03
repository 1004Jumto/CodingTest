import java.util.List;
import java.util.ArrayList;

class Solution {
    public String solution(int n, int t, int m, int p) {
        String answer = "";
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i <= m * t; i++){
            sb.append(Integer.toString(i, n));
        }
        
        
        for(int i = 0; i < t; i++){
            answer += sb.charAt(i * m + p - 1);
        }
        
        return answer.toUpperCase();
    }
}