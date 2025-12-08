package java1940;

import java.util.Arrays;
import java.util.Scanner;

/* 1940 주몽 실버4 */
public class Main {

    /*
     * N개의 수들 중 두 수의 합이 M이 되는 pair의 개수를 출력하면 되는 문제
     * 가장 간단하면서 쉬운 방법은 이중 for문으로 완전 탐색하는 방법이다. 이 때, 시간복잡도는 O(NlogN) -> 충분히 가능
     *
     */
    /*
    public static void main(String[] args) {
        int count = 0;

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        
        // 완전 탐색으로 모든 경우의 수 확인
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (arr[i] + arr[j] == M) count++;
            }
        }
        System.out.println(count);

        sc.close();
    }
    */

    /* 
     * 투 포인터로 하는 방법(인덱스 순서 바뀌어도 되므로)
     * -> 배열을 입력받은 후 정렬
     * -> start, end를 두고 양쪽 끝에서부터 탐색
     * -> 이 때, 두 수의 합이 target보다 작을 경우 start++, 반대인 경우 end--, 찾은 경우 count++
    */

    public static void main(String[] args) {
        int count = 0;

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        sc.nextLine();  // 공백 제거
        
        int[] arr = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        
        // 정렬
        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr));

        int start = 0; 
        int end = N - 1;
        while(start <= end && end < N){
            int sum = arr[start] + arr[end];
            if(sum == M) { 
                count++;
                start++;
                end--; 
            }
            else if(sum < M) start++;
            else end--;
        }
        
        System.out.println(count);

        sc.close();
    }

}