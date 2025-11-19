class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;

        // 오름차순 정렬 NlogN
        sort(nums.begin(), nums.end());

        // 순회 -> 탐색
        int left = 0; 
        int right = nums.size()-1;

        /*
        * 정렬 후 가장 큰 값과 작은 값의 합이 k가 맞는지 검사
        * sum > k 이면 sum이 작아져야 하므로 right--. 그 반대 sum < k 또한 마찬가지 left++
        * 
        */
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == k){
                count++;
                left++; right--;
            }
            else if(sum > k) right--;
            else left++;
        }

        return count;
    }
};