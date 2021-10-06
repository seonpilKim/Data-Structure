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

vector<int> par(1e5 + 1);
vector<long long> dist(1e5 + 1);

int find(int u) {
	if (u == par[u])
		return u;

	int root = find(par[u]);
	dist[u] += dist[par[u]];
	return par[u] = root;
}

void merge(int u, int v, int d){
	int par_u = find(u);
	int par_v = find(v);

	if (par_u == par_v)
		return;

	par[par_v] = par_u;
	dist[par_v] = dist[u] - dist[v] + d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		int N, M;
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;

		for (int i = 1; i <= N; i++) {
			par[i] = i;
			dist[i] = 0;
		}

		for (int m = 0; m < M; m++) {
			char cmd;
			cin >> cmd;

			if (cmd == '!') {
				int u, v, w;
				cin >> u >> v >> w;
				merge(v, u, w);
			}
			else if (cmd == '?') {
				int u, v;
				cin >> u >> v;
				if (find(u) != find(v))
					cout << "UNKNOWN\n";
				else
					cout << dist[u] - dist[v] << '\n';
			}
		}
	}

	return 0;
}