package BaekJoon;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int len = Integer.parseInt(sc.nextLine());
        int[] scores = new int[len];

        for (int i = 0; i < len; i++) scores[i] = sc.nextInt();
        
        Arrays.sort(scores);
        int max = scores[scores.length - 1];
        double sum = 0;
        for(int n : scores) sum += (n / (double)max * 100); 
        
        System.out.println(sum / len);
    }
}
