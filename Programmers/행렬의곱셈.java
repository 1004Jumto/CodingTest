import java.util.Arrays;

class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int[][] answer = new int[arr1.length][arr2[0].length];
        
        for(int row = 0; row < arr1.length; row++){
            for(int col = 0; col < arr2[0].length; col++){
                int arr1Idx = 0, arr2Idx = 0;
                while(arr1Idx < arr1[0].length && arr2Idx < arr2.length){
                    answer[row][col] += (arr1[row][arr1Idx] * arr2[arr2Idx][col]);
                    arr1Idx++;
                    arr2Idx++;
                }
            }
        }
        for(int[] is : answer) System.out.println(Arrays.toString(is));
        
        
        return answer;
    }
}