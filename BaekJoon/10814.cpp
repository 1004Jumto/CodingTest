#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(pair<int, string> x, pair<int, string> y) {
	return x.first < y.first;	// �������� ����
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
	// �ϳ��� ��ҷ� ������ ��, pair�� ���� �����̴� ��

	for (int i = 0; i < N; i++) {
		cout << person[i].first << " " << person[i].second << "\n";
	}

	return 0; 
}