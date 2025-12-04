package java2018;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] arr = new int[N + 1];
        for (int i = 1; i <= N; i++)
            arr[i] = i + arr[i - 1];
        System.out.println(Arrays.toString(arr));
        // int start = 1;
        // int end = 1;
        // int count = 0;
        // while (start <= end && end < N + 1) {
        //     int sum = arr[end] - arr[start - 1];
        //     if (sum == N) count++;
        //     else if (sum < N) end++;
        //     else start++;

        // }

        // System.out.println(count);
        sc.close();
    }     

}