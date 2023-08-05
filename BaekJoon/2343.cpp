/*
* [백준 2343] 기타레슨
* 강토는 자신의 기타 강의 동영상을 블루레이로 만들어 판매하려고 한다. 블루레이에는 총 N개의 강의가 들어가는데, 블루레이를 녹화할 때, 강의의 순서가 바뀌면 안 된다. 순서가 뒤바뀌는 경우에는 강의의 흐름이 끊겨, 학생들이 대혼란에 빠질 수 있기 때문이다. 즉, i번 강의와 j번 강의를 같은 블루레이에 녹화하려면 i와 j 사이의 모든 강의도 같은 블루레이에 녹화해야 한다.

* 강토는 이 블루레이가 얼마나 팔릴지 아직 알 수 없기 때문에, 블루레이의 개수를 가급적 줄이려고 한다. 오랜 고민 끝에 강토는 M개의 블루레이에 모든 기타 강의 동영상을 녹화하기로 했다. 이때, 블루레이의 크기(녹화 가능한 길이)를 최소로 하려고 한다. 단, M개의 블루레이는 모두 같은 크기이어야 한다.

* 강토의 각 강의의 길이가 분 단위(자연수)로 주어진다. 이때, 가능한 블루레이의 크기 중 최소를 구하는 프로그램을 작성하시오.


*
* [알고리즘]
* 이분 탐색/ 매개 변수 탐색
* 
* 이분탐색에서 중요한 것은 mid의 결정과 low, high!
* 그리고 결정함수
* 
* 이 문제에선 블루레이 크기의 최소를 구하는 중이므로 mid를 블루레이 크기로 가정한다. 
* 이 때, low는 극단적으로 생각했을 때 강의 하나당 블루레이 하나에 배정되는 경우로 본다면 블루레이의 크기는 강의 시간중 가장 긴 강의시간만큼 되어야 한다. 
* 반대로 high는 모든 강의가 블루레이 하나에 배정되는 경우로 보고, 모든 강의시간을 합한 만큼의 크기의 블루레이가 있어야한다. 
* 
* 블루레이 개수가 M보다 크면 블루레이 크기를 늘려야하므로 low = mid+1, 
* 블루레이 개수가 M보다 작으면 블루레이 크기를 줄여야하므로 high = mid-1
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; cin >> N >> M;
	vector<int> LessonTimes;
	int high = 0;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		high += tmp;
		LessonTimes.push_back(tmp);
	}

	int low = *max_element(LessonTimes.begin(), LessonTimes.end());
	int mid, cnt, sum;		// cnt는 블루레이 개수, sum은 블루레이에 들어가는 강의 시간 합
	
	while (low <= high) {
		mid = (low + high) / 2;
		cnt = 0; sum = 0;

		for (int i = 0; i < N; i++) {
			if (sum + LessonTimes[i] > mid) {
				sum = 0;
				cnt++;
			}
			sum += LessonTimes[i];
		}
		if (sum != 0) cnt++;			// mid보다 커지기 전에 강의가 끝난 경우, 블루레이 하나 더해주어야함
		if (cnt <= M) high = mid - 1;	// M보다 같거나 작은 경우, 블루레이 크기를 줄여야함
		else low = mid + 1;
		

	}

	cout << low;
	return 0;
}