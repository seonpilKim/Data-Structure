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

void preorder(const vector<int>& postorder, const vector<int>& inorder, const vector<int>& inroot,
	int start, int end, int post_root) {
	if (start >= end)
		return;

	int in_root = inroot[postorder[post_root]];

	cout << inorder[in_root] << ' ';
	preorder(postorder, inorder, inroot, start, in_root, post_root - end + in_root);
	preorder(postorder, inorder, inroot, in_root + 1, end, post_root - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> inorder(N), postorder(N), inroot(N + 1);
	for (int i = 0; i < N; i++)
		cin >> inorder[i];
	for (int i = 0; i < N; i++)
		cin >> postorder[i];
	for (int i = 0; i < N; i++)
		inroot[inorder[i]] = i;

	preorder(postorder, inorder, inroot, 0, N, N - 1);

	return 0;
}