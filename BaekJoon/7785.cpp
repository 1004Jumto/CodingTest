#include<iostream>
#include<set>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// vars
	int N;
	set<string> s;
	string name, log;

	// input
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> name >> log;
		if (log == "enter") {
			s.insert(name);
		}
		else s.erase(name);
	}

	// print
	for (auto itr = s.rbegin(); itr != s.rend(); itr++) cout << *itr << "\n";

	return 0;
}