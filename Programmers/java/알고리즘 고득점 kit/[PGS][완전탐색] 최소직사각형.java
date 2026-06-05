class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        int maxW = 0;
        int maxH = 0;
        
        for(int[] size : sizes) {
            int w = Math.max(size[0], size[1]);
            int h = size[0] == w ? size[1] : size[0];
            
            maxW = Math.max(maxW, w);
            maxH = Math.max(maxH, h);
        }
        
        answer = maxW * maxH;
        
        
        return answer;
    }
}