#include <string>
#include <vector>

using namespace std;

// 아스키코드 활용
// a = 97 ~ z = 122
// A = 65 ~ Z = 90
string solution(string s, int n) {
    for(int i=0; i<n; i++){
        string answer = "";
        for(char c : s){
            if(c == ' ') answer += " ";
            else if(c == 'z') answer += "a";
            else if(c == 'Z') answer += "A";
            else answer += (c + 1);
        }    
        s = answer;
    }
    
    return s;
}