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

int N;
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
	
	N--;
	par[v] = u;
	if (_rank[u] == _rank[v])
		_rank[u]++;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	N = n;
	par.resize(n + 1);
	_rank.assign(n + 1, 1);
	for (int i = 1; i <= n; i++) 
		par[i] = i;

	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
	for (int i = 1; i <= n; i++)
		dp[i][1] = dp[i][i] = 1;

	for (int i = 2; i <= n; i++) 
		for (int j = 2; j < i; j++) 
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % MOD;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		merge(u, v);

		long long ans = 0;
		for (int i = 1; i <= N; i++)
			ans += dp[N][i];
	
		cout << ans % MOD << '\n';
	}

	return 0;
}