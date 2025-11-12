class Solution {
public:
    int compress(vector<char>& chars) {
        
        /*
        // 시간복잡도 O(N), 공간복잡도 O(N)
        int count = 0;
        string strres = "";

        if(chars.size() == 1) return 1;

        for(vector<char>::iterator iter = chars.begin(); iter < chars.end() - 1; iter++)
        {
            if(*iter == *(iter+1)) count++;                
            else
            {
                count++;
                strres.push_back(*iter);
                if(count > 1) strres.append(to_string(count));
                count = 0;
            }
        }
        // 마지막 원소 처리
        if(chars.back() == chars[chars.size() - 2])
        {
            strres.push_back(chars.back());
            strres.append(to_string(++count)); 
        }
        else strres.push_back(chars.back());
       
        chars.clear();
        for(int i = 0; i < strres.length(); i++)
        {
            chars.push_back(strres[i]);
        }


        return chars.size();

        */

        // 투 포인터 - 시간복잡도O(n), 공간복잡도O(1)
        int ireadIdx = 0, iwriteIdx = 0;
        int count = 0;

        // chars 배열 순회
        while(ireadIdx < chars.size())
        {
            char curr = chars[ireadIdx];

            // 이전과 문자값이 바뀔때까지
            while(ireadIdx < chars.size() && curr == chars[ireadIdx])
            {
                count++;
                ireadIdx++;
            }

            chars[iwriteIdx++] = curr;
           
            if(count > 1)
            {
                string s = to_string(count);
                for(char a : s)
                {
                    chars[iwriteIdx++] = a;
                }
            }

            count = 0;
            
        }

        return iwriteIdx;

    }
};