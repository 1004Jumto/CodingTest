package java14501;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());

        int[] income = new int[N + 2];
        int[] T = new int[N + 1];
        int[] P = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken());
            int pay = Integer.parseInt(st.nextToken());
            T[i] = time;
            P[i] = pay;
        }

        for(int i = 1; i<=N; i++){
            // 상담 가능한 경우
            if(i + T[i] - 1 <= N){
                income[i+T[i]] = Math.max(income[i+T[i]], income[i] + P[i]);
            }

            income[i+1] = Math.max(income[i+1], income[i]);
        }

        System.out.println(income[N+1]);

    }

}
