#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> s;

	int T;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	while (T--) {
		string cmd;

		cin >> cmd;

		if (cmd == "push") {
			int data;

			cin >> data;
			s.push(data);
		}
		else if (cmd == "pop") {
			if (s.empty()) cout << "-1\n";
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (cmd == "size") {
			cout << s.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << s.empty() << '\n';
		}
		else if (cmd == "top") {
			if (s.empty()) cout << "-1\n";
			else cout << s.top() << '\n';
		}
	}

	return 0;
}