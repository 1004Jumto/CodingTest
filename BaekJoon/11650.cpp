#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
   
    vector<vector<int>> dot;

    for (int i = 0; i < N; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        vector<int> tmp;
        tmp.push_back(tmp1);
        tmp.push_back(tmp2);
        
        dot.push_back(tmp);
    }
    
    sort(dot.begin(), dot.end());

    for (int i = 0; i < dot.size(); i++) {
        cout << dot[i][0] << " " << dot[i][1] << "\n";
    }

    return 0;
}