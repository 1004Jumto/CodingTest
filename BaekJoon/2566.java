package BaekJoon;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        int row = 0, col = 0;
        int maxVal = 0;
        
        Scanner sc = new Scanner(System.in);
        int[][] arr = new int[9][9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int val = sc.nextInt();
                arr[i][j] = val;
                if(maxVal <= val){
                    maxVal = val;
                    row = i + 1;
                    col = j + 1;
                } 
            }
        }

        System.out.println(maxVal);
        System.out.println(row + " " + col);

    }
}
