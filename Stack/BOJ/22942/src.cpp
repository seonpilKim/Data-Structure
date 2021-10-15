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
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dh[] = {1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<pair<int, int>> circle(N);
	for (int i = 0; i < N; i++) {
		int x, r;
		cin >> x >> r;
		circle[i] = {x - r, x + r};
	}
	sort(circle.begin(), circle.end());

	bool flag = true;
	auto prev = circle.front();
	for (int i = 1; i < N; i++) {
		auto cur = circle[i];
		if (prev.second >= cur.first && prev.second <= cur.second) {
			flag = false;
			break;
		}
		prev = cur;
	}

	cout << (flag ? "YES" : "NO");

	return 0;
} 