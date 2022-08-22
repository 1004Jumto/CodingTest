#include<iostream>
#include<algorithm>

using namespace std;


int main(void) {
	int N;
	cin >> N;

	float sum = 0;
	float mean;
	int median, mode, distance;
	int max;

	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	mean = sum / N;						//���
	
	sort(arr, arr + N);
	max = arr[N - 1];

	distance = arr[N - 1] - arr[0];		//����
	median = arr[N / 2];				//�߾Ӱ�
	mode = whatIsMode( &arr,N);

	cout << fixed;
	cout.precision(0);
	cout << mean << "\n";
	cout << median << "\n" << mode << "\n" << distance << "\n";
	return 0;

}

int whatIsMode(const int* arr[], int len) {

	int tmp[8001] = { 0 };
	int cnt = 0;
	int index, mode;

	//tmp�� �ε��� = arr�� ����
	//tmp �� = ����
	for (int i = 0; i < len; i++) {
		tmp[*arr[i]+4000]++;
	}
	
	//tmp �ִ� ���ϱ�
	for (int i = 0; i < 8001; i++) {
		if (tmp[i] > cnt) {
			cnt = tmp[i];
			index = i;
		}
	}
	mode = *arr[index-4000];			//�ֺ�
	
	sort(tmp, tmp + 8001);		//�����ϰ�

	

	return;

}