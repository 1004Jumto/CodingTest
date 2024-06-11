#include<iostream> 
#include<stack>

using namespace std;

bool isVPS(string str);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// vars 
	int T;
	string str;

	// input 
	cin >> T;
	
	// print 
	for (int i = 0; i < T; i++) {
		cin >> str;
		if (isVPS(str)) cout << "YES";
		else cout << "NO";
		cout << "\n";
	}

	return 0;
}

bool isVPS(string str) {
	stack<char> s;
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') s.push('(');
		else if (str[i] == ')' && s.empty()) return false;
		else s.pop();
	}
	
	if (s.empty()) return true;
	
	return false;
}