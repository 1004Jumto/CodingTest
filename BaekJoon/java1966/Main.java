package java1966;
 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

 
public class Main {
     
    
    public static void main(String[] args) throws IOException { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> o1 - o2);
        int testcase = Integer.parseInt(st.nextToken());

        for(int i = 0; i<testcase; i++){
            // 문서 개수, target문서 인덱스
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            // 우선순위 큐에 N개 수 삽입
            for(int j = 0; j < N; j++){
                st = new StringTokenizer(br.readLine());
                pq.offer(Integer.parseInt(st.nextToken()));
            }

        }


        return;
    }

}
