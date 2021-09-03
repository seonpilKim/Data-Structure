#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include <math.h>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>
#include <bitset>

using namespace std;

#define NONE -1
#define MAX 1e3 + 1
#define MOD (int)(1e4 + 7);

const int dr[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dc[] = {-1, 0, 1, 0, -1, 1, -1, 1};

vector<int> par;
vector<int> _rank;
vector<bool> isCycle;

int find(int v) {
	if (v == par[v])
		return v;

	return par[v] = find(par[v]);
}

void merge(int u, int v){
	u = find(u);
	v = find(v);

	if (u == v) {
		isCycle[u] = true;
		return;
	}

	if (isCycle[u] || isCycle[v]) {
		isCycle[u] = true;
		isCycle[v] = true;
	}

	if (_rank[u] < _rank[v])
		swap(u, v);

	par[v] = u;
	if (_rank[u] == _rank[v])
		_rank[u]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	par.resize(n + 1);
	_rank.assign(n + 1, 1);
	isCycle.assign(n + 1, false);

	for (int i = 1; i <= n; i++)
		par[i] = i;

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;

		if (ans != 0)
			continue;

		merge(u, v);

		if (isCycle[find(u)]) 
			ans = i;
	}

	cout << ans;

	return 0;
}