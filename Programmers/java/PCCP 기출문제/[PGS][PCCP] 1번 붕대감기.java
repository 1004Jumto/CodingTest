class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        
        // 변수 초기화
        int answer = 0;
        int hp = health;
        int serial = 0;
        boolean isAttack = false;
        int time = 0;
        int len = attacks.length;
        int idx = 0;
         
        // 몬스터의 마지막 공격 시간까지 시간 증가
        for(time = 1; time <= attacks[len - 1][0]; time++) { 
            
            isAttack = false;
            
            // 몬스터 공격 유무 확인
            if(time == attacks[idx][0]) isAttack = true;
            
            // 공격 안 한 경우
            if(!isAttack) {
                
                serial++;           // 연속 성공 증가
                hp += bandage[1];   // 현재 체력 증가
                
                // 연속 성공한 경우
                if(serial == bandage[0]) {
                    hp += bandage[2];   // 체력 추가 회복
                    serial = 0;         // 연속 성공 초기화
                }
                
                // 최대치 이상인 경우 최대치로 초기화
                if(hp > health) hp = health;
                
            }
            else{             // 공격한 경우
                serial = 0;                 // 연속 성공 초기화
                hp -= attacks[idx][1];      // 데미지
                idx++;                      // 공격 순서 다음으로 넘어감
            } 
            
            
            // 만약 체력이 바닥난 경우
            if(hp <= 0) return -1;
            
        }
        
        
        return answer = hp;
    }
}