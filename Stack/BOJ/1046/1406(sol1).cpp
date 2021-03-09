#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<char> left, right;

	string input;

	cin >> input;

	for (char c : input) {
		left.push(c);
	}

	int T;

	cin >> T;

	while (T--) {
		char cmd;
		cin >> cmd;

		if (cmd == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (cmd == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (cmd == 'B') {
			if (!left.empty())
				left.pop();
		}
		else if (cmd == 'P') {
			char add;
			cin >> add;
			left.push(add);
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

	return 0;
}