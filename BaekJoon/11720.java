package BaekJoon;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int len = Integer.parseInt(sc.nextLine());
        String str = sc.nextLine();
        System.out.println(str.chars().map(c -> c-'0').sum());

    }
}
