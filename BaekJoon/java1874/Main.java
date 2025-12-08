package java1874;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        // 입력 var
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        // var
        int N = Integer.parseInt(br.readLine());
        Stack<Integer> st = new Stack<>();
        // 입력받은 수들을 저장하는 배열
        int[] nums = new int[N];        
        // 배열에 int 값 저장
        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(br.readLine());
        }

        // cur은 1부터 N까지의 숫자
        // i는 nums의 인덱스 변수
        // nums[] 순회
        int cur = 1;
        int i = 0;
        while (i < N) {
            // 현재 숫자가 목표하는 nums보다 작으면 계속 푸시
            if (nums[i] > cur) {
                while (nums[i] > cur) {
                    st.push(cur);
                    sb.append("+\n");
                    cur++;
                }

            } 
            // 현재 숫자가 목표 nums와 같으면 푸시 후 팝
            else if (nums[i] == cur) {
                st.push(cur);
                st.pop();
                sb.append("+\n-\n");
                cur++;
                i++;
            } 
            // 현재 숫자가 목표 nums보다 크면 스택에서 pop
            // 이 때, peek가 nums와 다르면 그대로 NO
            else {
                if (st.peek() != nums[i]) {
                    System.out.println("NO");
                    return;
                } else {
                    sb.append("-\n");
                    st.pop();
                    i++;
                }

            }
            // System.out.println(st + " : " + sb);
            // System.out.println("cur=" + cur);
            // System.out.println("num=" + nums[i]);
        }
         
        System.out.println(sb);

    }
}
