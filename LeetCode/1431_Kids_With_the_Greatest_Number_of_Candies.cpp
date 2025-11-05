class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> answer(candies.size());

        // 배열 중 가장 큰 수를 찾는다
        int greatest = *max_element(candies.begin(), candies.end());

        // 가장 큰 수와 차이값이 extra보다 크면 false
        for(int i = 0; i < candies.size(); i++){
            if((greatest - candies[i]) > extraCandies){
                answer[i] = false;
            } 
            else answer[i] = true;
        } 

        return answer;
    }

     
};