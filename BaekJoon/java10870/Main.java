package java10870;

import java.util.Scanner; 

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = Integer.parseInt(sc.nextLine());

        System.out.println(fibonacci(N)); 
       
        
        sc.close();

    }

    private static int fibonacci(int num){
        if(num == 0) return 0;
        if(num == 1) return 1;
        return fibonacci(num-1) + fibonacci(num-2); 
    }
}
