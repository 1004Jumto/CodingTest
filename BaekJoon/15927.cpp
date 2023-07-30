/*
* [���� 15927] ȸ���� ȸ���ƴϾ�!!
* �Ӹ�����̶� ������ ������ �ڷ� ������ ���� ���ڿ��� ���Ѵ�. �Ӹ������ ���÷� POP, ABBA ���� �ְ�, �Ӹ������ �ƴ� ���� ���÷� ABCA, PALINDROME ���� �ִ�.

* �ǹ̸� ������ ���� �ܾ���� ����.

	ȸ�� (�ѱ���)
	palindrome (����, ��������, �븣���̾�, �׸�����, ��ƾ��)
	palindrom (���Ͼ�, ����ũ��)
	palindromi (�ɶ����)
	palindromo (��Ż���ƾ�, ����������)

* ���� �̻��� ���� ������ �ʴ°�? �� � ������ �Ӹ������ ���ϴ� �ܾ�� �Ӹ������ �ƴϴ�! 
* ���� ������� �߱��ϴ� ����Ī�� �Ƹ��ٿ��� ���� ��� �Ұ��ϴ�.

* ���ĺ� �빮�ڷ� �̷���� ���ڿ��� �־����� ��, �Ӹ������ �ƴ� ���� �� �κй��ڿ��� ���̸� ���� ����. �̶� �κй��ڿ��� �̷�� ���ڴ� �����ؾ� �Ѵ�. AB�� ABCD�� �κй��ڿ�������, AC�� �ƴϴ�.
*
* [�˰���]
* ó���� ȸ������ �ƴ��� �Ǻ��ϰ� ȸ���� �ƴϸ� �״�� ���ڿ� ���̸� ��ȯ
* ȸ���� ��� �� �� Ȥ�� �� ���� �ϳ��� �����ص� ȸ���� ������ �ǹǷ� ���ڿ�����-1�� ��ȯ
* �� ��, ��� ���ڰ� ���� ��츦 ����Ͽ� ó�����־����
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

bool isOneChar(string s) {
	for (int i = 0; i < (s.length() / 2); i++) {
		if (s[i] != s[i+1]) return false;
	}
	return true;
}

int main(void) {
	string s; cin >> s;
	if (isOneChar(s)) cout << -1;
	else if (isPal(s)) cout << s.size() - 1;
	else cout << s.size();

	return 0;
}