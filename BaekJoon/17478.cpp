/*
	 [���� 17478] ����Լ��� ������?
	  22-08-05 / c++

	  < �˰��� >

	  ����Լ�

 */

#include<iostream>
#include<string>

using namespace std;

void WhatIsRecurFunc(int n, int k) {
	string str1 = "\"����Լ��� ������?\"\n";
	string str2 = "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	string str3 = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	string str4 = "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\" \n";
	string str5 = "��� �亯�Ͽ���.\n";
	string str6 = "____";
	string str7 = "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";

	if (n == 0) {
		return;
	}
	

	for (int i = 1; i < k; i++) {
		str6 = str6 + "____";
	}

	str1 = str6 + str1;
	str2 = str6 + str2;
	str3 = str6 + str3;
	str4 = str6 + str4;
	str5 = str6 + str5;
	str7 = str6 + str7;
	
	if (n == 1) {
		cout << str1 << str7 << str5;
		return;
	}

	cout << str1 << str2 << str3 << str4;

	WhatIsRecurFunc(n - 1, ++k);

	cout << str5;

	return;

}

int main(void) {
	int N;
	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	cout << "\"����Լ��� ������?\"\n";
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

	WhatIsRecurFunc(N, 1);

	cout << "��� �亯�Ͽ���.\n";
	return 0;
}