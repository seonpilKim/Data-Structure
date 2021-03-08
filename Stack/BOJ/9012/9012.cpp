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
		string PS;
		bool flag = false;

		cin >> PS;

		for (char PC : PS) {
			if (PC == '(') s.push(PC);
			else if (PC == ')') {
				if (s.empty()) {
					flag = true;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty() || flag) {
			while (!s.empty()) {
				s.pop();
			}
			cout << "NO\n";
		}
		else cout << "YES\n";
	}

	return 0;
}