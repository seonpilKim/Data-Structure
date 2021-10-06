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
const long long INF = 9e9;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int ans;
vector<int> par, _rank;

int find(int u) {
	if (u == par[u])
		return u;

	return par[u] = find(par[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v)
		return;

	if (_rank[u] < _rank[v])
		swap(u, v);

	ans--;
	par[v] = u;

	if (_rank[u] == _rank[v])
		_rank[u]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	ans = N;
	par.resize(N + 1);
	for (int i = 1; i <= N; i++)
		par[i] = i;
	_rank.assign(N + 1, 1);

	int M;
	cin >> M;
	vector<pair<int, int>> pos(M);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		pos[i] = {u, v};
	}

	if (M) {
		sort(pos.begin(), pos.end());
		auto cur = pos.front();

		for (int i = 0; i < M; i++) {
			if (pos[i].first <= cur.second) 
				cur.second = max(cur.second, pos[i].second);
			else {
				for (int j = cur.first; j < cur.second; j++)
					merge(j, j + 1);
				cur = pos[i];
			}
		}
		for (int j = cur.first; j < cur.second; j++)
			merge(j, j + 1);
	}

	cout << ans;

	return 0;
}