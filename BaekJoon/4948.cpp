/*
	 [백준 4948] 베르트랑 공준
	  22-08-27 / c++

	  < 알고리즘 >

	  아라테스테네스의 체를 사용하여 소수 개수를 카운트한다

 */

#include <iostream>
#include <string>

using namespace std;


int CountPrimeNumberSieve(int start, int end)
{
    int cnt = 0;
    int* num = new int[end + 1];

    //배열 초기화
    for (int i = 0; i <= end; i++) {
        num[i] = i;
    }

    //2부터 배수를 지워준다
    for (int i = 2; i <= end; i++)
    {
        //num[i] 가 0이면 이미 소수가 아니므로 continue
        if (num[i] == 0)
            continue;

        for (int j = 2 * i; j <= end; j += i)
            num[j] = 0;
    }

    //1은 소수가 아니므로 예외처리
    num[1] = 0;

    //카운트
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