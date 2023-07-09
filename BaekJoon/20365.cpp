/*
* [백준 20365] 블로그2
* neighbor 블로그를 운영하는 일우는 매일 아침 풀고 싶은 문제를 미리 정해놓고 글을 올린다.
* 그리고 매일 밤 각각의 문제에 대하여, 해결한 경우 파란색, 해결하지 못한 경우 빨간색으로 칠한다. 일우는 각 문제를 칠할 때 아래와 같은 과정을 한 번의 작업으로 수행한다.

* 연속된 임의의 문제들을 선택한다. 선택된 문제들을 전부 원하는 같은 색으로 칠한다.

* 예를 들어, 각 문제를 위와 같은 색으로 칠하려고 할 때, 1~2번 문제를 파란색, 3번을 빨간색, 4번을 파란색, 5번을 빨간색, 6~7번을 파란색, 8번을 빨간색으로 칠하는 작업을 순서대로 수행하면 6번의 작업을 거쳐야 한다.
* 하지만, 1~7번 문제를 파란색, 3번을 빨간색, 5번을 빨간색, 8번을 빨간색으로 순서대로 칠한다면 작업 횟수는 4번으로 가장 적다.

* 일우는 매일 500,000문제까지 시도하기 때문에, 이 작업이 꽤나 귀찮아지기 시작했다. 그래서 가장 효율적인 방법으로 위 작업을 수행하기를 원한다. 일우를 도와 각 문제를 주어진 색으로 칠할 때 필요한 최소한의 작업 횟수를 구하는 프로그램을 작성하라.

* [알고리즘]
* 그리디 알고리즘 : 현재 시점에서 best performance를 내기 위한 step을 선택하는 알고리즘으로, 각 단계에서 최선의 선택을 통해 전체적으로 best performance를 수행하는 것이 목적이다.
*
* 중복되어 있는 색을 하나로 합친다 (BBRBRRB -> BRBRB)
* 색을 카운팅하고 더 많은 색을 바탕으로 칠한다
* 적은 색 개수를 더해준다
*
*/

#include<iostream>
#include<algorithm>
#include<vector>	
#include<string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, cntr = 0, cntb = 0, res = 0;
	string instr = "";
	string rb = "";

	cin >> N;
	cin >> instr;

	// bbrbrrb -> brbrb
	for (int i = 0; i < instr.length() - 1; i++) {
		if (instr[i] != instr[i + 1]) {
			rb += instr[i];
		}
	}
	rb += instr[instr.length() - 1];

	// count num of color
	for (int i = 0; i < rb.length(); i++) {
		if (rb[i] == 'R') cntr++;
		else cntb++;
	}

	int max = cntb < cntr ? cntb : cntr;
	res = max + 1;
	cout << res;

	return 0;
}