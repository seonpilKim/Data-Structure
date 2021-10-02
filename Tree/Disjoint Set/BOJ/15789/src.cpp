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

vector<int> par, _rank, _size;

int find(int node) {
	if (node == par[node])
		return node;

	return par[node] = find(par[node]);
}

void merge(int node1, int node2) {
	node1 = find(node1);
	node2 = find(node2);

	if (node1 == node2)
		return;

	if (_rank[node1] > _rank[node2])
		swap(node1, node2);
	par[node1] = node2;
	_size[node2] += _size[node1];

	if (_rank[node1] == _rank[node2])
		++_rank[node2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	par.resize(N + 1);
	_rank.assign(N + 1, 1);
	_size.assign(N + 1, 1);

	for (int i = 1; i <= N; i++)
		par[i] = i;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		merge(u, v);
	}

	int C, H, K;
	cin >> C >> H >> K;

	int par_H = find(H);
	int par_C = find(C);

	vector<int> otherKingdom;
	vector<bool> isVisited(N + 1);
	for (int i = 1; i <= N; i++) {
		int par_i = find(i);

		if (par_i == par_H || par_i == par_C)
			continue;
		if (isVisited[par_i])
			continue;

		otherKingdom.push_back(_size[par_i]);
		isVisited[par_i] = true;
	}
	sort(otherKingdom.begin(), otherKingdom.end(), greater<int>());

	int answer = _size[par_C];
	for (int i = 0; i < K; i++)
		answer += otherKingdom[i];

	cout << answer;

	return 0;
}