#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	queue<int> q, ans;
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	
	while (!q.empty()) {
		for (int i = 1; i < K; i++) {
			q.push(q.front()); q.pop();
		}
		ans.push(q.front()); q.pop();
	}

	cout << "<";
	while (!ans.empty()) {
		if (ans.size() == 1) {
			cout << ans.front();
			ans.pop();
		}
		else {
			cout << ans.front() << ", ";
			ans.pop();
		}
	}
	cout << ">";

	return 0;
}