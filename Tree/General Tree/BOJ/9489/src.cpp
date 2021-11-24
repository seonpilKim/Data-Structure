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
	
	int n, k;
	while (true) {
		cin >> n >> k;
		if (n == 0 && k == 0) 
			break;

		vector<int> nodes(n + 1), par(n + 1);
		nodes[0] = par[0] = -1;
		
		int cnt = -1, idx = 0;
		for (int i = 1; i <= n; i++) {
			cin >> nodes[i];

			if (nodes[i] == k)
				idx = i;
			if (nodes[i] != nodes[i - 1] + 1)
				cnt++;
			par[i] = cnt;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (par[i] != par[idx] && par[par[i]] == par[par[idx]])
				ans++;
		cout << ans << '\n';
	}

	return 0;
}