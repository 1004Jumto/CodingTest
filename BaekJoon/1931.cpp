#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {

	int N;
	cin >> N;

	vector<pair<int, int>> time;

	// �Է¹ޱ�
	for (int i = 0; i < N; i++) {	
		int startTime, endTime;
		cin >> startTime >> endTime;
		
		time.push_back(make_pair(endTime, startTime));
	}

	// ����
	sort(time.begin(), time.end());

	int start, end;
	
	// �ð�����
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