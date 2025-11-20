class Solution {
    public String decodeString(String s) {
        StringBuilder sb = new StringBuilder();
        Stack<Integer> nSt = new Stack<>();
        Stack<StringBuilder> sSt = new Stack<>();
        int num = 0;

            for(char c : s.toCharArray()){
                // when character is num
                if(Character.isDigit(c)){
                    num = num * 10 + (c - '0');
                }
                // when c is [
                else if(c == '['){
                    nSt.push(num);      // store num in stack
                    num = 0;
                    sSt.push(sb);       // store str in stack
                    sb = new StringBuilder();
                }
                // when c is ]
                else if(c == ']'){
                    int k = nSt.pop();
                    StringBuilder str = sb;
                    sb = sSt.pop();
                    while(k-- > 0) sb.append(str);
                }
                // when c is normal alphabet
                else sb.append(c);

            }


        return sb.toString();
    }
}