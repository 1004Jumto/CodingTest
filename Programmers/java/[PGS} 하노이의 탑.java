/*
n개의 원판을 1 -> 3으로 옮기기 위해서는, 
1. n-1개의 원판을 1 -> 2(중간)으로 옮긴 뒤, 
2. 맨 아래 있던 마지막 원판 한 개를 1 -> 3으로 옮기고, 
3. 2(중간)에 있던 n-1개의 원판을 2 -> 3으로 옮기면 된다.

이 때, 원판이 이동한 횟수는 2 * hanoi(n-1) + 1이라고 공식화할 수 있음
*/

import java.util.ArrayList;
import java.util.Arrays; 
import java.util.List; 

class Solution {
    List<int[]> path = new ArrayList<>();
    
    public int[][] solution(int n) {
        int[][] answer = {};
        
        hanoi(n, 1, 2, 3);
        
        answer = path.toArray(new int[path.size()][]);
        return answer;
    }
    
    private void hanoi(int n, int from, int mid, int to){
        if(n == 1) {  // 마지막 원판인 경우 그냥 from 에서 to로 옮김
            path.add(new int[]{from, to});            
            return;
        }    
        
        // n-1 개의 원판을 중간으로 옮긴다
        hanoi(n-1, from, to, mid);
        
        // 마지막 원판을 목적지로 옮긴다
        hanoi(1, from, mid, to);
        
        // 중간에 있는 n-1개의 원판을 목적지로 옮긴다
        hanoi(n-1, mid, from, to);
    }
}