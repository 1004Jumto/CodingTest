/*
* [백준 20300] 서강근육맨
* 로니 콜먼 동영상을 보고 보디빌더가 되기로 결심한 향빈이는 PT 상담을 받으러 서강헬스클럽에 갔다. 향빈이가 서강헬스클럽을 선택한 이유는 PT를 받을 때 사용하는 운동기구를 회원이 선택할 수 있다는 점 때문이다. 
* 하지만, 서강헬스클럽은 항상 사람이 많아서 PT를 한 번 받을 때 운동기구를 최대 두 개까지만 선택할 수 있다.
* 헬스장에 있는 N개의 운동기구를 한 번씩 사용해보고 싶은 향빈이는 PT를 받을 때마다 이전에 사용하지 않았던 운동기구를 선택하기로 계획을 세웠다. 
* 그리고 비용을 절약하기 위해 PT를 받을 때 운동기구를 되도록이면 두 개를 사용하기로 했다. 

* 예를 들어, 헬스장에 총 10개의 운동기구가 있을 경우 PT를 5번 받으면 모든 기구를 다 사용할 수 있다.
* 9개의 운동기구가 있는 경우에도 PT를 5번 받지만, 마지막 PT를 받을 때는 운동기구를 하나만 사용한다.

* 하지만 향빈이는 운동기구를 선택하다가 큰 고민에 빠졌다. 왜냐하면 운동기구마다 근손실이 일어나는 정도가 다르기 때문이다. 어떤 운동기구는 자극이 잘 안 와서 근손실이 적게 일어나는데, 
* 어떤 운동기구는 자극이 잘 와서 근손실이 많이 일어난다. 근손실이 죽음보다 무서운 향빈이는 PT를 한 번 받을 때의 근손실 정도가 M을 넘지 않도록 하고 싶다. 

* 이때, M의 최솟값을 구해보자. 
* 참고로, 운동기구를 두 개 사용해서 PT를 받을 때의 근손실 정도는 두 운동기구의 근손실 정도의 합이다.
*
* [알고리즘]
* 그리디 알고리즘 : 현재 시점에서 best performance를 내기 위한 step을 선택하는 알고리즘으로, 각 단계에서 최선의 선택을 통해 전체적으로 best performance를 수행하는 것이 목적이다.
*
* 하루에 두 개 선택할 수 있고, 결국 구하고자 하는 것은 두 개의 근손실 합의 최솟값이다.
* 최솟값이 되기 위해서는 큰 값과 작은 값을 pair하는 것이 유리하다. 
* 입력받은 배열을 오름차순으로 정렬시킨 뒤, 맨 앞과 뒤의 원소의 합들을 비교한다.
* 이 때, 운동기구가 홀수 개인 경우, 가장 근손실이 큰 운동기구는 한 개만 쓰는 것이 유리하다.
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long minM = 0;
	int N = 0;
	vector<long long> Ms;				// 하루 근손실
	vector<long long> loss;				// 각 운동기구 근손실

	// 근손실 입력받아 오름차순 정렬
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		long long tmp = 0;
		cin >> tmp;
		loss.push_back(tmp);
	}
	sort(loss.begin(), loss.end());

	if (N == 1) {
		cout << loss[0];
		return 0;
	}
	
	// 기구가 짝수개면 맨앞뒤 합, 홀수개면 맨 뒤를 제외한 합을 구해 Ms에 삽입
	if (N % 2 == 0) {
		for (int i = 0; i < (N / 2); i++) {
			Ms.push_back(loss[i] + loss[N - i - 1]);
		}
	}
	else {
		for (int i = 0; i < (N / 2); i++) {
			Ms.push_back(loss[i] + loss[N - i - 2]);
		}
		Ms.push_back(loss[loss.size() - 1]);
	}

	// 오름차순 정렬 후 가장 큰 값 출력
	sort(Ms.begin(), Ms.end());
	minM = Ms[Ms.size() - 1];
	
	cout << minM;

	return 0;
}