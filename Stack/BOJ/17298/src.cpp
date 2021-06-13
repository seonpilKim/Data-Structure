#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M;
	cin >> M;

	stack<pair<int, int>> s;
	vector<int> ans(M, -1);

	int n;
	for (int i = 0; i < M; i++) {
		cin >> n;
		
		while (!s.empty() && n > s.top().first) {
			if (ans[s.top().second] == -1)
				ans[s.top().second] = n;
			s.pop();
		}
		s.emplace(n, i);
	}

	for (int a : ans)
		cout << a << ' ';

	return 0;
}
