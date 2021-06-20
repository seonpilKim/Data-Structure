#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <limits.h>
#include <numeric>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	while (N--) {
		int M, find;
		cin >> M >> find;
		queue<pair<int, int>> q;
		priority_queue<int, vector<int>, less<int>> pq;

		for (int i = 0; i < M; i++) {
			int n;
			cin >> n;
			pq.push(n);
			q.emplace(n, i);
		}

		int cnt = 1;
		while (true) {
			if (q.front().first == pq.top()) {
				if (q.front().second == find) {
					cout << cnt << '\n';
					break;
				}
				pq.pop();
				cnt++;
			}
			q.push(q.front()); q.pop();
		}
	}

	return 0;
}