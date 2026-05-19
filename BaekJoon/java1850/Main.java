package java1850;
 
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long N = sc.nextLong();
        long M = sc.nextLong();

        long gcd = getGCD(N, M);
        
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < gcd; i++){
            sb.append("1");
        }

        System.out.println(sb);
    }

    private static long getGCD(long n, long m){
        while(m !=0){
            long temp = n % m;
            n = m;
            m = temp;
        }

        return n;
    }
}
