class Solution {
    public int solution(String[][] board, int h, int w) {
        int answer = 0;
        
        String color = board[h][w];
        int len = board.length;
        int[] dh = {0, 1, -1, 0};
        int[] dw = {1, 0, 0, -1}; 
        
        for(int i=0; i<4; i++){
            int curH = h + dh[i];
            int curW = w + dw[i]; 
            if(curH < len && curH >= 0 && curW < len && curW >= 0 && color.equals(board[curH][curW])) answer++; 
        }
        
        return answer;
    }
}