#include<iostream>
#include<stack>
#include<map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// vars
	int N ; 
	string s;
	stack<double> st; 
	map<char, double> m;

	// input
	cin >> N >> s;

	for (char c : s) {
		if ('A' <= c && c <= 'Z') {
			if (m.find(c) == m.end()) {
				int tmp; cin >> tmp;
				m[c] = tmp;
			}
			if (m.size() == N) break;
		}
	}

	// num mapping »Æ¿Œ
	//for (auto a : m) cout << a.first << " : " << a.second << "\n";

	// solution
	for (char c : s) {
		double f_pop, s_pop;

		if (c == '*') {
			s_pop = st.top();
			st.pop();
			f_pop = st.top();
			st.pop();
			st.push(f_pop * s_pop);
		}
		else if (c == '+') {
			s_pop = st.top();
			st.pop();
			f_pop = st.top();
			st.pop();
			st.push(f_pop + s_pop);
		}
		else if (c == '-') {
			s_pop = st.top();
			st.pop();
			f_pop = st.top();
			st.pop();
			st.push(f_pop - s_pop);
		}
		else if (c == '/') {
			s_pop = st.top();
			st.pop();
			f_pop = st.top();
			st.pop();
			st.push(f_pop / s_pop);
		}
		else {
			st.push(m[c]);
		}
	}
	 
	cout << fixed;
	cout.precision(2);
	cout << st.top();

	return 0;
}