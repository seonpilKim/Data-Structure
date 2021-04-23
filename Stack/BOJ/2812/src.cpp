#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int K, N;
	string number, answer;
	stack<char> s;

	cin >> N >> K;
	cin >> number;
	
	for (int i = 0; i < N; i++) {
		while (K > 0 && !s.empty() && s.top() < number[i]) {
			s.pop();
			K--;
		}
		s.push(number[i]);
	}

	while (K > 0 && !s.empty()) {
		s.pop();
		K--;
	}

	while (!s.empty()) {
		answer.push_back(s.top());
		s.pop();
	}

	reverse(answer.begin(), answer.end());

	cout << answer;

	return 0;
}