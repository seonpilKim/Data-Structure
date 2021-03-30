#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, tower;
	stack<pair<int, int>> s, tmp;

	cin >> N;
	vector<int> answer(N);

	for (int i = 1; i <= N; i++) {
		cin >> tower;
		s.push(make_pair(i, tower));
	}

	while (true) {
		pair<int, int> top = s.top();
		s.pop();

		if (s.empty()) {
			answer[0] = 0;
			break;
		}
		
		if (s.top().second >= top.second) {
			answer[top.first - 1] = s.top().first;
			while (!tmp.empty() && s.top().second >= tmp.top().second) {
				answer[tmp.top().first - 1] = s.top().first;
				tmp.pop();
			}
		}
		else 
			tmp.push(top);	
	}

	for (int ans : answer) {
		cout << ans << ' ';
	}

	return 0;
}