class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg;

        // 가장 큰 평균을 구하려면 결국 합이 가장 커야함
        int left = 0;
        int right = k;
        int sum = 0;
        int maxSum;

        // 맨 처음 합을 구함
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        maxSum = sum;

        // 양쪽 끝을 빼고 더한 합을 비교하면서 최대값을 찾음
        while(right < nums.size()){ 
            sum = sum - nums[left] + nums[right];
            maxSum = max(maxSum, sum);
            left++; right++;
        }

        maxAvg = (double)maxSum / (double)k;
        return maxAvg;

    }
};