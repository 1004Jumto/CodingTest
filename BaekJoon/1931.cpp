#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {

	int N;
	cin >> N;

	vector<vector<int>> time;

	// 입력받기
	for (int i = 0; i < N; i++) {	
		int startTime, endTime;
		cin >> startTime >> endTime;
		
		vector<int> tmp;
		
		tmp.push_back(startTime);
		tmp.push_back(endTime);
		time.push_back(tmp);
	}

	// 정렬
	sort(time.begin(), time.end());

	int start, end;
	
	// 시간결정
	start;
	end = 0;
	int count = 1;

	for (int i = 0; i < time.size(); i++) {
		if (end <= time[i][0]) {
			count++;
			start = time[i][0];
			end = time[i][1];
		}
	}
	
	cout << count;

	return 0;
}