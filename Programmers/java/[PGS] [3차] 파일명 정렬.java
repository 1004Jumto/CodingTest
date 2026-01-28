package java;
/*
0. HEAD와 NUMBER 파싱
1. HEAD 기준으로 문자열 정렬
2. NUMBER 기준으로 오름차순 정렬
*/

import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String[] solution(String[] files) {
        String[] answer = new String[files.length];

        Arrays.sort(files, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                int head1EndIdx = getHeadEndIdx(0, s1);
                int head2EndIdx = getHeadEndIdx(0, s2);
                String head1 = s1.substring(0, head1EndIdx).toLowerCase();
                String head2 = s2.substring(0, head2EndIdx).toLowerCase();

                int num1EndIdx = getNumEndIdx(head1EndIdx, s1);
                int num2EndIdx = getNumEndIdx(head2EndIdx, s2);
                int number1 = Integer.parseInt(s1.substring(head1EndIdx, num1EndIdx));
                int number2 = Integer.parseInt(s2.substring(head2EndIdx, num2EndIdx));

                // System.out.println(head1 + ":" + head2);
                // System.out.println(number1 + ":" + number2);

                if (head1.equals(head2))
                    return number1 - number2;

                return compareString(head1, head2);
            }
        });

        // System.out.println(Arrays.toString(files));

        return files;
    }

    private int compareString(String s1, String s2) {
        if (s1.equals(s2))
            return 0;

        int len = s1.length() >= s2.length() ? s2.length() : s1.length();

        for (int i = 0; i < len; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                return s1.charAt(i) - s2.charAt(i);
            }
        }

        return s1.length() - s2.length();
    }

    private int getHeadEndIdx(int startIdx, String str) {
        for (int i = startIdx; i < str.length(); i++) {
            if (Character.isDigit(str.charAt(i))) {
                return i;
            }
        }

        return str.length();
    }

    private int getNumEndIdx(int startIdx, String str) {
        for (int i = startIdx; i < str.length(); i++) {
            if (!Character.isDigit(str.charAt(i))) {
                return i;
            }
        }

        return str.length();
    }
}