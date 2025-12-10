package java18258;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(st.nextToken());
        Queue<Integer> q = new LinkedList<>();

        int lastNum = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            switch (st.nextToken()) {
                case "push":
                    lastNum = Integer.parseInt(st.nextToken());
                    q.offer(lastNum);
                    break;

                case "pop":
                    if(q.isEmpty()) sb.append(-1 + "\n");
                    else sb.append(q.poll() + "\n"); 
                    break;

                case "size":
                    sb.append(q.size() + "\n");
                    break;

                case "empty":
                    if(q.isEmpty()) sb.append(1 + "\n");
                    else sb.append(0 + "\n");
                    break;

                case "front":
                    if(q.isEmpty()) sb.append(-1 + "\n");
                    else sb.append(q.peek() + "\n");
                    break;

                default:    //back
                    if(q.isEmpty()) sb.append(-1 + "\n");
                    else sb.append(lastNum + "\n");
                    break;
            }
        }

        System.out.println(sb);

    }
}