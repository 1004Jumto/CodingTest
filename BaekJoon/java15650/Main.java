package java15650;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1 ~ N 까지 M개의 수를 뽑아야함
 * 일단 생각해볼 수 있는 건 1~N까지 for문을 M번 도는것 -> 코드상으로 불가
 * 대신 생각해볼 수 있는 방법 -> 재귀 -> M개의 숫자를 뽑는 것을 반복한다
 * 
 * 아래 코드의 시간복잡도 O(C(N, M)) -> 조합 개수만큼 시간이 걸림(불필요한 경우를 탐색하지 않음)
 */
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()); 

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] arr = new int[M];

        // 주어진 범위 내에서 숫자를 하나 고르는 함수
        pickNum(M, 0, arr, 1, N);

    }

    // 주어진 범위 내에서 숫자를 하나 뽑고, 원하는 개수만큼 다 뽑았다면 출력
    // @param 뽑으려는 숫자 개수, 현재 뽑은 숫자 개수, 뽑은 숫자를 저장한 배열, 범위(start ~ N)
    private static void pickNum(int depth, int cur, int[] picked, int start, int end) {
        // M개만큼 뽑았으면 출력
        if (cur == depth) {
            for (int n : picked) {
                System.out.print(n + " ");
            }
            System.out.println();
            return;
        }

        // 범위 내에서 하나 뽑기
        for (int i = start; i <= end; i++) {
            picked[cur] = i;
            pickNum(depth, cur + 1, picked, i + 1, end);
        }

    }

}