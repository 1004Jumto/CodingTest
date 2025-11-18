class Solution {
public:
    int maxArea(vector<int>& height) {
        int currentMax = 0;
        
        int left = 0;
        int right = height.size()-1;

        // while(left < right)
        // { 
        //     currentMax = max(currentMax, (right-left)*min(height[right], height[left]));
        //     if(height[left] < height[right]) left++;
        //     else right--;
        // }

        // return currentMax;

        while(left < right){
            currentMax = max(currentMax, (right-left)*min(height[right], height[left]));
            if(height[left] < height[right]){
                int tmp = height[left];
                //왼쪽을 오른쪽보다 큰 애가 나올때까지 옮김
                while(height[left] <= tmp && left < right) left++;
            }
            else{
                int tmp = height[right];
                while(tmp >= height[right] && right > left) right--;
            }
        }

        return currentMax;
    }
};