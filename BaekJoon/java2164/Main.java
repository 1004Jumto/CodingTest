package java2164;
 
import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); 
        Queue<Integer> q = new LinkedList<>();

        // 큐 초기화
        for(int i = 1; i <= N; i++) q.offer(i);

        // q에 하나의 원소만 남을 때까지 반복 
        while (q.size() > 1) {
                q.poll(); 
                q.offer(q.peek());
                q.poll();
        }

        System.out.println(q.peek()); 

        sc.close();
    }
}