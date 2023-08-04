/*
* [백준 1477] 휴게소 세우기
* 다솜이는 유료 고속도로를 가지고 있다. 다솜이는 현재 고속도로에 휴게소를 N개 가지고 있는데, 휴게소의 위치는 고속도로의 시작으로부터 얼만큼 떨어져 있는지로 주어진다. 다솜이는 지금 휴게소를 M개 더 세우려고 한다.

* 다솜이는 이미 휴게소가 있는 곳에 휴게소를 또 세울 수 없고, 고속도로의 끝에도 휴게소를 세울 수 없다. 휴게소는 정수 위치에만 세울 수 있다.

* 다솜이는 이 고속도로를 이용할 때, 모든 휴게소를 방문한다. 다솜이는 휴게소를 M개 더 지어서 휴게소가 없는 구간의 길이의 최댓값을 최소로 하려고 한다. (반드시 M개를 모두 지어야 한다.)

* 예를 들어, 고속도로의 길이가 1000이고, 현재 휴게소가 {200, 701, 800}에 있고, 휴게소를 1개 더 세우려고 한다고 해보자.

* 일단, 지금 이 고속도로를 타고 달릴 때, 휴게소가 없는 구간의 최댓값은 200~701구간인 501이다. 하지만, 새로운 휴게소를 451구간에 짓게 되면, 최대가 251이 되어서 최소가 된다.
*
* [알고리즘]
* 이분 탐색/ 매개 변수 탐색
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, L;			// 휴게소 개수, 더 지으려는 휴게소 개수, 고속도로 길이
	vector<int> locations;	// 휴게소 위치

	cin >> N >> M >> L;
	locations.push_back(0);
	locations.push_back(L);
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		locations.push_back(tmp);
	}
	sort(locations.begin(), locations.end());

	int low = 0; int high = L;
	int mid, res = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		
		int count = 0;
		for (int i = 1; i < locations.size(); i++) {
			int dist = locations[i] - locations[i - 1];
			count += (dist / mid);
			if (dist % mid == 0) count--;
		}
		if (count > M) low = mid + 1;
		else {
			high = mid - 1;
			res = mid;
		}
	}
	cout << res;

	return 0;

}