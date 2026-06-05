class Solution {
    public int solution(int n) {
        int answer = 0;
        String s = "";
        
        while(n != 0){
            s += String.valueOf(n % 3);
            n /= 3;
        }
        
        return Integer.parseInt(s, 3);
        
    }
}

/*class Solution {
    public int solution(int n) {
        int answer = 0;
        // 3진법 앞뒤 반전된 string으로 리턴
        String trit = convertToTrit(n); 
        
        // 10진법으로 변환 int로 리턴
        answer = convertToNum(trit);
        
        return answer;
    }
    
    // 정수 -> 3진법으로 String 변환
    private String convertToTrit(int num){
        String res = "";
        
        while(num != 0){
            res += String.valueOf(num % 3);
            num /= 3;
        }
        
        return res;
    }
    
    // 3->10진법으로 변환
    private int convertToNum(String s){
        int res = 0;
        int k = 1;
        for(int i = s.length()-1; i>=0; i--, k*=3){
            res += (s.charAt(i) - '0') * k; 
        }
        
        return res;
    }
}
*/