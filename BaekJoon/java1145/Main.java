package java1145;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(arr);

        int min = Integer.MAX_VALUE;

        // 모든 경우의 수의 최소공배수
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    int val = getLCM(arr[i], arr[j], arr[k]);
                    min = min < val ? min : val;
                }
            }
        }

        System.out.println(min);
        sc.close();

    }
    // 최소공배수는 
    /**
     *  30 = 2 3 5
     *  43 = 2 3 7
     *  70 = 2 5 7
     *  2 3 5 7
     */
    // 세 개의 수 최소공배수를 리턴한다
    // 두 수의 곱을 최대공약수로 나눈 수가 최대공배수가 됨
    private static int getLCM(int a, int b, int c) {
        int val = (a * b) / getGCD(a, b);
        
        return (val * c) / getGCD(val, c);
    }

    // 최대공약수를 구한다
    private static int getGCD(int a, int b) {

        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }
}
