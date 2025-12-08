package java1253; 

import java.util.Arrays;
import java.util.Scanner;
 
/* 백준 좋다 골드4 */
public class Main {
    /*
    * 배열을 순회하며 각 원소가 좋은 수 인지 판단
    * 한 원소가 좋은 수 인지 판단하기 위해서 투포인터를 사용해 배열 전체 범위에서 합이 되는 두 수를 탐색
    * 
    * 배열 탐색 전 정렬 필수(오름차순)  O(NlogN)
    * 타겟이 되는 숫자를 포함해서 두 숫자를 찾은 경우는 카운트하지 않음 -> start와 겹쳤다면 start++ / end는 반대로
    * 숫자의 최대 크기는 10억이므로 최대 합은 20억 -> int 사용 가능
    * 시간복잡도는 숫자의 최대 개수가 2000개 -> for문 돌면서 투포인터로 탐색하므로 최악기준 O(N^2) -> 400만 번의 연산
    */
    
    public static void main(String[] args) {
        int count = 0;

        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        int[] arr = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();


        // 오름차순 정렬 필수
        Arrays.sort(arr);

        // 배열 순회하면서 좋은 수인지 판단
        for(int i = 0; i < N; i++){
            int target = arr[i];
            int start = 0;
            int end = N - 1;

            // 합이 되는 두 수 탐색
            while(start < end){
                int sum = arr[start] + arr[end];
                if(target == sum) {
                    if(i != start && i != end) {
                        count++;
                        break;
                    }
                    else if(i == start){
                        start++;
                    }
                    else if(i == end){
                        end--;
                    }
                }
                else if(target < sum) end--;
                else start++;
            }
        }

        System.out.println(count);
        sc.close();

        return;
    }

}
