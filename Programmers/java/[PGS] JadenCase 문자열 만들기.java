import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";

        // 전체 소문자로 변경
        s = s.toLowerCase();

        // 공백 기준 분리
        String[] words = s.split(" ");
        for (int i = 0; i < words.length; i++) {
            if (words[i].length() != 0 && !Character.isDigit(words[i].charAt(0))) {
                words[i] = words[i].substring(0, 1).toUpperCase() + words[i].substring(1);
            }
        }

        // System.out.println(Arrays.toString(words));

        // 문자열 배열 합치기
        answer = String.join(" ", words);

        // 문자열 맨 뒤의 공백들 추가
        int re = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == ' ')
                re++;
            else
                break;
        }

        answer += " ".repeat(re);
        return answer;
    }
}