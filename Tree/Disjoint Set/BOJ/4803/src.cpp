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

	int _case = 1;

	while (true) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		par.resize(n + 1);
		_rank.assign(n + 1, 1);
		isCycle.assign(n + 1, false);

		for (int i = 1; i <= n; i++)
			par[i] = i;

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;

			merge(u, v);
		}

		int cnt = 0;
		vector<bool> isVisited(n + 1);

		for (int i = 1; i <= n; i++) {
			int target = find(i);
			if (isVisited[target] || isCycle[target])
				continue;

			cnt++;
			isVisited[target] = true;
		}

		switch (cnt) {
			case 0:
				cout << "Case " << _case << ": No trees.\n";
				break;
			case 1:
				cout << "Case " << _case << ": There is one tree.\n";
				break;
			default:
				cout << "Case " << _case << ": A forest of " << cnt << " trees.\n";
				break;
		}

		_case++;
	}

	return 0;
}