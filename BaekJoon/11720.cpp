/*
	 [���� 11720] ������ ��
	  22-08-27 / c++

	  < �˰��� >

	  ���ڿ��� �Է¹޾� �ݺ����� �����鼭 �ϳ��� �����
	  ���������� ��ȯ���� ��� ���Ѵ�

 */

#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);;
	cout.tie(NULL);;

	int TESTCASE, iSum = 0;
	string str;

	cin >> TESTCASE;
	cin >> str;

	for (int i = 0; i < TESTCASE; i++) {
		int tmp = str[i] - '0';
		iSum += tmp;
	}

	cout << iSum;
	return 0;


}