/*
	 [���� 1212] 8���� 2����
	  22-09-06 / c++

	  < ���� >

	  8������ 2������ �����Ͻÿ�

	  < �˰��� >

	  �� ���� �������� ���� �� �ڸ��� �������� ��ȯ�� ��
	  �̾���δ�

 */

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(void) {
	string oc;
	cin >> oc;

	if (oc == "0") {
		cout << 0 << "\n";
	}

	string res;
	for (int i = 0; i < oc.length(); i++) {
		res += to_string((oc[i] - '0') / 4);
		res += to_string(((oc[i] - '0') % 4) / 2);
		res += to_string((((oc[i] - '0') % 4) % 2) / 1);

	}

	bool flag = false;
	for (int i = 0; i < res.length(); i++) {
		if (!flag) {
			if (res[i] == '1') {
				flag = true;
				cout << res[i];
			}
		}
		else {
			cout << res[i];
		}
	}
	cout << "\n";

	return 0;
}