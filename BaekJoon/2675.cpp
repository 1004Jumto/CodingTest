/*
	 [���� 2675] ���ڿ� �ݺ�
	  22-08-27 / c++

	  < �˰��� >

	  ���ڿ��� �Է¹ް�
	  �� ���ڿ� ������ �ݺ������� ������ ���ڿ��� �ٿ��ش�

 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int TESTCASE;
	cin >> TESTCASE;

	for (int i = 0; i < TESTCASE; i++) {
		
		int N;
		string Str;
		cin >> N >> Str;
		for (int j = 0; j < Str.length(); j++) {
			for (int k = 0; k < N; k++) {
				cout << Str[j];
			}
		}

		cout << "\n";
	}
    return 0;
}