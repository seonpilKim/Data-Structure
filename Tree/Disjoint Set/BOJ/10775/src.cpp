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

int find(int v) {
	if (v == par[v])
		return v;

	return par[v] = find(par[v]);
}

void merge(int u, int v){
	u = find(u);
	v = find(v);
	par[u] = v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int G, P;
	cin >> G >> P;

	vector<int> g(P + 1);
	par.resize(G + 1);

	for (int i = 1; i <= P; i++)
		cin >> g[i];
	for (int i = 1; i <= G; i++) 
		par[i] = i;

	int ans = 0;
	for (int i = 1; i <= P; i++) {
		int target = find(g[i]);
		if (target == 0)
			break;

		merge(target, target - 1);
		ans++;
	}

	cout << ans;

	return 0;
}