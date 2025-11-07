class Solution {
public:
    string reverseVowels(string s) {

        vector<pair<int, char>> v;
        // 어느 자리에 어느 문자가 있는지 벡터2차원으로 저장
        for (int i = 0; i < s.length(); i++) {
            if (tolower(s[i]) == 'a' || tolower(s[i]) == 'i' ||
                tolower(s[i]) == 'u' || tolower(s[i]) == 'e' ||
                tolower(s[i]) == 'o') 
            {
                v.push_back(make_pair(i, s[i])); 
            }
        }

        // 저장된 목록에 따라 문자 바꿔치기
        for (int i = 0; i < v.size() / 2; i++)
        {
            s[v[i].first] = v[v.size()-i-1].second;
            s[v[v.size()-i-1].first] = v[i].second;
        }

        return s;
    }
};