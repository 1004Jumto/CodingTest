#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int whatIsMode(const int arr[], int len) {

	int tmp[8001] = { 0 };
	int max, cnt = 0;
	int mode;

	//tmp�� �ε��� = arr�� ����
	//tmp �� = ����
	for (int i = 0; i < len; i++) {
		tmp[arr[i] + 4000]++;
	}

	max = *max_element(tmp, tmp + 8001);
	for (int i = 0; i < 8001; i++) {
		if (tmp[i] == max) {
			cnt++;		//���� ū ���� ���� Ƚ���� �÷��ش�. �ι�°���� ���ؾ��ϹǷ�
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
	int mean;						//���
	int median, mode, distance;		//�߾Ӱ�, �ֺ�, ����

	int* arr = new int[N];

	//�迭 �� �Է¹ޱ�
	for (int i = 0; i < N; i++) {		
		cin >> arr[i];
		sum += arr[i];		//���� ��
	}

	mean = round(sum / N);			//���

	sort(arr, arr + N);		//�迭 ����

	distance = arr[N - 1] - arr[0];		//����
	median = arr[(N-1) / 2];			//�߾Ӱ� 0~N-1�� ����� (N�� Ȧ��)
	mode = whatIsMode(arr,N);		//�ֺ�

	cout << mean << "\n";
	cout << median << "\n" << mode << "\n" << distance << "\n";

	delete[]arr;

	return 0;

}
