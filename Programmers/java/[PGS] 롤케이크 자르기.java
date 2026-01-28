/*
중복 허용X -> set
토핑의 가짓수 -> set.size()로 판별가능
topping 가짓수별 개수를 저장하는 배열
 
set 두 개를 사용해 topping을 한 번 순회하면서 비교
하나의 셋에 미리 topping을 모두 넣어놓고, for 로 topping을 순회하면서 다른 셋에 하나씩 추가
추가 후 배열에서 해당 토핑 개수-1, 두 셋의 크기 비교
*/
import java.util.Set;
import java.util.HashSet;
class Solution {
    public int solution(int[] topping) {
        int answer = -1;
        int count = 0;
        
        int[] toppingCount = new int[10001];
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        
        // topping 순회하면서 하나의 set에 모두 저장
        // 토핑 개수도 배열에 저장
        for(int i : topping){
            toppingCount[i]++;
            set1.add(i);
        }
        
        // topping 순회하면서 하나 씩 다른 배열로 move
        for(int i : topping){
            // 같은 토핑이 있는 경우, 더 없는 경우 구분
            if(toppingCount[i] > 1) {
                toppingCount[i]--;
            }
            else{
                set1.remove(i);
            }
            
            // 두번째 셋에 추가
            set2.add(i);
            
            // 가짓수 비교
            if(set1.size() == set2.size()) count++;
            // System.out.println(set1.size() + ": " + set2.size());
        }
        
        answer = count;
        return answer;
    }
}