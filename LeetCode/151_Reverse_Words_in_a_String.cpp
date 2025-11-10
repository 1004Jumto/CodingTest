#include <sstream>

class Solution {
public:
    string reverseWords(string s) {
        string answer = "";
        answer.reserve(s.length());
        
        stringstream ss(s);
        vector<string> words;
        string word;

        // 공백 기준으로 나누어 배열에 삽입
        while(ss >> word)
        {
            words.push_back(word);
        }

        // 거꾸로 문자열 
        for(int i = words.size()-1; i >= 0; i--)
        {
            answer.append(words[i]);

            if(i > 0) answer.append(" ");
        }
        
        return answer;
    }
};