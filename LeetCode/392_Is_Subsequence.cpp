class Solution {
public:
    bool isSubsequence(string s, string t) {
        // s를 순회
        // s의 첫글자를 탐색
        // 찾으면 해당 인덱스부터 다음 글자를 탐색
        int letterIdx = 0;
        int find = 0;
        for(int i = 0; i < s.length(); i++){
            while(letterIdx < t.length()){
                if(s[i] == t[letterIdx]){
                    letterIdx++;
                    find++;
                    break;
                }
                letterIdx++;
            }

        }

        if(find == s.length()) return true;

        return false;

    }
};