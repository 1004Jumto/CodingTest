package java10773;

import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = Integer.parseInt(sc.nextLine());

        // 숫자 입력받아서 stack에 저장
        // 0인 경우 pop
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i< N; i++){
            int n = sc.nextInt();
            if(n == 0) st.pop();
            else st.push(n);
        }
        System.out.println(st);

        // stack 순회하면서 합
        int sum = 0;
        for(Integer i : st){
            sum += i;
        }
        System.out.println(sum);
        
        sc.close();

    }
}
