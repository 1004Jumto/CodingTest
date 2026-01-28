 
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int solution(String s) {
        int answer = 0;
        List<String[]> li = new ArrayList<>();
        li.add(new String[] {"zero", "0"});
        li.add(new String[] {"one", "1"});
        li.add(new String[] {"two", "2"});
        li.add(new String[] {"three", "3"});
        li.add(new String[] {"four", "4"});
        li.add(new String[] {"five", "5"});
        li.add(new String[] {"six", "6"});
        li.add(new String[] {"seven", "7"});
        li.add(new String[] {"eight", "8"});
        li.add(new String[] {"nine", "9"});
        
        
        for(int i = 0; i < li.size(); i++){
            s = s.replaceAll(li.get(i)[0],li.get(i)[1]);
            System.out.println(s);       
        }
        
        answer = Integer.parseInt(s);
        return answer;
    }
}