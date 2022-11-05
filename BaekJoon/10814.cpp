#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(pair<int, string> x, pair<int, string> y) {
	return x.first < y.first;	// 오름차순 정렬
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, string>> person;

	for (int i = 0; i < N; i++) {
		string name;
		int age;
		cin >> age >> name;

		person.push_back(make_pair(age, name));
	}

	stable_sort(person.begin(), person.end(), compare);
	// 하나의 요소로 정렬할 때, pair가 같이 움직이는 것

	for (int i = 0; i < N; i++) {
		cout << person[i].first << " " << person[i].second << "\n";
	}

	return 0; 
}