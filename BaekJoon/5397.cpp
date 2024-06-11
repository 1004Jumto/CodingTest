#include<iostream>
#include<list>
#include<string> 
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// vars
	int N;
	string pw;
	list<char> l;
	list<char>::iterator cursor = l.begin();

	// input
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> pw;

		// init
		l.clear();
		cursor = l.begin();

		// solution
		for (char c : pw) {
			switch (c) {
			case '<': {
				if (cursor != l.begin()) cursor--;
				break;
			}
			case '>': {
				if (cursor != l.end()) cursor++;
				break;
			}
			case '-': {
				if (cursor != l.begin()) { 
					cursor = l.erase(--cursor); 
				}
				break;
			}
			default: {
				cursor = l.insert(cursor, c);
				cursor++;
				break;
			}
			}
		}
 
		
		// print
		for (auto c : l) cout << c;
		cout << "\n";

	}


	return 0;
}
