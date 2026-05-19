import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class Person {
    public String lang;
    public String pos;
    public String exp;
    public String food;
    public int score;

    public Person(String lang, String pos, String exp, String food, int score) {
        this.lang = lang;
        this.pos = pos;
        this.exp = exp;
        this.food = food;
        this.score = score;
    }
}

class Solution {

    // info 저장할 리스트
    List<Person> infoList = new ArrayList<>();

    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];

        // info 대로 나누어서 사람들 저장
        for (String inf : info) {
            String[] temp = inf.split(" ");
            Person p = new Person(temp[0], temp[1], temp[2], temp[3], Integer.parseInt(temp[4]));
            infoList.add(p);
        }

        // query 실행 반복
        // 쿼리 해석 및 점수 리스트 생성
        // 점수 리스트에서 점수 이분탐색
        for (int i = 0; i < query.length; i++) {
            int ret = doQuery(query[i]);
            answer[i] = ret;
        }

        return answer;
    }

    // 쿼리 실행 후 결과값 리턴
    private int doQuery(String stmt) {
        int result = 0;

        // 쿼리 해석
        // and로 split 후 맨 마지막에서 score 따로 split
        String[] str = stmt.split(" and ");
        // System.out.println(Arrays.toString(str));
        String lang = str[0];
        String pos = str[1];
        String exp = str[2];

        String[] tmp = str[3].split(" ");
        String food = tmp[0];
        int score = Integer.parseInt(tmp[1]);

        // 점수 저장할 배열
        List<Integer> marks = new ArrayList<>();

        // info 순회하면서 해당하는 사람의 점수만 리스트에 삽입
        for (Person p : infoList) {
            if ((lang.equals("-") || lang.equals(p.lang))
                    && (pos.equals("-") || pos.equals(p.pos))
                    && (exp.equals("-") || exp.equals(p.exp))
                    && (food.equals("-") || food.equals(p.food))) {
                marks.add(p.score);
            }
        }

        // 점수 정렬
        Collections.sort(marks);

        // 점수 이진탐색
        int start = 0;
        int end = marks.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (marks.get(mid) < score) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        // System.out.println("target=" + target + ": mid=" + result);
        result = marks.size() - end;

        // System.out.println(marks);
        return result;
    }
}