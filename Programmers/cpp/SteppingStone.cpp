#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isOkay(vector<int> stones, int mid, int k) {
    int limit = 0;
        
    for (int i = 0; i < stones.size(); i++) {   
        if (stones[i] <= mid) {
            limit += 1;
        }
        else {
            limit = 0;
        }
        
        if (limit >= k) {
            return false;   
        }        
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int begin = 1;
    int end;

    end = *max_element(stones.begin(), stones.end());   // 최대 수

    while (begin <= end) {
        int mid = (begin + end) / 2;

        if (!isOkay(stones, mid, k)) {  //건널수 없을때
            end = mid - 1;
        }

        else {                          //건널수 있을때
            begin = mid + 1;
        }
    }

    return begin;
}

int main(void) {
    vector<int> case1 = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    int k = 3;

    cout << solution(case1, k);

    return 0;
}