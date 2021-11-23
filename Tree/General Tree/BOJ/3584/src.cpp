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
#include <cctype>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dh[] = {1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> par(N + 1);
		for (int i = 1; i <= N; i++)
			par[i] = i;
		for (int i = 1; i < N; i++) {
			int u, v;
			cin >> u >> v;
			par[v] = u;
		}

		int u, v;
		cin >> u >> v;
		vector<bool> isVisited(N + 1);
		while (u != par[u]) {
			isVisited[u] = true;
			u = par[u];
		}
		while (true) {
			if (isVisited[v]) {
				cout << v << '\n';
				break;
			}
			isVisited[v] = true;
			v = par[v];
		}
	}

	return 0;
}