package java11004;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;  

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);
        System.out.println(arr[K-1]);

    }
    public String solution(int[] numbers) {
        String answer = "";
        StringBuilder sb = new StringBuilder();
        String[] sarr = new String[numbers.length];
        
        for(int i = 0; i < numbers.length; i++){
            sarr[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(sarr, Comparator.reverseOrder());
        
        System.out.println(Arrays.toString(sarr));

        return answer;
    }
}
