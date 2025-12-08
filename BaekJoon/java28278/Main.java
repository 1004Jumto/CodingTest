package java28278;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader; 
import java.util.Stack;
import java.util.StringTokenizer;

/*
시간 초과로 StringBuilder 사용 필요
 */
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        Stack<Integer> st = new Stack<>();

        int N = Integer.parseInt(bf.readLine());
        
        for (int i = 0; i < N; i++) {
            StringTokenizer tok = new StringTokenizer(bf.readLine());
            int opt = Integer.parseInt(tok.nextToken());
           
            switch (opt) {
                case 1:
                    st.push(Integer.parseInt(tok.nextToken())); 
                    break;
                case 2:
                    if(st.isEmpty()) sb.append(-1 + "\n");
                    else{
                        sb.append(st.pop() + "\n");
                    }
                    break;
                case 3:
                    sb.append(st.size() + "\n");
                    break;
                case 4:
                    if(st.isEmpty()) sb.append(1 + "\n");
                    else sb.append(0 + "\n");
                    break;
                case 5:
                    if(st.isEmpty()) sb.append(-1 + "\n");
                    else sb.append(st.peek() + "\n");
                    break;

                default:
                    break;
            }

        }

        System.out.println(sb);
 

    }
}
