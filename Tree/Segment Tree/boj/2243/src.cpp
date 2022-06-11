#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <list>
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

const int dr[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dc[] = {0, -1, 0, 1, 1, -1, 1, -1};

typedef vector<vector<long long>> matrix;
matrix operator*(matrix A, matrix B) {
    matrix res = {{0, 0}, {0, 0}};
    int n = A.size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                res[i][j] += A[i][k] * B[k][j];

    return res;
}

const int MAX = 1000000;

void update(vector<int>& tree, int node, int start, int end, int index, int diff) {
    if (index < start || index > end) {
        return;
    }

    tree[node] += diff;
    if (start != end) {
        const int left = node * 2;
        const int right = left + 1;
        const int mid = (start + end) / 2;

        update(tree, left, start, mid, index, diff);
        update(tree, right, mid + 1, end, index, diff);
    }
}

int find(const vector<int>& tree, int node, int start, int end, int target) {
    if (start == end) {
        return start;
    }

    const int left = node * 2;
    const int right = left + 1;
    const int mid = (start + end) / 2;
    
    if (tree[left] >= target) {
        return find(tree, left, start, mid, target);
    }
    else {
        return find(tree, right, mid + 1, end, target - tree[left]);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> values(MAX);
    int h = ceil(log2(MAX));
    vector<int> tree(1 << (h + 1));

    while (n--) {
        int A, B, C, candy;
        cin >> A;
        
        if (A == 1) {
            cin >> B;
            C = -1;
            candy = find(tree, 1, 0, MAX - 1, B);
            cout << candy + 1 << '\n';
        }
        else {
            cin >> B >> C;
            candy = B - 1;
        }

        values[candy] += C;
        update(tree, 1, 0, MAX - 1, candy, C);
    }

	return 0;
}