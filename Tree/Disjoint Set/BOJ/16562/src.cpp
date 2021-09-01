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
vector<int> cost;

int find(int v) {
	if (v == par[v])
		return v;

	return par[v] = find(par[v]);
}

void merge(int u, int v){
	u = find(u);
	v = find(v);

	if (cost[u] < cost[v])
		swap(u, v);

	par[u] = v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, k;
	cin >> N >> M >> k;

	par.resize(N + 1);
	cost.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int c;
		cin >> c;
		cost[i] = c;
		par[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}

	int ans = 0;
	vector<bool> isVisited(N + 1);

	for (int i = 1; i <= N; i++) {
		int cur = find(i);
		if (isVisited[cur])
			continue;

		isVisited[cur] = true;
		ans += cost[cur];
	}

	if (ans > k)
		cout << "Oh no";
	else
		cout << ans;

	return 0;
}