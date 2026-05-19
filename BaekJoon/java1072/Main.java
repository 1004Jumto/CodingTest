package java1072;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
* 이진탐색 힌트: 특정 조건을 만족하는 최대/최소값 + 어마무시한 입력 크기
* 현재 문제에서는 게임을 해야하는 최소 횟수
* 게임 횟수 X 최대 10억

* "이제 형택이는 앞으로의 모든 게임에서 지지 않는다" -> 개멋있다ㄷㄷ

* 승률 Z = Y / X * 100 -> Y * 100 / X
* 탐색대상: 추가 게임 횟수(mid)
* start = 0
* end 
* -> 최악의 경우, 승률이 변하려면 n이 어느 정도까지 갈 수 있는가?
* -> end는 "정답이 반드시 이 안에 들어온다"만 보장하면 됨
* 승률이 100이 되려면 X == Y 이어야함 -> 즉, 승률이 99 이상이면 바뀔 수 없음
*/
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long answer = -1;

        // 게임 횟수
        long gameX = Integer.parseInt(st.nextToken());

        // 승리 횟수
        long winY = Integer.parseInt(st.nextToken());

        // 원래는 double로 변환 후 계산, 그 후 다시 int로 변환했으나
        // 부동소수점 이슈로 long 사용 및 winY * 100으로 곱셈 먼저 해줌
        long rateZ = (winY * 100 / gameX);

        // 예외: Z가 99 이상이면 승률 바뀌기 어려움
        if (rateZ >= 99) {
            System.out.println("-1");
            return;
        }

        long start = 0;
        long end = 1000000000; // 최대한 큰 수로 함. X 크기가 10억이라 10억으로 함

        while (start <= end) {
            long mid = (start + end) / 2;
            long newRate = (winY + mid) * 100 / (gameX + mid);

            if (newRate > rateZ) {
                // 성공
                answer = mid;
                end = mid - 1;
            } else {
                // 실패
                start = mid + 1;
            }
        }

        System.out.println(answer);

    }
}