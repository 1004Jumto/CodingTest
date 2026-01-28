#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<vector<string>> park, int row, int col, int size);

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    // 추후 가능한 크기를 더 빠르게 결정하기 위해 오름차순 정렬
    sort(mats.begin(), mats.end());
    
    // 돗자리마다 가능한지 확인
    for(int i = 0; i < mats.size(); i++){
        int m = mats[i];
        
        // 공원을 순회하며 -1인 공간을 탐색
        for(int h = 0; h < park.size(); h++){
            for(int w = 0; w < park[0].size(); w++){
                if(park[h][w].compare("-1")) continue;
                
                // -1 인 공간을 발견하면 공석 크기를 확인해보는 함수 실행
                answer = max(answer, check(park, h, w, m));
                
            }
        } 
    }
    return answer;
}

int check(vector<vector<string>> park, int row, int col, int size){
    // 범위를 벗어났으면 불가하므로 리턴
    if(row + size > park.size() || col + size > park[0].size()) return -1;
    
    // row, col 기준으로 size만큼 공석인지 확인
    for(int dx = 0; dx < size; dx++){
        for(int dy = 0; dy < size; dy++){
            // 한자리라도 중간이 공석이 아니면 불가하므로 리턴 
            if(park[row+dx][col+dy] != "-1") return -1;
        }
    }
    return size;
    
}