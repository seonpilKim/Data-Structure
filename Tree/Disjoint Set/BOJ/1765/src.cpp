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

const long long MOD = 1e9;
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

	int n;
	cin >> n;
	ans = n;
	par.resize(n + 1);
	_rank.assign(n + 1, 1);
	for (int i = 1; i <= n; i++) 
		par[i] = i;

	int m;
	cin >> m;
	vector<vector<int>> enemy(n + 1);
	for (int i = 0; i < m; i++) {
		char type;
		int u, v;
		cin >> type >> u >> v;

		if (type == 'F')
			merge(u, v);
		else if (type == 'E') {
			enemy[u].push_back(v);
			enemy[v].push_back(u);

			for (int fr : enemy[u])
				merge(v, fr);
			for (int fr : enemy[v])
				merge(u, fr);
		}
	}

	cout << ans;

	return 0;
}