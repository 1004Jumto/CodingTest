class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        // 모두 소문자로 변경
        s = s.toLowerCase();
        
        long pCnt = s.chars().filter(c -> c == 'p').count();
        long yCnt = s.chars().filter(c -> c == 'y').count();
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println(pCnt + ":" + yCnt);
        
        if(pCnt != yCnt) answer = false; 

        return answer;
    }
}