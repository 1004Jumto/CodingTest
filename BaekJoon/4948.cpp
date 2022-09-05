/*
	 [���� 4948] ����Ʈ�� ����
	  22-08-27 / c++

	  < �˰��� >

	  �ƶ��׽��׳׽��� ü�� ����Ͽ� �Ҽ� ������ ī��Ʈ�Ѵ�

 */

#include <iostream>
#include <string>

using namespace std;


int CountPrimeNumberSieve(int start, int end)
{
    int cnt = 0;
    int* num = new int[end + 1];

    //�迭 �ʱ�ȭ
    for (int i = 0; i <= end; i++) {
        num[i] = i;
    }

    //2���� ����� �����ش�
    for (int i = 2; i <= end; i++)
    {
        //num[i] �� 0�̸� �̹� �Ҽ��� �ƴϹǷ� continue
        if (num[i] == 0)
            continue;

        for (int j = 2 * i; j <= end; j += i)
            num[j] = 0;
    }

    //1�� �Ҽ��� �ƴϹǷ� ����ó��
    num[1] = 0;

    //ī��Ʈ
    for (int k = start + 1; k <= end; k++) {
        if (num[k] != 0) {
            cnt++;
        }
    }
    return cnt;
}


int main(void) {

    while (true) {
	    int iTESTCASE;
	    cin >> iTESTCASE;
	
        if (iTESTCASE != 0) {

            cout << CountPrimeNumberSieve(iTESTCASE, 2 * iTESTCASE) << "\n";
        }

        else
            break;
    }
    return 0;
}