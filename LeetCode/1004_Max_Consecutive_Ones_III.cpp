#include <vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCnt = 0;
        int left = 0, right = 0;
        int maxCnt = 0;
        
        // 오른쪽은 윈도우 확장. 
        // 왼쪽은 윈도우 시작지점으로 이동.
        for(right = 0; right < nums.size(); right++){
            if(nums[right] == 0) zeroCnt++;

            while(zeroCnt > k){
                if(nums[left] == 0) zeroCnt--;
                left++;
            } 

            maxCnt = max(maxCnt, right - left + 1);
        }

        return maxCnt;
    }
};