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

const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> adj(N + 1);
	long long int D = 0, G = 0;

	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		long long int _size = adj[i].size();

		for (int j = 0; j < _size; j++)
			D += (_size - 1) * (adj[adj[i][j]].size() - 1);

		G += _size * (_size - 1) * (_size - 2) / 6;
	}
	D /= 2;

	if (D > 3 * G)
		cout << 'D';
	else if (D < 3 * G)
		cout << 'G';
	else
		cout << "DUDUDUNGA";

	return 0;
}