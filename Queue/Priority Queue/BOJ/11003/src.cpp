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
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dh[] = {1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, L;
	cin >> N >> L;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	vector<int> ans(N);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < L; i++) {
		pq.emplace(v[i], i);
		ans[i] = min(pq.top().first, v[i]);
	}

	for (int i = L; i < N; i++) {
		pq.emplace(v[i], i);
		while (pq.top().second <= i - L)
			pq.pop();
		ans[i] = pq.top().first;
	}

	for (auto answer : ans)
		cout << answer << ' ';

	return 0;
} 