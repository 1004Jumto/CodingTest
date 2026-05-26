package java;
import java.util.Queue;
import java.util.ArrayList;
import java.util.LinkedList;

public class Solution {

    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Truck answer = new Truck(0);

        Queue<Truck> waiting = new LinkedList<>(); // 대기열
        Queue<Truck> bridge = new LinkedList<>();  // 현재 다리 상태

        int curTime = 0;    // 현재 시점
        int curWeight = 0;  // 현재 다리 무게

        // 대기열 초기화
        for (int i = 0; i < truck_weights.length; i++) {
            Truck t = new Truck(truck_weights[i]);
            waiting.offer(t);
        }

        // 대기열이 빌 때까지(모두 다 건널때까지) 반복
        while (!waiting.isEmpty()) {
            Truck next = waiting.peek(); // 대기열에 있는 다음 순서 트럭

            // 다리가 비어있는 경우는 바로 대기 트럭 진입
            if (bridge.isEmpty()) {
                bridge.offer(next);
                waiting.poll(); // 대기열에서 제거
                curWeight += next.weight;
                next.endTime = curTime + bridge_length;
                curTime++;

                answer = next;

                continue;
            }

            // 다 건넌 트럭 빼주기
            if (curTime == bridge.peek().endTime) {
                Truck now = bridge.poll();
                curWeight -= now.weight;
            }

            // 새로운 트럭이 못 들어가는 경우
            if (next.weight + curWeight > weight || bridge.size() > bridge_length) {
                Truck truck = bridge.poll();
                curTime = truck.endTime; // 다음에 바로 빠질 수 있도록 curTime 조정
                curWeight -= truck.weight;

                answer = next;
                continue;
            }

            bridge.offer(next);
            waiting.poll(); // 대기열에서 제거
            curWeight += next.weight;
            next.endTime = curTime + bridge_length;
            curTime++;
            answer = next;

        }

        return answer.endTime + 1;
    }
}

class Truck {
    public int weight;
    public int endTime; 

    public Truck(int weight) {
        this.weight = weight; 
    }
}