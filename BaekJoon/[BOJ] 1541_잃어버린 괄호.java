package java1541;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 최대한 음수로 만든다
// - 를 기준으로 나누어 덧셈을 먼저하고 맨 나중에 -로 음수를 만든다
public class Main {
    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       
        String str = br.readLine();
        String[] arr = str.split("-");

        int sum = 0;
        for(int i = 0; i < arr.length; i++){
            
            String[] addStr = arr[i].split("\\+");
            
            // 첫번째 덩이는 더해주기
            if(i == 0){ 
                for(String s: addStr){
                    sum += Integer.parseInt(s);
                }
            }else{      // 나머지는 모두 마이너스
                for(String s: addStr){
                    sum -= Integer.parseInt(s);
                }
            }
        }

        System.out.println(sum);
    }
}
