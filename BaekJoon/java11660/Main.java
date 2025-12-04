package java11660;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int sum = 0;
        int[][] arr = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j <= N; j++) {
                if(j == 0) {arr[i][j] = sum; continue;}
                arr[i][j] = sum + Integer.parseInt(st.nextToken());
                sum = arr[i][j];
            }
        }
        for (int[] a : arr)
            System.out.println(Arrays.toString(a));

        // M번만큼 반복하여 부분합 sysout
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            // 부분합을 구해야하는데..
            // 아 귀찮아
            int res = 0;
            for(int k = x1; k <= x2; k++){
                res += arr[k][y2] - arr[k][y1 - 1];
            }
            // if(y1 == 0) res = arr[x2][y2] - arr[x2][y1 - 1] + arr[x1][y2] - arr[x1][y1 -
            // 1];
            // else res = arr[x2][y2] - arr[x2][y1 - 1] + arr[x1][y2] - arr[x1][y1 - 1];

            System.out.println(res);

        }

        br.close();
    }

}