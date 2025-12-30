package java1920;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
* 가장 먼저 떠오르는 방법은 하나씩 모두 확인해보는 방법으로 O(N*M) 최악의 경우 10만 * 10만 = 100억 -> 시간초과
* 
* 이진탐색
* - 시간복잡도: O(logN) -> 매 단계마다 탐색 범위가 절반으로 줄어듬 (N -> N/2 -> N/4 -> ... -> 1)
* - 공간복잡도: 반복문 O(1) / 재귀 O(logN) 호출스택
* - 필수 조건: 데이터 정렬
* - 이진 탐색 힌트: 정답이 특정 조건을 만족하는 최소/최대값
*/
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        // N개의 정수 입력받기 (정수 배열 입력받는 방법1 - stream)
        int N = Integer.parseInt(st.nextToken());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        // arr 정렬
        Arrays.sort(arr);

        // M개의 정수 입력받기 - 이 수들이 arr에 있는지 유무 검사하게 됨
        // (정수 배열 입력받는 방법2 - st.nextToken)
        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int[] targets = new int[M];
        for (int i = 0; i < M; i++) {
            targets[i] = Integer.parseInt(st.nextToken());
        }

        // arr안에 targets 숫자가 있는지 검사
        for (int target : targets) {
            if (check(target, arr))
                sb.append("1");
            else
                sb.append("0");

            sb.append("\n");
        }

        System.out.println(sb);

    }

    // arr에 num이 있는지 검사
    private static boolean check(int target, int[] arr) {
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == target)
                return true;
            else if (arr[mid] < target) {
                start = mid + 1;
            } else
                end = mid - 1;
        }

        return false;
    }

}