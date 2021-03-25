#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;

	while (T--) {
		string str;
		stack<char> left, right;
		cin >> str;

		for (char c : str) {
			if (c == '<') {
				if (!left.empty()) {
					right.push(left.top());
					left.pop();
				}
			}
			else if (c == '>') {
				if (!right.empty()) {
					left.push(right.top());
					right.pop();
				}
			}
			else if (c == '-') {
				if (!left.empty())
					left.pop();
			}
			else 
				left.push(c);
		}

		while (!left.empty()) {
			right.push(left.top());
			left.pop();
		}

		while (!right.empty()) {
			cout << right.top();
			right.pop();
		}
		cout << '\n';
	}
	
	return 0;
}