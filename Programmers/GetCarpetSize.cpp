#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    /// <summary>
    /// ������������
    /// ������밥
    /// ������밥
    /// ������������
    /// 
    /// �� + �� = width * height
    /// (�� + 4) / 2 = width+height
    /// 
    int a = (brown + 4) / 2;
    int b = brown + yellow;

    for (int height = 3; ; height++) {
        if ((a - height) * height == b) {
            int width = a - height;
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }
    return answer;
}

int main(void) {
    int numOfBrown, numOfYellow;
    cin >> numOfBrown >> numOfYellow;
    
    cout << solution(numOfBrown, numOfYellow)[0] << solution(numOfBrown, numOfYellow)[1];

    return 0;
}