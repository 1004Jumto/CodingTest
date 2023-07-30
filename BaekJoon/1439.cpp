/*
* [백준 1439] 뒤집기
* 다솜이는 0과 1로만 이루어진 문자열 S를 가지고 있다. 
* 다솜이는 이 문자열 S에 있는 모든 숫자를 전부 같게 만들려고 한다. 
* 다솜이가 할 수 있는 행동은 S에서 연속된 하나 이상의 숫자를 잡고 모두 뒤집는 것이다. 
* 뒤집는 것은 1을 0으로, 0을 1로 바꾸는 것을 의미한다.

* 예를 들어 S=0001100 일 때,

* 전체를 뒤집으면 1110011이 된다.
* 4번째 문자부터 5번째 문자까지 뒤집으면 1111111이 되어서 2번 만에 모두 같은 숫자로 만들 수 있다.
* 하지만, 처음부터 4번째 문자부터 5번째 문자까지 문자를 뒤집으면 한 번에 0000000이 되어서 1번 만에 모두 같은 숫자로 만들 수 있다.

* 문자열 S가 주어졌을 때, 다솜이가 해야하는 행동의 최소 횟수를 출력하시오.
*
* [알고리즘]
* 문자열 다루는 문제이다. 
* 입력받은 문자열에서 0과1의 개수를 센다음 더 적은 수의 숫자를 뒤집기 시작한다
* 개수를 세어놓고, 중복되는 문자열을 모두 없앤다음(001101 --> 0101) 더 적은 숫자의 개수를 센다. 
* 
* 노노 이거 순서 반대로 해야될듯
*/

#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input; cin >> input;
	int zero = 0, one = 0;
	int min;
	string str = "";

	// 중복 없애주기 
	for (int i = 0; i < input.length() - 1; i++) {
		if (input[i] != input[i+1]) {
			str += input[i];
		}
	}
	str += input[input.size()-1];
	
	// 숫자 세기
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0')zero++;
		else one++;
	}
	min = zero < one ? zero : one;
	cout << min;
	

	return 0;
}