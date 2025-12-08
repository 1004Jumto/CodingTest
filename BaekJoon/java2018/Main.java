package java2018;
 
import java.util.Scanner;

/* 2018 수들의 합 5 실버5*/
public class Main {

    /*
    * 구간 합 + 투포인터
    * 시간복잡도: 한 번 순회하므로 O(N) N은 최대 1000만
    * 유동적인 범위에 따라 값이 찾는 값(target)인지 확인하기 위해 투 포인터 사용
    * 
    * 어떤 구간의 합을 아는 방법은 arr[end]-arr[start-1]
    * start, end를 정의
    * 처음 인덱스부터 시작하여 구간합 계산 -> 이 때, 합이 찾는 수보다 크면 합을 줄여야하므로 start++
    *                                   -> 합이 찾는 수보다 작으면 합을 증가시켜야하므로 end++
    *                                   -> target이면 count++ 후 end++
    * end 범위와 start < end 범위 고려
    */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] arr = new int[N + 1];
        for (int i = 1; i <= N; i++)
            arr[i] = i + arr[i - 1]; 

        int start = 1;
        int end = 1;
        int count = 0;
        while (start <= end && end < N + 1) {
            int sum = arr[end] - arr[start - 1];
            if (sum == N) {
                count++;
                end++;
            } 
            else if (sum < N) end++;
            else start++;

        }

        System.out.println(count);
        sc.close();
    }

}