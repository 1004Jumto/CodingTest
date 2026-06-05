import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;

        Arrays.sort(citations);

        // 논문 개수
        int n = citations.length;

        // 논문 개수가 하나인 경우는 바로 리턴
        if (n < 2)
            return citations[0];

        // 최대 인용 수부터 1씩 감소하면서 검사
        for (int i = citations[n - 1]; i >= 1; i--) {
            int hIndex = i;

            // n편 중 hIndex편 이상이 존재해야하므로
            // n - hIndex 번째 논문의 인용 횟수를 검사
            if (hIndex <= n && citations[n - hIndex] >= hIndex) {
                answer = hIndex;
                break;
            }
        }

        // System.out.println(Arrays.toString(citations));
        return answer;
    }
}