package java;
import java.util.Map;
import java.util.HashMap;
import java.lang.StringBuilder;

class Solution {
    public String[] solution(String[] record) {
        int resCount = 0;

        // 유저별로 닉네임 저장
        Map<String, String> userNickname = new HashMap<>();

        // record를 순회하면서 닉네임 저장 O(N)
        for (String str : record) {
            String[] sarr = str.split(" ");
            String type = sarr[0];

            if (type.equals("Enter")) {
                String id = sarr[1];
                String nickname = sarr[2];

                userNickname.put(id, nickname);
                resCount++;
            } else if (type.equals("Change")) {
                String id = sarr[1];
                String nickname = sarr[2];

                userNickname.put(id, nickname);

            } else {
                resCount++;
            }
        }

        String[] answer = new String[resCount];

        // record를 순회하면서 userNickname에 저장된 유저 닉네임을 적용하여 result 저장
        StringBuilder sb = new StringBuilder();

        for (int i = 0, idx = 0; i < record.length; i++) { // O(N)
            String[] sarr = record[i].split(" ");
            String type = sarr[0]; // Enter, Leave, Change
            String id = sarr[1]; // uid
            String nickname = userNickname.get(id);

            switch (type) {
                case "Enter":
                    sb.append(nickname + "님이 들어왔습니다.");
                    break;
                case "Leave":
                    sb.append(nickname + "님이 나갔습니다.");
                    break;
                default:
                    continue;
            }

            answer[idx++] = sb.toString();
            sb.setLength(0);
        }

        return answer;
    }
}