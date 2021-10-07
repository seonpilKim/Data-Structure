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

	par[v] = u;
	ans--;

	if (_rank[u] == _rank[v])
		_rank[u]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	par.resize(N * M);
	_rank.assign(N * M, 1);
	for (int i = 0; i < N * M; i++)
		par[i] = i;

	ans = N * M;
	vector<string> dir(N);
	for (int i = 0; i < N; i++)
		cin >> dir[i];
	for (int i = 0; i < N * M; i++) {
		int cur = i;
		int next;
		char direction = dir[i / M][i % M];
		if (direction == 'D')
			next = cur + M;
		else if (direction == 'L')
			next = cur - 1;
		else if (direction == 'R')
			next = cur + 1;
		else if (direction == 'U')
			next = cur - M;
		merge(cur, next);
	}

	cout << ans;

	return 0;
}