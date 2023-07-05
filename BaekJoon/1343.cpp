/*
* /*
	 [���� 1343] �������̳�
	  23-07-06 / c++

	  < ���� >
		�ν��̴� ������ ���� �������̳� 2���� ���Ѱ���ŭ ������ �ִ�. AAAA�� BB.
		���� '.'�� 'X'�� �̷���� �������� �־����� ��, �ν��̴� ��ħ���� 'X'�� ��� �������̳�� �������� �Ѵ�. �̶�, '.'�� �������̳�� ������ �� �ȴ�.
		�������̳�� ��� ���� �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	  < �˰��� >
		�׸���
		
		X�� ������ ���鼭 �� �� �ִ� ����� ��(1,2,3,4)�� ������ ������� �����
		A�� B���� �켱�Ǿ�� �ϹǷ�, X�� 4�� ��츦 ���� �����ش�.
		X�� 1 �Ǵ� 3�̰�, �� ���� ���ڰ� X�� �ƴϸ� -1�� ����Ѵ�.
 */

#include<iostream>
#include<string>

using namespace std;

#define	POLYOMINO_1 "AAAA"
#define	POLYOMINO_2 "BB"

int main(void) {
	int cntX = 0;		// X ����
	string res = "";	// result

	// �Է� ex) "XXXX.XX..XXXX" --> ��� "AAAA.BB..AAAA"
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'X') {
			cntX++;
			if (cntX == 4) {
				res += POLYOMINO_1;
				cntX = 0;
			}
			else if (cntX == 2 && str[i + 1] != 'X') {
				res += POLYOMINO_2;
				cntX = 0;
			}
			else if ((cntX == 3 || cntX == 1) && str[i + 1] != 'X') {
				break;
			}
		}
		else {
			res += '.';
		}
	}

	// X ������ Ȧ������ �� ���� �� �����Ƿ� -1
	if (cntX % 2 != 0) res = "-1";

	cout << res;
	return 0;
}