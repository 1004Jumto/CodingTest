class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());

        result[0] = 1;
        // 자신을 기준으로 왼쪽 값들을 곱한 값이 나오게 됨
        for(int i = 1; i < nums.size(); i++){
            result[i] = result[i-1] * nums[i-1];
        }

        // 자신을 기준으로 오른쪽 값들을 곱한 값이 나오게 됨
        int right = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            result[i] = result[i] * right;
            right *= nums[i];
        }




        return result;
    }
};