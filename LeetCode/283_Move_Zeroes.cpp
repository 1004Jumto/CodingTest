class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
      

        // 하나는 0이 아닌 숫자를 찾고, 하나는 탐색한 숫자를 대입할 인덱스
        int write = 0, read = 0;

        // 0이 아닌 숫자를 탐색
        // 0이 아닌 숫자를 찾으면, writeidx와 스왑
        for(read = 0; read < nums.size(); read++)
        {
            if(nums[read] != 0)
            {
                swap(nums[read], nums[write]);
                write++;
            }
        }


        /*
        // 하나는 0을 찾고, 하나는 0이 아닌 원소를 찾는 피벗
        int zeroIdx = 0;
        int numIdx = 0;

        // 0을 먼저 찾기 시작
        // 0을 찾으면, 그 자리부터 0이 아닌 원소를 찾는다
        // 스왑한다
        // 다시 0을 찾기 시작 반복
        int n = nums.size();
        while(zeroIdx < n)
        {
            if(0 == nums[zeroIdx])
            {
                numIdx = zeroIdx;
                while(numIdx < n && nums[numIdx] == 0)
                {
                    numIdx++;
                }

                // 스왑
                if(numIdx < n && nums[numIdx] != 0){
                    nums[zeroIdx] = nums[numIdx];
                    nums[numIdx] = 0;
    
                }
                 
            }
            zeroIdx++;
        }

        --> 0이 아닌 숫자를 찾아서 꼭 0의 자리에 대입할 필요 없다는 생각을 왜 못했지?
        */
    }
};