#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int whatIsMode(const int arr[], int len) {

	int tmp[8001] = { 0 };
	int max, cnt = 0;
	int mode;

	//tmp의 인덱스 = arr의 숫자
	//tmp 값 = 개수
	for (int i = 0; i < len; i++) {
		tmp[arr[i] + 4000]++;
	}

	max = *max_element(tmp, tmp + 8001);
	for (int i = 0; i < 8001; i++) {
		if (tmp[i] == max) {
			cnt++;		//가장 큰 값이 나온 횟수를 올려준다. 두번째값을 구해야하므로
			mode = i - 4000;

			if (cnt == 2) {
				break;
			}
		}
	}
	return mode;
}

int main(void) {
	int N;
	cin >> N;

	double sum = 0;
	int mean;						//평균
	int median, mode, distance;		//중앙값, 최빈값, 범위

	int* arr = new int[N];

	//배열 값 입력받기
	for (int i = 0; i < N; i++) {		
		cin >> arr[i];
		sum += arr[i];		//값의 합
	}

	mean = round(sum / N);			//평균

	sort(arr, arr + N);		//배열 정렬

	distance = arr[N - 1] - arr[0];		//범위
	median = arr[(N-1) / 2];			//중앙값 0~N-1중 가운데값 (N은 홀수)
	mode = whatIsMode(arr,N);		//최빈값

	cout << mean << "\n";
	cout << median << "\n" << mode << "\n" << distance << "\n";

	delete[]arr;

	return 0;

}
