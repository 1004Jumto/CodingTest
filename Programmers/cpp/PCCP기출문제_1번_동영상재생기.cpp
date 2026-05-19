#include <string>
#include <vector>

using namespace std;

int convertToSec(string s);

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    // 초로 단위를 변환하여 검사?
    int vod = convertToSec(video_len);
    int cur = convertToSec(pos);
    int begin = convertToSec(op_start);
    int end = convertToSec(op_end);
    
    // command 순회하며 오프닝건뛰, prev, next 계산
    for(string comm : commands){
        // 오프닝 건너뛰기 검사
        if(begin <= cur && cur < end) cur = end;
        
        // prev, next 검사
        if(comm == "prev"){
            cur -= 10;
            if(cur < 10) cur = 0;
        }
        else if(comm == "next"){
            cur += 10;
            if(vod - cur < 10) cur = vod;
        }
        // 오프닝 건너뛰기 검사
        if(begin <= cur && cur < end) cur = end;
    }
    
    // cur을 다시 string으로 변환
    string smin, ssec;
    smin = to_string(cur / 60);
    if((cur / 60) < 10) smin = "0" + smin;
    ssec = to_string(cur % 60);
    if((cur % 60) < 10) ssec = "0" + ssec;
    answer = smin + ":" + ssec;
    
    // C++ 20 이전에 format 할 수 있는 방법
    char buf[6];
    sprintf(buf, "%02d:%02d", cur / 60, cur % 60);
    answer = string(buf);
    
    return answer;
}

int convertToSec(string s){ 
    int min = stoi(s.substr(0,2));
    int sec = stoi(s.substr(3,2));
    
    return min * 60 + sec;
}