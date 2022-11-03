#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> cloth;

    // 종류별로 옷 분류한 뒤 개수 세기
    for (int i = 0; i < clothes.size(); i++) {
        if (cloth.find(clothes[i][1]) == cloth.end()) {
            cloth.insert(make_pair(clothes[i][1], 1));
        }
        else {
            cloth[clothes[i][1]]++;
        }
    }

    // 경우의 수 세기
    for (auto iter = cloth.begin(); iter != cloth.end(); ++iter) {
        answer = answer * (iter->second + 1);
    }

    answer -= 1;

    return answer;
}