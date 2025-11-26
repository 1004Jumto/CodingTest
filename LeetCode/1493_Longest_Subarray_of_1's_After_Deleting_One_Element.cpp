class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int right, left = 0;
        int zero = 0;
        int length = 0;

        for(right = 0; right < nums.size(); right++){
            if(nums[right] == 0) zero++;

            while(zero > 1){
                if(nums[left] == 0) zero--;
                left++;
            }
            length = max(length, right - left);

        }

        return length;
    }
};