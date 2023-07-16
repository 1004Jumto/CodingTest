/*
* [백준 12919] A와B 2
* 수빈이는 A와 B로만 이루어진 영어 단어 존재한다는 사실에 놀랐다. 
* 대표적인 예로 AB (Abdominal의 약자), BAA (양의 울음 소리), AA (용암의 종류), ABBA (스웨덴 팝 그룹)이 있다.

* 이런 사실에 놀란 수빈이는 간단한 게임을 만들기로 했다. 두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임이다
* 문자열을 바꿀 때는 다음과 같은 두 가지 연산만 가능하다.

* 문자열의 뒤에 A를 추가한다.
* 문자열의 뒤에 B를 추가하고 문자열을 뒤집는다. 
* 주어진 조건을 이용해서 S를 T로 만들 수 있는지 없는지 알아내는 프로그램을 작성하시오. 

* [알고리즘]
* 완전탐색 알고리즘 : 가능한 모든 경우의 수를 모투 체크해 정답을 찾는 방법
* 그리디와 자꾸 헷갈릴 때가 있는데, 그리디는 현 로컬 시점에서 최적해를 따라 최종적 해답에 이르는 방법이고, 
* 완전 탐색은 정말 경우 하나하나 다 따져보는 방법
* 
* 이 문제도 처음부터 A혹은 B를 붙이고 뒤집으며 S를 T로 만들기 보단 반대로 역추적하는 것이 더 효율적일 것 같다.
* T의 마지막 문자가 A면 없애준다
* T의 첫번째 문자가 B면 문자열을 뒤집고 마지막 B를 없애준다 <-- 얘를 첫번째로 해줘야하는건가?
* 
* 
*/

#include<iostream>	
#include<algorithm>
#include<vector>
#include<string>	

using namespace std;

void toAB(string s, string t) {
	if (s == t) {
		cout << 1;
		exit(0);
	}
	if (s.size() >= t.size()) return;
	if (t[t.size() - 1] == 'A') {
		string tmp = t;
		tmp.erase(tmp.size() - 1);
		toAB(s, tmp);
	}
	if (t[0] == 'B') {
		string tmp = t;
		tmp.erase(tmp.begin());
		reverse(tmp.begin(), tmp.end());
		toAB(s, tmp);
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL);	cout.tie(NULL);

	string S, T;
	cin >> S >> T;
	toAB(S, T);
	cout << 0;

	return 0;
}

/*
* t를 가지고 변경하면 곤란함
* else if가 아닌 else를 사용해야함
*/