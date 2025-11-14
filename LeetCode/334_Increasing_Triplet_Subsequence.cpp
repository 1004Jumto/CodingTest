#include <vector>
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // 첫번째, 두번째, 세번째 큰 수
        int min = INT_MAX, mid = INT_MAX;

        /*
        순회 시 현재 숫자가 min 보다 작으면 현재 숫자를 min으로 저장
        min보다는 크고 중간값보다 작으면 현재 숫자를 중간값으로 저장
        min 보다 크면 증가하는 순열이 완성되므로 true 리턴.
        */
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            if(*it <= min) min = *it;
            else if(*it <= mid) mid = *it;
            else if(*it > mid) return true;
        }
        
        return false;

    }
};


/* 해당 알고리즘 설명
이 알고리즘에서 min과 mid는 실제 증가하는 수열 (a, b, c)를 구성하는 최종 a와 b 값이 아닐 수 있으며, 
단지 a < b < c  조건을 만족하는 트리거(Trigger) 역할을 합니다.

핵심은 다음과 같습니다.
 -> mid가 설정되는 순간 (nums[j])어떤 원소 B가 mid로 설정되는 순간, 
    이는 B가 이전에 설정된 min 값 A보다 크다는 것을 의미합니다.
    A = \text{min} (설정 인덱스 i)B = \text{mid} (설정 인덱스 j)

 -> 보증: A < B 이고 i < j 인 (A, B) 쌍이 반드시 존재합니다. 
 (만약 B가 A보다 먼저 나왔다면, B가 먼저 min이 되었을 것이고 A가 B를 덮어쓰지 않았을 것입니다.)

*/