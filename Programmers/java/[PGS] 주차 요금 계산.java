package java;
import java.util.Map;
import java.util.HashMap;
import java.util.TreeMap;

class Solution {
    public int[] solution(int[] fees, String[] records) {
        int[] answer;

        // 차량별로 누적 주차 시간 저장 - 이 때 차량번호로 정렬 필요
        Map<String, Integer> totalTime = new TreeMap<>();

        // 차량별로 시간을 저장 - 분단위로 변환하여 저장
        Map<String, Integer> stayTime = new HashMap<>();

        // records 순회
        for (String s : records) {

            String[] str = s.split(" ");
            int time = convertToMin(str[0]); // 입출차 시간
            String car = str[1]; // 차량 번호
            String type = str[2]; // IN, OUT

            // 차량이 입차하면 Map에 put
            if (type.equals("IN")) {
                stayTime.put(car, time);
            } else { // 차량이 출차하는 경우
                int inTime = stayTime.get(car); // 입차 시간
                int stay = time - inTime; // 머문 시간

                // 머문 시간 저장
                totalTime.put(car, totalTime.getOrDefault(car, 0) + stay);

                // 출차 뒤 시간은 -1로 변경
                stayTime.put(car, -1);
            }
        }

        // records을 모두 순회 후 Map을 순회하면서 value가 0이상인 차량을 검색
        // 해당 차량에 대해 23:59로 출차 시간 계산 후 요금 계산, total에 저장
        for (Map.Entry<String, Integer> entry : stayTime.entrySet()) {
            String key = entry.getKey();
            int val = entry.getValue();

            if (val > -1) {
                int inTime = val; // 입차 시간
                int stay = convertToMin("23:59") - inTime; // 머문 시간

                // 머문 시간 저장
                totalTime.put(key, totalTime.getOrDefault(key, 0) + stay);
            }
        }
        // System.out.println(totalTime);

        // totalTime을 순회하면서 요금 계산
        answer = new int[totalTime.size()];
        int idx = 0;
        for (Map.Entry<String, Integer> entry : totalTime.entrySet()) {
            String car = entry.getKey();
            int time = entry.getValue();

            // 요금 계산 후 저장
            answer[idx++] = calculateFee(fees, time);
        }

        return answer;
    }

    // HH:MM 형식으로 string 입력받아서 분으로 변환해주는 함수
    private int convertToMin(String s) {
        int res = 0;

        String[] time = s.split(":");
        int hour = Integer.parseInt(time[0]);
        int min = Integer.parseInt(time[1]);

        res = hour * 60 + min;

        return res;
    }

    // 요금 기준표와 시간(분) 입력받아 요금 계산하는 함수
    private int calculateFee(int[] fees, int min) {
        int res = 0;

        // 기본시간 이내이면 바로 기본 요금 리턴
        if (min <= fees[0])
            res = fees[1];
        else {
            double tmp = (double) (min - fees[0]) / fees[2];
            // System.out.println(Math.ceil(tmp));
            res = fees[1] + (int) Math.ceil(tmp) * fees[3];
        }

        return res;
    }
}