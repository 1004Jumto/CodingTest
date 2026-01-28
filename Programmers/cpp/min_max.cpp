#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void split(string str, char delimiter, vector<int> des) {
    string s_tmp = "";

    // str을 mark 기준으로 나눠서 des에 넣을거임
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != delimiter) {
            s_tmp += str[i];
        }
        else {
            des.push_back(stoi(s_tmp));
            s_tmp = "";
        }
    }
}

string solution(string s) {
    string answer = "";
    vector<int> num;

    // 공백 기준 split
    split(s,' ', num);

    // sort로 정렬
    sort(num.begin(), num.end());

    // 답 출력
    answer = to_string(num[0]) + " " + to_string(num[num.size() - 1]);

    return answer;
}

int main(void) {
    string str;
    cin >> str;

    string answer = solution(str);
    cout << answer;

    return 0;
}