/*
	 [���� 25305] ĿƮ����
	  22-08-27 / c++

	  < �˰��� >

	  �迭�� ���� �ְ� sort�Լ��� ������ �� �ε����� ã���ش�


 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int TESTCASE, iCutLine;
	cin >> TESTCASE >> iCutLine;

	int* score = new int[TESTCASE];

	for (int i = 0; i < TESTCASE; i++) {
		cin >> score[i];
	}

	sort(score, score + TESTCASE);		//�������� ����

	cout << score[TESTCASE - iCutLine];

	

}