import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        StringBuilder sb = new StringBuilder();
        String[] sarr = new String[numbers.length];
        
        for(int i = 0; i < numbers.length; i++){
            sarr[i] = String.valueOf(numbers[i]);
        }
        
        // 문자열을 더한 값이 큰 순서대로 정렬(내림차순)
        Arrays.sort(sarr, new Comparator<String>(){
            @Override
            public int compare(String s1, String s2){
                 return (s2 + s1).compareTo(s1 + s2);
            }
        });
         
        if(sarr[0].equals("0")) return "0";
        
        for(String s : sarr){
            sb.append(s);
        }
        
        answer = sb.toString();
        return answer;
    }
}