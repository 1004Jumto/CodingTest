package java9663;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = Integer.parseInt(sc.nextLine());
        int count = 0;
        int[] board = new int[N];

        int answer = backtrack(board, N, count);

        System.out.println(answer);
    }

    private static int backtrack(int[] board, int n, int row) {

        // 모두 둔 경우
        if (n == row) {
            return 1;
        }

        int count = 0;

        // 한 행에 퀸은 하나만 둔다 -> 열과 대각선만 검사
        for (int col = 0; col < n; col++) {
            board[row] = col;

            if (isAvailable(board, row)) {
                count += backtrack(board, n, row + 1);
            }
        }

        return count;

    }

    private static boolean isAvailable(int[] board, int row) {
        for (int i = 0; i < row; i++) {
            if (board[row] == board[i]) {
                return false;
            }

            if (Math.abs(board[row] - board[i]) == row - i) {
                return false;
            }
        }

        return true;
    }

}
