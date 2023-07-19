/*
* [백준 1759] 암호 만들기
* 바로 어제 최백준 조교가 방 열쇠를 주머니에 넣은 채 깜빡하고 서울로 가 버리는 황당한 상황에 직면한 조교들은,
* 702호에 새로운 보안 시스템을 설치하기로 하였다. 
* 이 보안 시스템은 열쇠가 아닌 암호로 동작하게 되어 있는 시스템이다.

* 암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음(a, e, i, o, u)과 
* 최소 두 개의 자음으로 구성되어 있다고 알려져 있다. 
* 또한 정렬된 문자열을 선호하는 조교들의 성향으로 미루어 보아 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었을 것이라고 추측된다. 즉, abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.

* 새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는 C가지가 있다고 한다. 
* 이 알파벳을 입수한 민식, 영식 형제는 조교들의 방에 침투하기 위해 암호를 추측해 보려고 한다. 
* C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램을 작성하시오.

* [알고리즘]
* 완전탐색 알고리즘 : 가능한 모든 경우의 수를 모투 체크해 정답을 찾는 방법
* 그리디와 자꾸 헷갈릴 때가 있는데, 그리디는 현 로컬 시점에서 최적해를 따라 최종적 해답에 이르는 방법이고,
* 완전 탐색은 정말 경우 하나하나 다 따져보는 방법
*
* 주어진 문자들을 정렬한다
* 깊이 우선 탐색을 시작한다
* 배열 첫부분부터 시작하여 탐색할 때 배열에 집어넣고 L개 만큼 문자가 들어오면 자음/모음 개수 조건을 검사하고 
* 부울을 반환한다
*/

#include<iostream>	
#include<algorithm>
#include<vector>
#include<string>	

using namespace std;

int L, C;
vector<char> characters;
vector<char> res;

bool isOkay() {
	int vowel = 0;
	for (int i = 0; i < L; i++) {
		if (res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u') vowel++;
	}
	if (vowel >= 1 && (L - vowel) >= 2)return true;
	return false;
}

void DFS(int n) {
	if (res.size() == L) {
		if (isOkay()) {
			for (int i = 0; i < L; i++)cout << res[i];
			cout << endl;
		}
		return;
	}
	for (int i = n; i < C; i++) {
		res.push_back(characters[i]);
		DFS(i + 1);
		res.pop_back();
	}
	return;
}

int main(void) {
	cin >> L >> C;;

	for (int i = 0; i < C; i++) {
		char c; cin >> c;
		characters.push_back(c);
	}
	sort(characters.begin(), characters.end());
	DFS(0);

	return 0;
}