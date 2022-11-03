#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> babble;
    string tmp = "";

    for (int i = 0; i < babbling.size(); i++) {
        for (int j = 0; j < babbling[i].length(); j++) {
            tmp = tmp + babbling[i][j];
            if (tmp == "aya" || tmp == "ye" || tmp == "woo" || tmp == "ma") {
                babble.push_back(tmp);
                tmp = "";
            }
            

        }
    }

    return answer;
}

int main(void) {
    vector<string> bab = {"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"};
    cout << solution(bab);

    return 0;
}