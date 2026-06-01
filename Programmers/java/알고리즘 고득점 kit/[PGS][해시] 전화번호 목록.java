/*
이중 for문으로 N^2는 불가
길이 100만 * 문자열 최대 길이 20 -> O(M*N)

1. 문자열 배열 순회
2. 하나의 String에 대해 순회
-> substring으로 0,i 까지의 문자열이 set에 포함되어 있는지 확인
-> 있으면 바로 return false
-> 없으면 set에 추가

이 때 정렬 필요 -> 문자열 길이가 짧~길 순으로 정렬
*/

import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        Set<String> set = new HashSet<>();
        
        // 배열 정렬(문자열 길이 기준 오름차순)
        Arrays.sort(phone_book, new Comparator<String>(){
            // @override
            public int compare(String s1, String s2){
                return s1.length() - s2.length();
            }
        });
        /* 문자열배열 -> 리스트로 바꿔서 Collections.sort()사용
        List<String> list = new ArrayList<>();
        list = Arrays.asList(phone_book);
        */
        
        // 문자열 배열 순회하면서 접두어 검사
        set.add(phone_book[0]);
        for(int i = 1; i < phone_book.length; i++){
            for(int j = 0; j <= phone_book[i - 1].length(); j++){                 
                if(set.contains(phone_book[i].substring(0, j))){
                    return false;
                }
            }
            // set에 없으면 문자열을 접두어로 추가
            set.add(phone_book[i]); 
        }
        
        /*
        // 문자열 배열 순회하면서 접두어 검사
        for(String s : phone_book){
            for(int i = 0; i <= s.length(); i++){                 
                if(set.contains(s.substring(0, i))){
                    return false;
                }
            }
            // set에 없으면 문자열을 접두어로 추가
            set.add(s); 
        }
        */
        
        
        return answer;
    }
    
    /* 최적화 답안
    
    Arrays.sort(phone_book);

    for(int i = 0; i < phone_book.length - 1; i++){
        if(phone_book[i+1].startsWith(phone_book[i])){
            return false;
        }
    }
    return true;
    */
}