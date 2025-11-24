class Solution {
public: 
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int maxCount = 0;
        int count = 0;
        int left = 0, right = k;
        string vowels = "aeiou";
        
        // 맨 처음 부분배열만 모음 개수 확인
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])) count++;
        }
        maxCount = count;

        while(right < s.length()){
            // 오른쪽에 모음이 있으면 개수에 하나 추가
            if(isVowel(s[right++])) {
                count++;
            }

            // 왼쪽이 모음이었다면 개수에서 하나 빼기(count가 0인지 확인?)
            if(isVowel(s[left++])) {
                count--;
            }
            maxCount = max(maxCount, count);
        }
        
        
        // 맨 처음 부분배열만 모음 개수 확인
        // for(int i = 0; i < k; i++){
        //     if(vowels.find(s[i]) != string::npos) count++;
        // }
        // maxCount = count;

        // while(right < s.length()){
        //     // 오른쪽에 모음이 있으면 개수에 하나 추가
        //     if(vowels.find(s[right++]) != string::npos){
        //         count++;
        //     }

        //     // 왼쪽이 모음이었다면 개수에서 하나 빼기(count가 0인지 확인?)
        //     if(vowels.find(s[left++]) != string::npos){
        //         count--;
        //     }
        //     maxCount = max(maxCount, count);
        // }

        return maxCount;
    } 
};