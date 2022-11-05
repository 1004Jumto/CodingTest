#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {

	int N;
	cin >> N;

	vector<pair<int, int>> time;

	// 입력받기
	for (int i = 0; i < N; i++) {	
		int startTime, endTime;
		cin >> startTime >> endTime;
		
		time.push_back(make_pair(endTime, startTime));
	}

	// 정렬
	sort(time.begin(), time.end());

	int start, end;
	
	// 시간결정
	end = time[0].first;
	int count = 1;

	for (int i = 1; i < time.size(); i++) {
		if (end <= time[i].second) {
			count++;
			end = time[i].first;
		}
	}
	
	cout << count;

	return 0;
}