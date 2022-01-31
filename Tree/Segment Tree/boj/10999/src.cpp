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

typedef vector<vector<long long>> matrix;
matrix operator*(const matrix& A, const matrix& B) {
    int n = A.size(), m = B[0].size(), w = A[0].size();
    matrix res(n, vector<long long>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < w; k++)
                res[i][j] += A[i][k] * B[k][j];

    return res;
}

long long init(const vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = a[start];
    return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

void update_lazy(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right, long long diff) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start)
        return;
    if (left <= start && right >= end) {
        tree[node] += (end - start + 1) * diff;
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }

    update_range(tree, lazy, node * 2, start, (start + end) / 2, left, right, diff);
    update_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start)
        return 0;
    if (left <= start && right >= end)
        return tree[node];
    return sum(tree, lazy, node * 2, start, (start + end) / 2, left, right) + sum(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int h = ceil(log2(n));
    vector<long long> tree(1 << (h + 1)), lazy(1 << (h + 1));
    init(a, tree, 1, 0, n - 1);

    for (int i = 0; i < m + k; i++) {
        int u, v, w; long long x;
        cin >> u >> v >> w;
        if (u == 1) {
            cin >> x;
            update_range(tree, lazy, 1, 0, n - 1, v - 1, w - 1, x);
        }
        else if (u == 2)
            cout << sum(tree, lazy, 1, 0, n - 1, v - 1, w - 1) << '\n';
    }

    return 0;
}