/*
곱해서 yellow가 되는 두 수를 구하여, 그 때의 brown 수를 구한다 
*/
class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = {};
        
        for(int i = 1; i <= Math.sqrt(yellow); i++){
            if(yellow % i == 0){
                int width = yellow / i;
                int height = i;
                if(brown == ((width+height) * 2 + 4)) {
                    answer = new int[]{width + 2, height + 2};
                    break;
                }
            }    
        }
        
        
        return answer;
    }
}