class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // 단어 길이가 더 짧은 단어 기준으로 번갈아가면서 문자를 합침
        int minSize = word1.length() <= word2.length() ? word1.length() : word2.length();
        string longerStr = word1.length() <= word2.length() ? word2 : word1;

        string answer = "";
        answer.reserve(word1.length() + word2.length()); // 미리 메모리 확보

        for (int i = 0; i < minSize; i++)
        {
            answer.push_back(word1[i]); // 효율적으로 문자 추가
            answer.push_back(word2[i]);
        }  

        // 나머지 부분을 split해서 뒤에 붙임  
        if(longerStr.length() > minSize)  answer.append(longerStr.substr(minSize));

        return answer;
    }
};