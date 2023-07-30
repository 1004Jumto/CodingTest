/*
* [���� 17609] ȸ��
* ȸ��(����) �Ǵ� �Ӹ����(palindrome)�� �� �� �������� �� �� ���� ������ ���ڷ� ������ ���ڿ��� ���Ѵ�. 
* ���� ��� ��abba�� ��kayak��, ��reviver��, ��madam���� ��� ȸ���̴�. ���� �� ��ü�� ȸ���� �ƴ����� �� ���ڸ� �����Ͽ� ȸ������ ���� �� �ִ� ���ڿ��̶�� �츮�� �̷� ���ڿ��� ������ȸ����(pseudo palindrome)�̶�� �θ���. 
* ���� ��� ��summuus���� 5��°�� Ȥ�� 6��° ���� ��u���� �����Ͽ� ��summus���� ȸ���� �ǹǷ� ����ȸ���̴�.

* �������� ���õ� ���ڿ��� �м��Ͽ� �װ��� �� ��ü�� ȸ������, �Ǵ� �� ���ڸ� �����ϸ� ȸ���� �Ǵ� ������ȸ��������, �ƴϸ� ȸ���̳� ����ȸ���� �ƴ� �Ϲ� ���ڿ������� �Ǵ��ؾ� �Ѵ�. 
* ���� ���ڿ� �� ��ü�� ȸ���̸� 0, ����ȸ���̸� 1, �� �ܴ� 2�� ����ؾ� �Ѵ�. 
* 
* [�˰���]
* ȸ������ ���� �Ǵ��Ѵ�. �Ǵ��ϴ� ������ �־ ����ȸ������ �Ǵ��Ѵ�.
* ����ȸ���� �Ǵ��� ���� ȸ������ �Ǵ��ϴ� ����(�� �հ� �� ���� ���� �񱳹ݺ�)���� ���ڰ� �ٸ��� �� ���ڸ� ������� ��, �� �� �������ڿ� ������ ���Ͽ� �Ǵ��Ѵ�
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

bool isPal(string s) {
	for (int i = 0; i < (s.length() / 2); i++) {
		if (s[i] != s[s.length() - i - 1]) return false;
	}
	return true;
}

bool isSubpal(string s) {
	int left = 0, right = s.size() - 1;
	while (left < right) {
		if (s[left] != s[right])return false;
		left++; right--;
	}
	return true;
}

int type(string s) {
	if (isSubpal(s)) return 0;
	int left = 0, right = s.size() - 1;

	while (left < right) {
		if (s[left] != s[right]) {
			if (isPal(s.substr(0, left) + s.substr(left + 1))) return 1;
			if (isPal(s.substr(0, right) + s.substr(right+ 1))) return 1;
			return 2;
		}
		left++; right--;
	}
	return 2;
}

int main(void) {
	int testcase;
	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		string s; cin >> s;
		int res = type(s);
		cout << res << "\n";
	}

	return 0;
}