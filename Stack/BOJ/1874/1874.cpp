#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	stack<int> s;
	vector<char> ans;
	vector<int> v;

	int n;
	int find = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 1; i <= n; i++) {
		s.push(i);
		ans.push_back('+');

		while (!s.empty() && s.top() == v[find]) {
			s.pop();
			ans.push_back('-');
			find++;
		}
	}

	if (!s.empty()) cout << "NO";
	else {
		for (char a : ans) {
			cout << a << '\n';
		}
	}

	return 0;
}